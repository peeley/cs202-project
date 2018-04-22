#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
using std::vector;
#include <queue>
#include <iostream>
using std::cout;
using std::endl;
using std::queue;
#include "Application.hpp"
#include "DotTool.hpp"
#include "EraserTool.hpp"
#include "Button.hpp"
#include "TabMenu.hpp"
#include "Color.hpp"
#include "SquareTool.hpp"
using std::string;

int main() {
	int width = 1080;
	int height = 720;
	int volume = 20;
	sf::RenderWindow window(sf::VideoMode(width, height), "CSPaint");
	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(120);
	Application app(window);
	DotTool dot(app.getWindow());
	EraserTool eraser(app.getWindow());
	SquareTool square(app.getWindow());
	app.setTool(&square);
	sf::Color color = sf::Color::Red;

	//cursor
	window.setMouseCursorVisible(false);
    sf::Sprite cursorSprite(app.getTool()->getIcon());

	//music
	sf::Music music;
	music.openFromFile("assets/soundtrack.wav");
	music.setLoop(true);
	music.setVolume(volume);
	music.play();

	/*
	//////////make tab buttons////////////
	vector<Button> tabs;
	Button button1( 68, 30 ,  0, 0 , false,  "tab_not_pressed.png", "tab_pressed.png", "tab_hover.png", Button::OFF_BY_CLICK_ANOTHER, " File");
	Button button2( 68, 30 ,  68, 0 , true, "tab_not_pressed.png", "tab_pressed.png", "tab_hover.png", Button::OFF_BY_CLICK_ANOTHER, "Home");
	Button button3( 68, 30 ,  136, 0 , false, "tab_not_pressed.png", "tab_pressed.png", "tab_hover.png", Button::OFF_BY_CLICK_ANOTHER, "View");
	Button button4( 68, 30 ,  204, 0 , false, "tab_not_pressed.png", "tab_pressed.png", "tab_hover.png", Button::OFF_BY_CLICK_ANOTHER, "Tools");
	button2.setState(Button::PRESSED);
	tabs.push_back(button1);
	tabs.push_back(button2);
	tabs.push_back(button3);
	tabs.push_back(button4);
	
	////// file menu buttons////
	vector<Button> buttons;
	Button fileMenuBut1( 68, 30 ,  0, 35 , false,  "button_not_pressed1.png", "button_pressed.png", "button_hover.png", Button::AUTO_TOGGLE, "New");
	Button fileMenuBut2( 68, 30 ,  0, 70 , false, "button_not_pressed1.png", "button_pressed.png", "button_hover.png", Button::AUTO_TOGGLE, "Open");
	Button fileMenuBut3( 68, 30 ,  0, 105 , false, "button_not_pressed1.png", "button_pressed.png", "button_hover.png", Button::AUTO_TOGGLE, "Save");
	Button fileMenuBut4( 68, 30 ,  0, 140 , false, "button_not_pressed1.png", "button_pressed.png", "button_hover.png", Button::AUTO_TOGGLE, "Save As");
	Button fileMenuBut5( 68, 30 ,  0, 175 , false, "button_not_pressed1.png", "button_pressed.png", "button_hover.png", Button::AUTO_TOGGLE, "About CS-Paint");
	Button fileMenuBut6( 68, 30 ,  0, 210 , false, "button_not_pressed1.png", "button_pressed.png", "button_hover.png", Button::AUTO_TOGGLE, "Exit");
		buttons.push_back(fileMenuBut1);
		buttons.push_back(fileMenuBut2);
		buttons.push_back(fileMenuBut3);
		buttons.push_back(fileMenuBut4);
		buttons.push_back(fileMenuBut5);
		buttons.push_back(fileMenuBut6);
		
	// color selector
	vector<Button> colorButton;
	Button colorSelector(850, 0, "assets/colorselector.png");
		colorButton.push_back(colorSelector);
		
	//////make menus////
		TabMenu tabMenu({ 0,0 }, tabs, "tabHeaderBackgroundImage.png");
		TabMenu fileMenu({ 0,0 }, buttons, "tabMenuBackgroundImage.png");
		TabMenu colorMenu({850, 0}, colorButton, "colorselector.png"); // color selector
*/
	while (window.isOpen()) {
		window.clear(sf::Color::White);
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				app.close();
			}
			Color::colorSelectorButton(window, app); // color selector
			if (event.type == sf::Event::MouseButtonPressed || 
				event.type == sf::Event::MouseButtonReleased ||
				event.type == sf::Event::MouseMoved) {
				app.getTool()->paintTick(app.getCurrentFrame(), color, event);
			}
			if (event.type == sf::Event::MouseWheelScrolled) {
				app.getTool()->scrollAction(event);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				eraser.paintTick(app.getCurrentFrame(), sf::Color::White, event);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				app.clearCurrentFrame();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
				app.createNewFrame();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				app.cycleLastFrame();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				app.cycleNextFrame();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
				sf::Image screenshot;
				app.drawCurrentFrame();
				screenshot = window.capture();
				screenshot.saveToFile("screenshot.jpg");
			}
		}
		
		app.drawCurrentFrame();
		
		//cursor
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		int mouseX = mousePosition.x;
		int mouseY = mousePosition.y;
		if((mouseX > 270 && mouseX < 1080) && (mouseY > 0 && mouseY < 720)){
			window.setMouseCursorVisible(false);
			cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		}else{
			window.setMouseCursorVisible(true);
		}
				
/*
		//////draw menus//////
		fileMenu.draw(window);
		tabMenu.draw(window);
		colorMenu.draw(window); // color selector
		
		///////update button textures//////////
		//tab buttons//
		button1.setTexture(button1.getButtonState(window, { 273, 30 }, { 0,0 }));
		button2.setTexture(button2.getButtonState(window, { 273, 30 }, { 0,0 }));
		button3.setTexture(button3.getButtonState(window, { 273, 30 }, { 0,0 }));
		button4.setTexture(button4.getButtonState(window, { 273, 30 }, { 0,0 }));
		
		//file menu buttons//
		fileMenuBut1.setTexture(fileMenuBut1.getButtonState(window, { 273, 30 }, { 0,0 })); 
		fileMenuBut2.setTexture(fileMenuBut2.getButtonState(window, { 273, 30 }, { 0,0 }));
		fileMenuBut3.setTexture(fileMenuBut3.getButtonState(window, { 273, 30 }, { 0,0 }));
		fileMenuBut4.setTexture(fileMenuBut4.getButtonState(window, { 273, 30 }, { 0,0 }));
		fileMenuBut5.setTexture(fileMenuBut5.getButtonState(window, { 273, 30 }, { 0,0 }));
		fileMenuBut6.setTexture(fileMenuBut6.getButtonState(window, { 273, 30 }, { 0,0 }));
*/		
		window.draw(cursorSprite); //for cursor
		app.display();
	}
}


