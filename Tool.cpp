/*
	.cpp file for Tool class.
*/
#include "Tool.hpp"
#include <iostream>
Tool::Tool(sf::RenderWindow& w): _window{w}{}

Tool::~Tool(){
	std::cout << "Destroying tool" << std::endl;
}

sf::RenderWindow& Tool::getWindow() const{
	return _window;
}
