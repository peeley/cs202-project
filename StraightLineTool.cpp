#include "StraightLineTool.hpp"

void StraightLineTool::paintTick(Frame& f, sf::Color c, sf::Event& e){
	if(e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left){
		_mouseDown = true;
		_line = new sf::VertexArray(sf::LinesStrip);
		sf::Vector2f vertexPos = sf::Vector2f(sf::Mouse::getPosition(this->getWindow()));
		_line->append(sf::Vertex(vertexPos,c));
	}
	else if(e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left){
		sf::Vector2f vertexPos = sf::Vector2f(sf::Mouse::getPosition(this->getWindow()));
		_line->append(sf::Vertex(vertexPos,c));
		f.addObject(*_line);
		_mouseDown = false;
	}
}
void StraightLineTool::scrollAction(sf::Event& e){}

StraightLineTool::StraightLineTool(sf::RenderWindow& w): Tool(w){
	this->getIcon().loadFromFile("assets/pencilCursor.png");
}
