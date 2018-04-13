/*
	Pencil tool inherits from Tool, draws thin line on cavas.
*/
class Pencil : public Tool{
	using Tool::Tool;
	public:
		void paintTick(Frame&, sf::Color) const override;
}
