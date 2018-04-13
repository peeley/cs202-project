/*
	Tool object is abstract data type inherited by paint tools such as brushes, shapes, etc.
*/
#include <SFML/Graphics.hpp>
#include "Frame.hpp"

#ifndef TOOL_HPP_
#define TOOL_HPP_
class Tool{
	public:
		virtual void paintTick(Frame&, sf::Color) const = 0;
		Tool(sf::RenderWindow&);
		sf::RenderWindow& getWindow() const;
		virtual ~Tool();
	private:
		sf::RenderWindow& _window;
};
#endif
