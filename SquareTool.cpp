#include "SquareTool.hpp"
#include <iostream>
using std::cout;
using std::endl;
void SquareTool::paintTick(Frame& f, sf::Color c, sf::Event& e){
	if(e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left){
		_startPos = sf::Vector2i(sf::Mouse::getPosition(this->getWindow()));
		_mouseDown = true;
	}
	else if(e.type == sf::Event::MouseMoved && _mouseDown){
		//this->playSound();////////////////////////////////////   ///////////temp turn off link errors
	}
	else if(e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left){
		sf::Vector2i endPos = sf::Mouse::getPosition(this->getWindow());
		int xDist = endPos.x - _startPos.x;
		int yDist = endPos.y - _startPos.y;
		sf::Vector2f size(xDist, yDist);
		_square = new sf::RectangleShape(size);
		_square->setOutlineColor(c);
		_square->setFillColor(c);
		_square->setPosition(sf::Vector2f(_startPos));
		_square->setOutlineThickness(_outlineThickness);
		f.addObject(*_square);
		_mouseDown = false;
	}
}
void SquareTool::scrollAction(sf::Event& e){
	if(e.mouseWheelScroll.delta < 0 && _outlineThickness < 50){
		_outlineThickness += 5;
	}
	if(e.mouseWheelScroll.delta > 0 && _outlineThickness > 5){
		_outlineThickness -= 5;
	}
}

SquareTool::SquareTool(sf::RenderWindow& w): Tool(w){
	this->getIcon().loadFromFile("assets/squareCursor.png");
	//this->initializeSound("assets/stretchEffect.wav");        ///////////temp turn off link errors
}
