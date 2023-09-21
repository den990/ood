#include "DrawRectangle.h"

void DrawRectangle::Draw() const
{
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setPosition(topLeftPoint.x, topLeftPoint.y);
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(sf::Color(lineColour));

	m_window.draw(rectangle);
}
