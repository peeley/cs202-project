#include <SFML/Graphics.hpp>
#include <vector>
#include "Application.hpp"
#include "DotTool.hpp"
#include "EraserTool.hpp"

using std::vector;

int main(){
	sf::RenderWindow window(sf::VideoMode(1080, 720), "CSPaint");
	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(120);
	Application app(window);
	DotTool dot(app.getWindow());
	EraserTool eraser(app.getWindow());
	app.setTool(&dot);
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
		app.display();
	}
}
