/*
	.cpp file for Eraser tool.
*/
#include "EraserTool.hpp"
#include <iostream>
void EraserTool::paintTick(Frame& f, sf::Color c, sf::Event& e) {
	sf::CircleShape* circle;
	circle = new sf::CircleShape(10);
	sf::Vector2i position = sf::Mouse::getPosition(this->getWindow());
	circle->setPosition(position.x-10, position.y-10);
	circle->setFillColor(c);
	f.addObject(*circle);
	this->playSound();
}
void EraserTool::scrollAction(sf::Event& e){}
EraserTool::EraserTool(sf::RenderWindow& w): Tool(w){
	this->initializeSound("assets/eraserEffect.wav");
}
