/*
Button.cpp
CS-Paint
*/

#include "Button.hpp"
#include <string>
using std::string;
#include <SFML/System/Clock.hpp>


//constructor with no text//
Button::Button(float width, float length, float xPos, float yPos, const string &imagePathNotPressed, const string &imagePathPressed, const std::string &imagePathHover, _ButtonType type)
	: _size{ width, length }, _position{ xPos, yPos }, _imagePathNotPressed{ imagePathNotPressed }, _imagePathPressed{ imagePathPressed }, _imagePathHover{ imagePathHover }, _type{ type }
{
	if (!_texture.loadFromFile(_imagePathNotPressed)) //set initial button state to not pressed
	{
		// error...
	}
	_pressed = false;
	_state = NOT_PRESSED;
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setOrigin(0, 0);
	_sprite.setPosition(xPos, yPos);

}

//constructor with text, but not font or font color.//
Button::Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &imagePathPressed, const std::string &imagePathHover, _ButtonType type, const std::string &text)
	: _size{ width, length }, _position{ xPos, yPos }, _imagePathNotPressed{ imagePathNotPressed }, _imagePathPressed{ imagePathPressed }, _imagePathHover{ imagePathHover }, _type{ type }
{
	if (!_texture.loadFromFile(_imagePathNotPressed)) //set initial button state to not pressed
	{
		// error...
	}
	_pressed = false;
	_state = NOT_PRESSED;
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
Button::Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &imagePathPressed, const std::string &imagePathHover, _ButtonType type, const std::string &text, const sf::Font &font)
	: _size{ width, length }, _position{ xPos, yPos }, _imagePathNotPressed{ imagePathNotPressed }, _imagePathPressed{ imagePathPressed }, _imagePathHover{ imagePathHover }, _type{ type }, _font{ font }
{

	if (!_texture.loadFromFile(_imagePathNotPressed)) { //set initial button state to not pressed
		// error...
	}
	_pressed = false;
	_state = NOT_PRESSED;
	_sprite.setPosition(xPos, yPos);
	_text.setPosition(_position.x, _position.y);
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_text.setFont(font);
	_text.setFillColor(sf::Color::Black);
	_text.setString(text);

}

//constructor with text, font, and font color//
Button::Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &imagePathPressed, const std::string &imagePathHover, _ButtonType type, const std::string &text, sf::Font font, sf::Color textColor)
	: _size{ width, length }, _position{ xPos, yPos }, _imagePathNotPressed{ imagePathNotPressed }, _imagePathPressed{ imagePathPressed }, _imagePathHover{ imagePathHover }, _type {
	type
}, _font{ font }
{
	if (!_texture.loadFromFile(_imagePathNotPressed)) //set initial button state to not pressed
	{
		// error...
	}
	_pressed = false;
	_state = NOT_PRESSED;
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setPosition(xPos, yPos);
	_text.setFont(_font);
	_text.setFillColor(textColor);
	_text.setString(text);
}

//delay time... some buttons are a little too responsive. 
void delayTime(sf::Clock clock, float seconds) {
	sf::Time elapsed = clock.getElapsedTime();
	sf::Time delay = sf::seconds(seconds);
	while (elapsed < delay)
	{
		elapsed = clock.getElapsedTime();
	}
}

//////getters//////
sf::Vector2i Button::getPosition() {
	return _position;
}

sf::Vector2f Button::getSize() {
	return _size;
}

//returns true if button is pressed, false if it's not.//  
Button::_ButtonState Button::getButtonState(const sf::RenderWindow &window) {
	sf::Vector2f mousePointRelativeToWorld;
	//Get the mouse position:
	sf::Vector2i mouse = sf::Mouse::getPosition(window);
	//Map Pixel to Coords:
	sf::Vector2f mouse_world = window.mapPixelToCoords(mouse);

	if (_type == CLICK_ON_CLICK_OFF) {
		sf::Clock clock;
		if (_text.getString() == "") {
			if (_state == PRESSED  && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.x) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.y)) {
				_pressed = false;
				_state = NOT_PRESSED;
			}
			else if (_state == (HOVER || NOT_PRESSED)  && !_pressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.x) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.y)) {
				_pressed = true;
				_state = PRESSED;
				delayTime(clock, 0.1);
			}
			else if (_state == NOT_PRESSED && !_pressed && !sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.x) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.y)) {
				_state = HOVER;
				delayTime(clock, 0.1);
			}
			else if (_state == HOVER && !_pressed &&
				(!(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.x) ||
				!(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.y))){
				_state = NOT_PRESSED;
				delayTime(clock, 0.1);
			}
		}
		
		else { //if there is text
			if (_state == PRESSED && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x)) {
				_pressed = false;
				_state = NOT_PRESSED;
			}
			else if (_state == (HOVER || NOT_PRESSED) && !_pressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x)) {
				_pressed = true;
				_state = PRESSED;
				delayTime(clock, 0.1);
			}
			else if (_state == NOT_PRESSED && !_pressed && !sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x)) {
				_state = HOVER;
				delayTime(clock, 0.1);
			}
			else if (_state == HOVER && !_pressed &&
				(!(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) ||
					!(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x))) {
				_state = NOT_PRESSED;
				delayTime(clock, 0.1);
			}
			
		}
		return _state;
	}

	if (_type == AUTO_TOGGLE) {
		if (_text.getString() == "") {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.x) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.y)) {
				return PRESSED;
			}
			if (_state == NOT_PRESSED && !sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.x) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.y)) {
				return HOVER;
			}
			else {
				return NOT_PRESSED;
			}
		}
		else {//if there is text
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x)) {
				return PRESSED;
			}
			if (_state == NOT_PRESSED && !sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x)) {
				return HOVER;
			}
			else {
				return NOT_PRESSED;
			}
		}
	}
}

//sets button texture based on pressed/not pressed status//
void Button::setTexture(Button::_ButtonState state) {

	if (state == PRESSED) {
		_texture.loadFromFile(_imagePathPressed);
		{
			// catch error...
		}
	}
	if (state == NOT_PRESSED) {
		_texture.loadFromFile(_imagePathNotPressed);
		{
			//catch error...
		}
	}
	if (state == HOVER) {
		_texture.loadFromFile(_imagePathHover);
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

