/*
Button.cpp
CS-Paint
*/

#include "Button.hpp"
#include <string>
using std::string;


//constructor with no text//
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

//constructor with text, but not font or font color.//
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

//constructor with text and font but no font color//
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

//constructor with text, font, and font color//
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

//////getters//////
sf::Vector2i Button::getPosition(){
	return _position;
}

sf::Vector2f Button::getSize(){
	return _size;
}

//returns true if button is pressed, false if it's not.//  
bool Button::isPressed(const sf::RenderWindow &window)
{
	sf::Vector2f mousePointRelativeToWorld;
	//Get the mouse position:
	sf::Vector2i mouse = sf::Mouse::getPosition(window);
	//Map Pixel to Coords:
	sf::Vector2f mouse_world = window.mapPixelToCoords(mouse);
	
	if (_text.getString() == "") {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.x) &&
			(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.y)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) &&
			(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x)) {
			return true;
		}
		else {
			return false;
		}
	}
}

//sets button texture based on pressed/not pressed status//
void Button::setTexture(bool isPressed){
	
	if (isPressed){
		_texture.loadFromFile(_imagePathPressed);
		{
			// catch error...
		}
	}
	else{
		_texture.loadFromFile(_imagePathNotPressed);
		{
			//catch error...
		}
	}
	
}

//draws button to window//
void Button::draw(sf::RenderWindow &window) {
	window.draw(_sprite);
	window.draw(_text);
}

