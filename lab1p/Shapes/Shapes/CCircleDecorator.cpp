#include "CCircleDecorator.h"


CCircleDecorator::CCircleDecorator(float x, float y, float radius)
	: sf::CircleShape(radius)
{
	setFillColor(sf::Color::Yellow);
	setPosition(x, y); // Устанавливаем позицию начальной точки
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
