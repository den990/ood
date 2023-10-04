#include "CRectangleDecorator.h"

CRectangleDecorator::CRectangleDecorator(const sf::Vector2f& bottomRight, const sf::Vector2f& topLeft)
{
	sf::Vector2f size = bottomRight - topLeft;
	setSize(size);
	setPosition(topLeft);
	setFillColor(sf::Color::Blue); // Здесь устанавливаем цвет для прямоугольника
}

double CRectangleDecorator::GetSquare() const
{
	return getSize().x * getSize().y;
}

double CRectangleDecorator::GetPerimetr() const
{
	return 2 * (getSize().x + getSize().y);
}

void CRectangleDecorator::Draw(sf::RenderWindow& window) const
{
	window.draw(*this);
}

std::string CRectangleDecorator::PrintInfo() const
{
	std::stringstream ss;
	ss << "RECTANGLE: P=" << GetPerimetr() << "; S=" << GetSquare();
	return ss.str();
}

