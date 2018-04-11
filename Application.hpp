/*
	Application object tracks high-level object such as the current tool, current frame, and
	playing animations.
*/
#include <SFML/Graphics.hpp>
#include <vector>
#include "Frame.hpp"
class Application{
	public:
		void drawCurrentFrame();
		void cycleNextFrame();
		void cycleLastFrame();
		void createNewFrame();
		void setColor(sf::Color);
		sf::Color getColor();
		Application(sf::RenderWindow&);
		sf::RenderWindow& getWindow();
		void setTool();
		void clearCurrentFrame();
		void addToFrame(sf::CircleShape&);
		void close();
		void display();
//		Tool getTool();
	private:
		std::vector<Frame> _frames;
		int _currentFrameIndex = 0;
		sf::Color _currentColor = sf::Color::Black;
		sf::RenderWindow& _window;
//		Tool _currentTool;
};
