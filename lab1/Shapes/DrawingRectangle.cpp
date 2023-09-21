#include "DrawingRectangle.h"

void DrawingRectangle::Draw(sf::RenderWindow& window, IVisualObjectInfo& object) const
{
	sf::RectangleShape rectangle(sf::Vector2f(object.GetWidth(), object.GetHeight()));
	rectangle.setPosition(object.GetTop(), object.GetLeft());
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineThickness(1);
	sf::Color color = StringToSfmlColor(object.GetLineColour());
	rectangle.setOutlineColor(color);

	window.draw(rectangle);
}
