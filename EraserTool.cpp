/*
	.cpp file for Eraser tool.
*/
#include "EraserTool.hpp"
#include <iostream>

void EraserTool::paintTick(Frame& f, sf::Color c, sf::Event& e) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		sf::CircleShape* circle;
		circle = new sf::CircleShape(_dotRadius);
		sf::Vector2i position = sf::Mouse::getPosition(this->getWindow());
		circle->setPosition(position.x - _dotRadius, position.y - _dotRadius);
		circle->setFillColor(sf::Color::White);
		f.addObject(*circle);
		this->playSound();            
	}
}
void EraserTool::scrollAction(sf::Event& e){
	if(e.mouseWheelScroll.delta < 0 && _dotRadius < 50){
		_dotRadius += 5;
	}
	else if(e.mouseWheelScroll.delta > 0 && _dotRadius > 5){
		_dotRadius -= 5;
	}
}
EraserTool::EraserTool(sf::RenderWindow& w): Tool(w){
	this->initializeSound("assets/eraserEffect.wav");
	this->getIcon().loadFromFile("assets/eraserIcon.png");
}

