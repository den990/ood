#include "DrawingCircle.h"

void DrawingCricle::Draw(sf::RenderWindow& window, IVisualObjectInfo& object) const
{
	sf::CircleShape circle(object.GetRadius());
	circle.setPosition(object.GetCoords().at(0).x - object.GetRadius(), object.GetCoords().at(0).y - object.GetRadius());
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineThickness(1);
	sf::Color color = StringToSfmlColor(object.GetLineColour());
	circle.setOutlineColor(color);

	window.draw(circle);
}
