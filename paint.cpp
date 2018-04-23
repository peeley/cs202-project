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
#include "UI.hpp"
#include "Button.hpp"
#include "TabMenu.hpp"
#include "Color.hpp"
#include "SquareTool.hpp"
#include "PencilTool.hpp"
using std::string;

int main() {
	int width = 1080;
	int height = 720;
	int volume = 20;
	sf::RenderWindow window(sf::VideoMode(width, height), "CSPaint");
	window.setVerticalSyncEnabled(true);
	Application app(window, width, height);
	DotTool	   dot(app.getWindow());
	EraserTool eraser(app.getWindow());
	SquareTool square(app.getWindow());
	PencilTool pencil(app.getWindow());
	app.setTool(&pencil);
	sf::Color color = sf::Color::Red;

	//cursor
	window.setMouseCursorVisible(false);
    sf::Sprite cursorSprite(app.getTool()->getIcon());

	//make UI//
	UI ui(app, window, dot, eraser, square, pencil);

	////music
	//sf::Music music;
	//music.openFromFile("assets/soundtrack.wav"); ////////////////////////////temp turn off due to link errors
	//music.setLoop(true);
	//music.setVolume(volume);
	//music.play();

	while (window.isOpen()) {
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
				app.getTool()->paintTick(*app.getCurrentFrame(), app.getColor(), event);
			}
			if (event.type == sf::Event::MouseWheelScrolled) {
				app.getTool()->scrollAction(event);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				eraser.paintTick(*app.getCurrentFrame(), sf::Color::White, event);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				app.clearCurrentFrame();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
				app.createNewFrame(width, height);
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
				//screenshot = window.capture();//////////////////////////////////////////error says sf::RenderWindow::capture was declared deprecated, won't compile.
				screenshot.saveToFile("screenshot.jpg");
			}
		}	
		window.clear(sf::Color::White);
		app.drawCurrentFrame();

		//cursor
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		int mouseX = mousePosition.x;
		int mouseY = mousePosition.y;
		if((mouseX > 270 && mouseX < 1080) && (mouseY > 0 && mouseY < 720)){
			window.setMouseCursorVisible(false);
			cursorSprite.setPosition(mouseX, mouseY-23);
		}else{
			window.setMouseCursorVisible(true);
		}
				
		//UI events
		ui.loadTab(window, app);
		ui.draw(window);
		ui.setButTexture(window);
		ui.buttonAction();

		window.draw(cursorSprite); //for cursor
		app.display();
	}
}
