/*
	Frame class holds all graphical objects (shapes, textures, etc.) of current Frame.
*/
#include <SFML/Graphics.hpp>
#include <vector>
class Frame{
	public:
		Frame();
		std::vector<sf::CircleShape>& getObjects();
	private:
		std::vector<sf::CircleShape> objects();
};
