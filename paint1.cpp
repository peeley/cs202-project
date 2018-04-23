#include <SFML/Graphics.hpp>
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
#include "UI.hpp"
using std::string;
#include<memory>
using std::shared_ptr;
using std::make_shared;

int main() {
	int width = 1080;
	int height = 720;
	sf::RenderWindow window(sf::VideoMode(width, height), "CSPaint");
	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(120);
	Application app(window);
	string brushIconFilepath = "assets/brushcursor.png";
	DotTool dot(app.getWindow(), brushIconFilepath);
	EraserTool eraser(app.getWindow());
	app.setTool(&dot);

	//vector<Tool> tools{ dot, eraser };

	//cursor
	window.setMouseCursorVisible(false);
	sf::Sprite cursorSprite(dot.getIcon());

	//make UI//
	UI ui(app, window, dot, eraser);
	


	while (window.isOpen()) {
		window.clear(sf::Color::White);
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				app.close();
			}
			Color::colorSelectorButton(window, app); // color selector
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				app.getTool()->paintTick(app.getCurrentFrame(), app.getColor());
			}
			if (event.type == sf::Event::MouseWheelScrolled) {
				app.getTool()->scrollAction(event);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				eraser.paintTick(app.getCurrentFrame(), sf::Color::White);
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
		}

		//cursor
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		int mouseX = mousePosition.x;
		int mouseY = mousePosition.y;
		if ((mouseX > 270 && mouseX < 1080) && (mouseY > 0 && mouseY < 720)) {
			window.setMouseCursorVisible(false);
			cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		}
		else {
			window.setMouseCursorVisible(true);
		}

		app.drawCurrentFrame();

		//UI events
		ui.loadTab(window, app);
		ui.draw(window);
		ui.setButTexture(window);
		ui.buttonAction();
		


		window.draw(cursorSprite); //for cursor
		app.display();
	}
}


