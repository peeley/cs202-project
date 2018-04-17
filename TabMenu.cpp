/*
TabMenu.cpp
CS-Paint
*/
#include <SFML\Graphics.hpp>
#include "Button.hpp"
#include "TabMenu.hpp"
#include <string>
#include <vector>
using std::vector;


TabMenu::TabMenu(const sf::Vector2i &position, const std::vector<Button> &buttons, const std::string &backgroundImagePath)
	: _position{ position }, _buttons{ buttons } {
	_backgroundTexture.loadFromFile(backgroundImagePath);
	_backgroundTexture.setSmooth(true);
	_backgroundSprite.setTexture(_backgroundTexture);
	_backgroundSprite.setOrigin(0, 0);
	_backgroundSprite.setPosition((sf::Vector2f)position);
	
}

void TabMenu::draw(sf::RenderWindow &window) {
	window.draw(_backgroundSprite);
	for (auto a : _buttons) {
		a.draw(window);
	}
}
 

void TabMenu::setButtonTextures() {
	for (auto a : _buttons) {
		a.setTexture(a.getState());
	}
}