#include <SFML/Graphics.hpp>
#include "Tool.hpp"
class PencilTool : public Tool{
	using Tool::Tool;
	public:
		void paintTick(Frame&, sf::Color, sf::Event&) override;
		void scrollAction(sf::Event&) override;
		PencilTool(sf::RenderWindow&);
	private:
		bool _mouseDown = false;
		sf::VertexArray* _line;
};
