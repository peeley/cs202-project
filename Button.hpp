/*
Button.hpp
CS-Paint
*/
#include <SFML\Graphics.hpp>
#include <string>

#ifndef FILE_BUTTON_HPP
#define FILE_BUTTON_HPP


class Button 
{
public:
	enum _ButtonType { AUTO_TOGGLE, CLICK_ON_CLICK_OFF, OFF_BY_CLICK_ANOTHER };

	//constructor with no text//
	Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &imagePathPressed, _ButtonType type);
	
	//constructor with text, but no font or font color (defaults to DejaVuSans and black)//
	Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &inmagePathPressed, _ButtonType type,const std::string &text);
	
	//constructor with text and font but no font color (defaults to black)//
	Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &inmagePathPressed, _ButtonType type, const std::string &text,const sf::Font &font);
	
	//constructor with text, font, and font color//
	Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &inmagePathPressed, _ButtonType type,const std::string &text, sf::Font font, sf::Color textColor);
	
	//draws button to window//
	void draw(sf::RenderWindow &window);
	
	//getters
	sf::Vector2i getPosition();
	sf::Vector2f getSize();
	
	//returns true if button is pressed, false if it's not.//  
	bool isPressed(const sf::RenderWindow &window);

	//sets button texture based on pressed/not pressed status//
	void setTexture(bool isPressed);

private:
	sf::Vector2f _size;
	sf::Vector2i _position;
	std::string _imagePathNotPressed;
	std::string _imagePathPressed;
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Text _text;
	sf::Font _font;	
	_ButtonType _type;
};
#endif // !FILE_BUTTON_HPP
