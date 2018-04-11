/*
	.cpp for Application object.
*/

#include "Application.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
void Application::drawCurrentFrame(){
	_frames[_currentFrameIndex].drawObjects(_window);
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
void Application::createNewFrame(){
	Frame f;
	_frames.push_back(f);
}
void Application::setColor(sf::Color c){
	_currentColor = c;
}

sf::Color Application::getColor(){
	return _currentColor;
}

void Application::setTool(){
	// TODO
	;
}

/*
Tool Application::getTool(){
	// TODO
	;
}
*/
sf::RenderWindow& Application::getWindow(){
	return _window;
}

void Application::clearCurrentFrame(){
	_frames[_currentFrameIndex].clearObjects();
	cout << "Clearing frame " << _currentFrameIndex << endl;
}
void Application::addToFrame(sf::CircleShape& s){
	_frames[_currentFrameIndex].addObject(s);
}
void Application::close(){
	_window.close();
}
void Application::display(){
	_window.display();
}
Application::Application(sf::RenderWindow& window):_window{window}{
	createNewFrame();
}
