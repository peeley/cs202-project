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

	Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &imagePathPressed, _ButtonType type);
	Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &inmagePathPressed, _ButtonType type,const std::string &text);
	Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &inmagePathPressed, _ButtonType type, const std::string &text,const sf::Font &font);
	Button(float length, float width, float xPos, float yPos, const std::string &imagePathNotPressed, const std::string &inmagePathPressed, _ButtonType type,const std::string &text, sf::Font font, sf::Color textColor);
	
	void draw(sf::RenderWindow &window);
	
	//getters
	sf::Vector2i getPosition();
	sf::Vector2f getSize();
	//sf::Vector2f getSpritePosition();
	bool isPressed(const sf::RenderWindow &window);

	//setters
	//void press(bool pressed);
	void setTexture(bool isPressed);
	
	

	

private:
	sf::Vector2f _size;
	sf::Vector2i _position;
	std::string _imagePathNotPressed;
	std::string _imagePathPressed;
	sf::RectangleShape _rectangle;
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Text _text;
	sf::Font _font;	
	bool _isPressed;
	bool _autoToggle;  //true if button returns to unpressed when mouse button released. False if button must be clicked a s
	_ButtonType _type;



};
#endif // !FILE_BUTTON_HPP
