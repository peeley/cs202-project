#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tool.hpp"

class SquareTool : public Tool{
	using Tool::Tool;
	public:
		void paintTick(Frame&, sf::Color, sf::Event&) override;
		void scrollAction(sf::Event&) override;
		SquareTool(sf::RenderWindow&);
	private:
		bool _mouseDown = false;
		sf::RectangleShape* _square;
		sf::Vector2i _startPos;
		float _outlineThickness = 10;
		int _sfxCounter = 0;
};
