/*
	Dots tool creates line of circles, is derived from Tool class.
*/
#include "Tool.hpp"
#ifndef DOTTOOL_HPP_
#define DOTTOOL_HPP_
class DotTool : public Tool{
	using Tool::Tool;
	public:
		void paintTick(Frame&, sf::Color) const override;
		void scrollAction(sf::Event&) override;
	private:
		int _dotRadius = 5;
};
#endif
