#include <SFML/Graphics.hpp>
#include <vector>
using std::vector;
void paint(vector<sf::CircleShape>& circles, sf::RenderWindow& window){
	for(int i = 0; i < circles.size(); i++){
		window.draw(circles[i]);
	}
}

int main(){
	sf::RenderWindow window(sf::VideoMode(1080, 720), "CSPaint");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(120);
	sf::Font font;
	window.clear(sf::Color::White);
	vector<sf::CircleShape> art;

	while(window.isOpen()){
		window.clear(sf::Color::White);
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				window.close();
			}
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				sf::CircleShape circle(5);
				sf::Vector2i position = sf::Mouse::getPosition(window);
				circle.setPosition(position.x, position.y);
				circle.setFillColor(sf::Color::Black);
				art.push_back(circle);	
			}
			if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
				sf::CircleShape circle(10);
				sf::Vector2i position = sf::Mouse::getPosition(window);
				circle.setPosition(position.x, position.y);
				circle.setFillColor(sf::Color::White);
				art.push_back(circle);	
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
				art.clear();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
				if(art.size() > 0){
					art.pop_back();
				}
			}
		}
		paint(art, window);
		window.display();
	}
}
