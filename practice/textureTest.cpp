#include <SFML/Graphics.hpp>
int main(){
	sf::Texture texture;
	texture.loadFromFile("assets/brush-icon.png");
	sf::RenderWindow window(sf::VideoMode(1080,720), "Texture Test");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	while(true){
		window.clear(sf::Color::White);
		window.draw(sprite);
		window.display();
	}
}
