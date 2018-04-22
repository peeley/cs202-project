/*
	Dots tool creates line of circles, is derived from Tool class.
*/
#include "Tool.hpp"
#ifndef DOTTOOL_HPP_
#define DOTTOOL_HPP_
class DotTool : public Tool{
	using Tool::Tool;
	public:
		DotTool(sf::RenderWindow&);
		void paintTick(Frame&, sf::Color) override;
		void scrollAction(sf::Event&) override;
	private:
		int _dotRadius = 5;
		int _sfxCounter = 0;
};
#endif
