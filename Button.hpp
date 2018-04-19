/*
Button.hpp
CS-Paint
*/
#include <SFML\Graphics.hpp>
#include <string>
#include<queue>

#ifndef FILE_BUTTON_HPP
#define FILE_BUTTON_HPP

//time delay function//
void delayTime(sf::Clock clock, float seconds);


class Button
{
public:
	enum _ButtonType { AUTO_TOGGLE, CLICK_ON_CLICK_OFF, OFF_BY_CLICK_ANOTHER };
	enum _ButtonState { PRESSED, HOVER, NOT_PRESSED };

	//constructor with no text//
	Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &imagePathPressed, const std::string &imagePathHover, _ButtonType type);

	//constructor with text, but no font or font color (defaults to DejaVuSans and black)//
	Button(float length, float width, float xPos, float yPos, bool pressed, const std::string &imagePathNotPressed, const std::string &inmagePathPressed, const std::string &imagePathHover, _ButtonType type, const std::string &text);

	//constructor with text and font but no font color (defaults to black)//
	Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &inmagePathPressed, const std::string &imagePathHover, _ButtonType type, const std::string &text, const sf::Font &font);

	//constructor with text, font, and font color//
	Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &inmagePathPressed, const std::string &imagePathHover, _ButtonType type, const std::string &text, sf::Font font, sf::Color textColor);

	//draws button to window//
	void draw(sf::RenderWindow &window);

	//getters
	sf::Vector2i getPosition();
	sf::Vector2f getSize();
	sf::Text getText();
	_ButtonState getState();
	bool getPressed();

	//returns button state (PRESSED, HOVER, NOT_PRESSED)//  
	_ButtonState getButtonState(const sf::RenderWindow &window, sf::Vector2i _menuSize, sf::Vector2i _menuPosition);


	//setters
	void setState(_ButtonState state);
	void setPosition(sf::Vector2i position);
	void setPressed(bool pressed);

	//sets button texture based on pressed/not pressed status//
	void setTexture(_ButtonState state);

	//color selector button
	Button(float xPos, float yPos, const std::string &imagePathNotPressed);	

private:
	sf::Vector2f _size;
	sf::Vector2i _position;
	std::string _imagePathNotPressed;
	std::string _imagePathPressed;
	std::string _imagePathHover;
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Text _text;
	sf::Font _font;
	_ButtonType _type;
	_ButtonState _state;
	bool _pressed;
	int currentButtonPressed; //only used for OFF_BY_CLICK_ANOTHER buttons //maybe delete
	
};




#endif // !FILE_BUTTON_HPP
