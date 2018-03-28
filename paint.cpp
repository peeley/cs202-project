#include <SFML/Graphics.hpp>
int main(){
	sf::RenderWindow window(sf::VideoMode(720, 480), "CSPaint");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	sf::Font font;
	font.loadFromFile("assets/DejaVuSans.ttf");
	sf::Text text("Welcome to CSPaint!", font, 30);
	int count = 0;

	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
		}
		if(count % 20 ==0){
			text.setFillColor(sf::Color::Blue);
			text.setCharacterSize(50);
		}
		else{
			text.setFillColor(sf::Color::Red);
			text.setCharacterSize(30);
		}
		window.clear(sf::Color::Yellow);
		window.draw(text);
		window.display();
		++ count;
	}
}
