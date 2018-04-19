
// Color.hpp

#include <SFML\Graphics.hpp>
#include "Application.hpp"

#ifndef FILE_COLORSELECTOR_HPP
#define FILE_COLORSELECTOR_HPP

class Color : public Application{
public:
	//using Application::Application;
	//Color();
	static void colorSelectorButton(const sf::RenderWindow &window, Application &app);
	//static sf::Color _selectedColor;
};

#endif
