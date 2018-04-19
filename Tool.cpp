/*
	.cpp file for Tool class.
*/
#include "Tool.hpp"
#include <iostream>
using std::string;

Tool::Tool(sf::RenderWindow& w, string& s):_window{w}{
	std::cout << "loading brush icon" << std::endl;
	_mouseIcon.loadFromFile(s);
}
Tool::Tool(sf::RenderWindow& w): _window{w}{}

Tool::~Tool(){
	std::cout << "Destroying tool" << std::endl;
}

sf::RenderWindow& Tool::getWindow() const{
	return _window;
}

sf::Texture& Tool::getIcon() {
	return _mouseIcon;
}
