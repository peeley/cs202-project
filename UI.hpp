/*
Alex Lewandowski
CS-Paint
UI.hpp
*/

#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "TabMenu.hpp"
#include "Application.hpp"
#include <string>
#include <vector>
#include <memory>




#ifndef FILE_UI_HPP
#define FILE_UI_CPP

class UI {
public:
	//UI();
	UI(Application &app, sf::RenderWindow &window, Tool &dot, Tool &eraser, Tool &square, Tool &pencil, Tool &line);
	std::vector<TabMenu> getMenus();

	//void makeButtons(Application &app, sf::RenderWindow &window);  //put in constructor

	void callFunction(std::function< void() > f);
	
	
	void buttonAction();

	void draw(sf::RenderWindow &window);

	void setButTexture(sf::RenderWindow &window);

	void loadTab(sf::RenderWindow &window, Application &app);

	void loadMenuTexture(sf::Vector2f &position, const std::string &imageFilePath, sf::RenderWindow &window);

	

private:
	
	std::vector<TabMenu> _menus;    //////////
	std::vector<std::shared_ptr<Button>> _tabs;
	std::vector<std::shared_ptr<Button>> _fileButtons;
	std::vector<std::shared_ptr<Button>> _colorButtons;
	std::vector<std::shared_ptr<Button>> _toolButtons;
	sf::Sprite _sprite;
	sf::Texture _texture;
	std::vector<sf::Vector2i> _menuSizes;
	std::vector<sf::Vector2i> _menuPosition;

};

#endif // !FILE_UI_HPP
