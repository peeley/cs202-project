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
	circle = new sf::CircleShape(5);
	sf::Vector2i position = sf::Mouse::getPosition(this->getWindow());
	circle->setPosition(position.x, position.y);
	circle->setFillColor(c);
	f.addObject(*circle);
	std::cout << "Dot added at (" << position.x <<","<< position.y << ")" << std::endl;
}
