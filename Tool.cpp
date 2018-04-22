/*
	.cpp file for Tool class.
*/
#include "Tool.hpp"
#include <iostream>
using std::string;

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
sf::Sound& Tool::getSoundEffect(){
	return _sfx;
}
void Tool::initializeSound(string s){
	_sfxBuffer.loadFromFile(s);
	_sfx.setBuffer(_sfxBuffer);	
}
