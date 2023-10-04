#include "CCircleDecorator.h"


CCircleDecorator::CCircleDecorator(const sf::Vector2f& center, float radius)
	: sf::CircleShape(radius)
{
	setFillColor(sf::Color::Yellow);
	setPosition(center); // Устанавливаем позицию начальной точки
}

 double CCircleDecorator::GetSquare() const 
{
	return M_PI * getRadius() * getRadius();
}

double CCircleDecorator::GetPerimetr() const
{
	return 2 * M_PI * getRadius();
}

void CCircleDecorator::Draw(sf::RenderWindow& window) const
{
	window.draw(*this);
}

std::string CCircleDecorator::PrintInfo() const
{
	std::stringstream ss;
	ss << "CIRCLE: P=" << GetPerimetr() << "; S=" << GetSquare();
	return ss.str();
}
