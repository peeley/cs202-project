/*
	.cpp for Application object.
*/

#include "Application.hpp"
using std::vector;
void Application::drawCurrentFrame(){
	vector<sf::CircleShape> objects = _frames[_currentFrameIndex].getObjects();
	for(int i = 0; i < objects.size(); ++i){
		_window.draw(objects[i]);
	}
}
void Application::cycleNextFrame(){
	if(_currentFrameIndex != _frames.size()){
		++_currentFrameIndex;
	}
}
void Application::cycleLastFrame(){
	if(_currentFrameIndex != 0){
		--_currentFrameIndex;
	}
}
void setColor(){
	// TODO
	;
}
void setTool(){
	// TODO
	;
}
/*
Tool getTool(){
	// TODO
	;
}
*/
sf::Color& getColor(){
	// TODO
	;
}
Application::Application(sf::RenderWindow& window):_window{window}{
	
}
