/*
Button.cpp
CS-Paint
*/

#include "Button.hpp"

#include <string>
using std::string;



Button::Button(float width, float length, float xPos, float yPos, const string &imagePathNotPressed, const string &imagePathPressed, _ButtonType type) 
	: _size{ width, length }, _position{ xPos, yPos }, _imagePathNotPressed{ imagePathNotPressed }, _imagePathPressed{ imagePathPressed }, _type{ type }
{
	if (!_texture.loadFromFile(_imagePathNotPressed)) //set initial button state to not pressed
	{
		// error...
	}
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setOrigin(0, 0);
	_sprite.setPosition(xPos, yPos);

}

Button::Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &imagePathPressed, _ButtonType type,const std::string &text)
	: _size{ width, length }, _position{ xPos, yPos }, _imagePathNotPressed{ imagePathNotPressed }, _imagePathPressed{ imagePathPressed }, _type{ type }
{
	if (!_texture.loadFromFile(_imagePathNotPressed)) //set initial button state to not pressed
	{
		// error...
	}
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setPosition(xPos, yPos);
	_text.setPosition(_position.x + (0.4 * _size.x), _position.y + (0.09 * _size.y));
	_font.loadFromFile("assets/DejaVuSans.ttf");
	_text.setFont(_font);
	_text.setFillColor(sf::Color::Black);
	_text.setString(text);

}

Button::Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &imagePathPressed, _ButtonType type, const std::string &text,const sf::Font &font)
	: _size{ width, length }, _position{ xPos, yPos }, _imagePathNotPressed{ imagePathNotPressed }, _imagePathPressed{ imagePathPressed }, _type{ type }, _font{ font }
{

	if (!_texture.loadFromFile(_imagePathNotPressed)){ //set initial button state to not pressed
		// error...
	}
	_sprite.setPosition(xPos, yPos);
	_text.setPosition(_position.x, _position.y);
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_text.setFont(font);
	_text.setFillColor(sf::Color::Black);
	_text.setString(text);

}

Button::Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &imagePathPressed, _ButtonType type, const std::string &text, sf::Font font, sf::Color textColor)
	: _size{ width, length }, _position{ xPos, yPos }, _imagePathNotPressed{ imagePathNotPressed }, _imagePathPressed{ imagePathPressed }, _type{ type }, _font{ font }
{
	if (!_texture.loadFromFile(_imagePathNotPressed)) //set initial button state to not pressed
	{
		// error...
	}
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setPosition(xPos, yPos);
	_text.setFont(_font);
	_text.setFillColor(textColor);
	_text.setString(text);
}

sf::Vector2i Button::getPosition(){
	return _position;
}

sf::Vector2f Button::getSize(){
	return _size;
}

bool Button::isPressed(const sf::RenderWindow &window)
{
	if (_text.getString() == ""){
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			(sf::Mouse::getPosition().x > window.getPosition().x + _position.x + 17 && sf::Mouse::getPosition().x < 17 + _position.x + window.getPosition().x + _size.x) &&
			(sf::Mouse::getPosition().y > window.getPosition().y + _position.y + 70 && sf::Mouse::getPosition().y < 72 + _position.y + window.getPosition().y + _size.y)){
			_isPressed = true;
			return true;
		}
		else{
			_isPressed = false;
			return false;
		}
	}
	else /*if (_text.getString() != "")*/{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			(sf::Mouse::getPosition().x > window.getPosition().x + _position.x  && sf::Mouse::getPosition().x < 17 + _position.x + window.getPosition().x + (int)_size.y) &&
			(sf::Mouse::getPosition().y > window.getPosition().y + _position.y + 70 && sf::Mouse::getPosition().y < 72 + _position.y + window.getPosition().y + (int)_size.x)){
			_isPressed = true;
			return true;
		}
		else{
			_isPressed = false;
			return false;
		}
	}
}


void Button::setTexture(bool isPressed){
	
	if (isPressed){
		_isPressed = true;
		_texture.loadFromFile(_imagePathPressed);
		{
			// error...
		}
	}
	else{
		_isPressed = false;
		_texture.loadFromFile(_imagePathNotPressed);
		{
			// error...
		}
	}
	
}

void Button::draw(sf::RenderWindow &window) {
	window.draw(_sprite);
	window.draw(_text);
}

