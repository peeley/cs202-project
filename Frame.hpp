/*
	Frame class holds all graphical objects (shapes, textures, etc.) of current Frame.
*/
#include <SFML/Graphics.hpp>
#include <vector>
#ifndef FRAME_HPP_
#define FRAME_HPP_
class Frame{
	public:
		Frame();
		std::vector<sf::Drawable*>& getObjects();
		void clearObjects();
		void addObject(sf::Drawable&);
		void drawObjects(sf::RenderWindow&);
	private:
		std::vector<sf::Drawable*> _objects;
};
#endif
