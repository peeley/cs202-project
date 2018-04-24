/*
TabMenu.hpp
CS-Paint
*/
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include <string>
#include <vector>
#include <memory>


#ifndef FILE_TABMENU_HPP
#define FILE_TABMENU_HPP

class TabMenu {
public:
	std::vector<std::shared_ptr<Button>> _buttons;

	TabMenu(const sf::Vector2i &position, std::vector<std::shared_ptr<Button>> &buttons/*, const std::string &backgroundImagePath*/);
	//TabMenu(const sf::Vector2i &size, const sf::Vector2i &position, const std::vector<Button> &buttons, const sf::Color &backgroundColor);
	//TabMenu(const sf::Vector2i &size, const sf::Vector2i &position, const std::vector<Button> &buttons, const sf::Color &backgroundColor, const std::string &backgroundImagePath);

	//draw
	void draw(sf::RenderWindow &window);

	//getters
	sf::Vector2i getSize();
	sf::Vector2i getPosition();
	sf::Color getColor();
	std::string getBackgroundImagePath();
	int getMenuSize();
	//std::vector<shared_ptr<Button>> getButtons();
	//void getButtons(vector<shared_ptr<Button>>);

	//setters
	void setButtonTextures();

private:
	sf::Vector2i _position;
	//sf::Color _backgroundColor;
	//std::string _backgroundImagePath;
	//std::vector<std::shared_ptr<Button>> _buttons;
	//sf::Texture _backgroundTexture;
	//sf::Sprite _backgroundSprite;

};

#endif /*FILE_TABMENU_HPP*/
