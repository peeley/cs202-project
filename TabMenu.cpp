/*
TabMenu.cpp
CS-Paint
*/
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "TabMenu.hpp"
#include <string>
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;


TabMenu::TabMenu(const sf::Vector2i &position,vector<shared_ptr<Button>> &buttons/*, const std::string &backgroundImagePath*/): _position{ position }, _buttons{ buttons } {
	//_backgroundTexture.loadFromFile(backgroundImagePath);
	//_backgroundTexture.setSmooth(true);
	//_backgroundSprite.setTexture(_backgroundTexture);
	//_backgroundSprite.setOrigin(0, 0);
	//_backgroundSprite.setPosition({ 0,30 }/*(sf::Vector2f)position*/);
	
}

void TabMenu::draw(sf::RenderWindow &window) {
	//window.draw(_backgroundSprite);
	for (auto button = 0; button < _buttons.size(); ++button) {
		_buttons[button]->drawButton(window);
	}
}
 
int TabMenu::getMenuSize() {
	return _buttons.size();
}

void TabMenu::setButtonTextures() {
	for (auto button = 0; button < _buttons.size(); ++button) {
		_buttons[button]->setTexture(_buttons[button]->getState());
	}
}

//void TabMenu::getButtons(vector<shared_ptr<Button>>) {
//	
//	
//	//return _buttons;
//}
