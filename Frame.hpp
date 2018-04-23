/*
	Frame class holds all graphical objects (shapes, textures, etc.) of current Frame.
*/
#include <SFML/Graphics.hpp>
#include <vector>
#ifndef FRAME_HPP_
#define FRAME_HPP_
class Frame{
	public:
		Frame(sf::RenderWindow&, int w, int h);
		void clear();
		void addObject(sf::Drawable&);
		void drawObjects();
		sf::RenderWindow& getWindow();
	private:
		sf::Texture _texture;
		sf::Sprite _sprite;
		sf::RenderWindow& _window;
};
#endif
