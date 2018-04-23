#include "PencilTool.hpp"

void PencilTool::paintTick(Frame& f, sf::Color c, sf::Event& e){
	if(e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left){
		_mouseDown = true;
		_line = new sf::VertexArray(sf::LinesStrip);
	}
	else if(e.type == sf::Event::MouseMoved && _mouseDown){
		sf::Vector2f vertexPos = sf::Vector2f(sf::Mouse::getPosition(this->getWindow()));
		_line->append(sf::Vertex(vertexPos,c));
		//this->playSound();                        ///////////temp turn off link errors
		f.addObject(*_line);
	}
	else if(e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left){
		_mouseDown = false;
	}
}
void PencilTool::scrollAction(sf::Event& e){}

PencilTool::PencilTool(sf::RenderWindow& w): Tool(w){
	this->getIcon().loadFromFile("assets/pencilCursor.png");
	//this->initializeSound("assets/drawEffect.wav");          //////////temp turn off link errors
}
