#include "ShapeDecorator.h"

bool ShapeDecorator::IsPointInShape(const sf::Vector2f& point) const
{
	return GetGlobalBounds().contains(point);
}

void ShapeDecorator::SetSelect(bool select) 
{
	m_select = select;
}

bool ShapeDecorator::GetSelect() const
{
	return m_select;
}

std::string ShapeDecorator::GetType()
{
	return m_type;
}

sf::RectangleShape ShapeDecorator::GetBounds(sf::Vector2f position, sf::Vector2f size) const
{
	sf::RectangleShape rectangle = sf::RectangleShape();
	rectangle.setPosition(position);
	rectangle.setSize(size);
	rectangle.setOutlineThickness(3);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setFillColor(sf::Color::Transparent);

	return rectangle;
}