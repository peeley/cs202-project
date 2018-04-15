#include <SFML/Graphics.hpp>
#include <vector>
#include "Application.hpp"
#include "DotTool.hpp"
#include "EraserTool.hpp"
#include "Button.hpp"

using std::vector;

int main(){
	sf::RenderWindow window(sf::VideoMode(1080, 720), "CSPaint");
	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(120);
	Application app(window);
	DotTool dot(app.getWindow());
	EraserTool eraser(app.getWindow());
	app.setTool(&dot);


	//////////make a button////////////
	vector<Button> buttons;
	Button button(136, 60, 0, 0, "button_not_pressed1.png", "button_pressed.png", Button::AUTO_TOGGLE, "File");
	Button button2(136, 60, 150, 0, "button_not_pressed1.png", "button_pressed.png", Button::AUTO_TOGGLE, "Home");
	Button button3(136, 60, 300, 0, "button_not_pressed1.png", "button_pressed.png", Button::AUTO_TOGGLE, "View");
	buttons.push_back(button);
	buttons.push_back(button2);
	buttons.push_back(button3);


	while(window.isOpen()){
		window.clear(sf::Color::White);
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				app.close();
			}
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				app.getTool()->paintTick(app.getCurrentFrame(), app.getColor());
			}
			if(event.type == sf::Event::MouseWheelScrolled){
				app.getTool()->scrollAction(event);
			}
			if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
				eraser.paintTick(app.getCurrentFrame(), sf::Color::White);	
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
				app.clearCurrentFrame();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
				app.createNewFrame();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				app.cycleLastFrame();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				app.cycleNextFrame();
			}
		}
		app.drawCurrentFrame();

		button.setTexture(button.isPressed(window));
		button.draw(window);
		button2.setTexture(button2.isPressed(window));
		button2.draw(window);
		button3.setTexture(button3.isPressed(window));
		button3.draw(window);

		app.display();
	}
}
