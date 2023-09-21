#include "DrawLine.h"

void DrawingLine::Draw(sf::RenderWindow& window) const
{
	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f(from.x, from.y), sf::Color(lineColour)),
		sf::Vertex(sf::Vector2f(to.x, to.y), sf::Color(lineColour))
	};

	m_window.draw(line, 2, sf::Lines);
}
