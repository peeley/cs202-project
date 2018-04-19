/*
	Tool object is abstract data type inherited by paint tools such as brushes, shapes, etc.
*/
#include <SFML/Graphics.hpp>
#include <string>
#include "Frame.hpp"

#ifndef TOOL_HPP_
#define TOOL_HPP_
class Tool{
	public:
		virtual void paintTick(Frame&, sf::Color) const = 0;
		virtual void scrollAction(sf::Event&) = 0;
		Tool(sf::RenderWindow&, std::string&);
		Tool(sf::RenderWindow&);
		sf::RenderWindow& getWindow() const;
		virtual ~Tool();
		sf::Texture& getIcon() ;
	private:
		sf::RenderWindow& _window;
		sf::Texture _mouseIcon;	
};
#endif
