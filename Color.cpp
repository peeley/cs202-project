// color.cpp
// changes color of whichever tool is drawing in the window

#include <SFML\Graphics.hpp>
#include "Color.hpp"

void Color::colorSelectorButton(const sf::RenderWindow &window, Application &app){
	sf::Color color(0, 0, 0);
	sf::Vector2i mouse = sf::Mouse::getPosition(window);
	sf::Vector2f mouse_world = window.mapPixelToCoords(mouse);
	if((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (mouse_world.y >= 19 && mouse_world.y <= 23)){
		if(mouse_world.x >= 855 && mouse_world.x <= 871){
			app.setColor(sf::Color::Black);
		}if(mouse_world.x >= 877 && mouse_world.x <= 893){
			sf::Color grey(102, 102, 102);
			app.setColor(grey);
		}if(mouse_world.x >= 899 && mouse_world.x <= 915){
			sf::Color darkRed(153, 0, 0);
			app.setColor(darkRed);
		}if(mouse_world.x >= 921 && mouse_world.x <= 937){
			sf::Color lightRed(225, 51, 51);
			app.setColor(lightRed);
		}if(mouse_world.x >= 943 && mouse_world.x <= 959){
			sf::Color orange(225, 102, 51);
			app.setColor(orange);
		}if(mouse_world.x >= 965 && mouse_world.x <= 981){
			sf::Color yellow(225, 255, 0);
			app.setColor(yellow);
		}if(mouse_world.x >= 987 && mouse_world.x <= 1003){
			sf::Color green(51, 153, 51);
			app.setColor(green);
		}if(mouse_world.x >= 1009 && mouse_world.x <= 1025){
			sf::Color lightBlue(0, 153, 255);
			app.setColor(lightBlue);
		}if(mouse_world.x >= 1031 && mouse_world.x <= 1047){
			sf::Color blue(51, 51, 204);
			app.setColor(blue);
		}if(mouse_world.x >= 1053 && mouse_world.x <= 1069){
			sf::Color purple(153, 51, 153);
			app.setColor(purple);
		}
	}
}
	
	// this produced same results as above
	
	//if(
	//	(sf::Mouse::isButtonPressed(sf::Mouse::Left)) &&
	//	(mouse_world.y >= 20 && mouse_world.y <= 22) &&
	//	(mouse_world.x >= 855 && mouse_world.x <= 871) &&
	//	(sf::Mouse::isButtonReleased(sf::Mouse::Left))
	//	){
	//		app.setColor(sf::Color::Black);
	//	}
	//else if(
	//	(sf::Mouse::isButtonPressed(sf::Mouse::Left)) &&
	//	(mouse_world.y >= 20 && mouse_world.y <= 22) &&
	//	(mouse_world.x >= 897 && mouse_world.x <= 913)
	//	(sf::Mouse::isButtonReleased(sf::Mouse::Left))
	//	){
	//		app.setColor(sf::Color::Red);
	//	}
	
	// this did not work at all
	
//	sf::Event event;
//	if(event.type == sf::Event::MouseButtonPressed){
//    	if(event.mouseButton.button == sf::Mouse::Left){
//    		if((mouse_world.y >= 20 && mouse_world.y <= 22)){
//    			if(mouse_world.x >= 855 && mouse_world.x <= 871){
//    				app.setColor(sf::Color::Black);
//    			}if(mouse_world.x >= 897 && mouse_world.x <= 913){
//					app.setColor(sf::Color::Red);
//				}
//			}
//		}
//	}
//}



