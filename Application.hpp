/*
	Applicaion object tracks high-level object such as the current tool, current frame, and
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
		void setColor();
		sf::Color& getColor(sf::Color&);
		Application(sf::RenderWindow&);
		void setTool();
//		Tool getTool();
	private:
		std::vector<Frame> _frames;
		int _currentFrameIndex = 0;
		sf::Color _currentColor = sf::Color::Black;
		sf::RenderWindow& _window;
//		Tool currentTool;
};
