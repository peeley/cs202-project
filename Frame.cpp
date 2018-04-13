
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
void Frame::addObject(sf::Drawable& s){
	_objects.push_back(&s);
}
vector<sf::Drawable*>& Frame::getObjects(){
	return _objects;
}
void Frame::drawObjects(sf::RenderWindow& window){
	for(auto i:_objects){
		window.draw(*i);
	}
}
