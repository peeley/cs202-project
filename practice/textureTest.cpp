#include <SFML/Graphics.hpp>

int main(){
	sf::Texture texture;
	texture.loadFromFile("assets/brush-icon.png");
	// just wanted to see if a jpg works too
	//texture.loadFromFile("assets/pencil-icon.jpg");
	sf::RenderWindow window(sf::VideoMode(500,500), "Texture Test");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	//while(true){
	
	// for closing the window
	while(window.isOpen()){	
		sf::Event event;
    	while (window.pollEvent(event)){
        	if(event.type == sf::Event::Closed)
                window.close();
    	}
    	
		window.clear(sf::Color::White);
		window.draw(sprite);
		window.display();
	}
}
