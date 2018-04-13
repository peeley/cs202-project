#include <SFML/Graphics.hpp>
#include <vector>
#include "Application.hpp"
#include "DotTool.hpp"

using std::vector;

int main(){
	sf::RenderWindow window(sf::VideoMode(1080, 720), "CSPaint");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(120);
	Application app(window);
	DotTool dot(app.getWindow());
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
			if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
				sf::CircleShape circle(10);
				sf::Vector2i position = sf::Mouse::getPosition(app.getWindow());
				circle.setPosition(position.x, position.y);
				circle.setFillColor(sf::Color::White);
				app.addToFrame(circle);	
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
				app.clearCurrentFrame();
			}
		}
		app.drawCurrentFrame();
		app.display();
	}
}
