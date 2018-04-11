
#include "Frame.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

Frame::Frame(){
	cout << "Frame created!" << endl;	
}
void Frame::clearObjects(){
	_objects.clear();
}
void Frame::addObject(sf::CircleShape& s){
	_objects.push_back(s);
}
vector<sf::CircleShape>& Frame::getObjects(){
	return _objects;
}
void Frame::drawObjects(sf::RenderWindow& window){
	for(int i = 0; i < _objects.size(); ++i){
		window.draw(_objects[i]);
	}
}
