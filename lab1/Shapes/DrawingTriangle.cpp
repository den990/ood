#include "DrawingTriangle.h"

void DrawingTriangle::Draw(sf::RenderWindow& window) const
{
	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f(vertex1.x, vertex1.y), sf::Color(lineColour)),
		sf::Vertex(sf::Vector2f(vertex2.x, vertex2.y), sf::Color(lineColour)),
		sf::Vertex(sf::Vector2f(vertex3.x, vertex3.y), sf::Color(lineColour)),
		sf::Vertex(sf::Vector2f(vertex1.x, vertex1.y), sf::Color(lineColour))
	};

	window.draw(line, 4, sf::LinesStrip);
}
