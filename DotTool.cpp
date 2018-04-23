/*
	.cpp file for Dots class.
*/
#include "DotTool.hpp"
#include <iostream>
#include <memory>
using std::unique_ptr;
using std::make_unique;
void DotTool::paintTick(Frame& f, sf::Color c, sf::Event& e) {
	// Because Frames add Drawables to the _objects variable, for polymorphism to
	// take effect the circle must be passed as a pointer. circle must be assigned to
	// a 'new' CircleShape, otherwise circle is deleted when program leaves scope and
	// _objects has a pointer pointing to a deleted variable.
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		sf::CircleShape* circle = new sf::CircleShape(_dotRadius);
		sf::Vector2i position = sf::Mouse::getPosition(this->getWindow());
		circle->setPosition(position.x-_dotRadius, position.y-_dotRadius);
		circle->setFillColor(c);
		f.addObject(*circle);
		// _sfxCounter prevents sound effect from replaying instantly after starting
		//this->playSound();     //////////////////////////   ///////////temp turn off link errors
	}
}
void DotTool::scrollAction(sf::Event& e){
	if(e.mouseWheelScroll.delta < 0 && _dotRadius < 50){
		_dotRadius += 5;
	}
	else if(e.mouseWheelScroll.delta > 0 && _dotRadius > 5){
		_dotRadius -= 5;
	}
}
DotTool::DotTool(sf::RenderWindow& f): Tool(f){
	this->getIcon().loadFromFile("assets/brushcursor.png");
	//this->initializeSound("assets/drawEffect.wav");             ///////////////temp turning off link error
}
