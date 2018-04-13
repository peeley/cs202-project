/*
	.cpp file for Dots class.
*/
#include "DotTool.hpp"
#include <iostream>
void DotTool::paintTick(Frame& f, sf::Color c) const {
	// Because Frames add Drawables to the _objects variable, for polymorphism to
	// take effect the circle must be passed as a pointer. circle must be assigned to
	// a 'new' CircleShape, otherwise circle is deleted when program leaves scope and
	// _objects has a pointer pointing to a deleted variable.
	sf::CircleShape* circle;
	circle = new sf::CircleShape(_dotRadius);
	sf::Vector2i position = sf::Mouse::getPosition(this->getWindow());
	circle->setPosition(position.x-_dotRadius, position.y-_dotRadius);
	circle->setFillColor(c);
	f.addObject(*circle);
	std::cout << "Dot added at (" << position.x <<","<< position.y << ")" << std::endl;
}
void DotTool::scrollAction(sf::Event& e){
	if(e.mouseWheelScroll.delta < 0 && _dotRadius < 50){
		_dotRadius += 5;
		std::cout << "Dot size increased to: " << _dotRadius << " px." << std::endl;
	}
	else if(e.mouseWheelScroll.delta > 0 && _dotRadius > 5){
		_dotRadius -= 5;
		std::cout << "Dot size decreased to: " << _dotRadius << " px." << std::endl;
	}
}
