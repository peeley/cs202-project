/*
	.cpp file for Eraser tool.
*/
#include "EraserTool.hpp"
#include <iostream>
void EraserTool::paintTick(Frame& f, sf::Color c) const{
	sf::CircleShape* circle;
	circle = new sf::CircleShape(10);
	sf::Vector2i position = sf::Mouse::getPosition(this->getWindow());
	circle->setPosition(position.x, position.y);
	circle->setFillColor(c);
	f.addObject(*circle);
	std::cout << "Erasing ("<<position.x<<","<<position.y<<")"<<std::endl;
}
void EraserTool::scrollAction(sf::Event& e){}
