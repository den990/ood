#include "CTriangleDecorator.h"

CTriangleDecorator::CTriangleDecorator(const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3)
	: sf::ConvexShape(3)
{
	setFillColor(sf::Color::Red);
	setPoint(0, p1);
	setPoint(1, p2);
	setPoint(2, p3);
}

double CTriangleDecorator::GetSquare() const
{
	sf::Vector2f p1 = getPoint(0);
	sf::Vector2f p2 = getPoint(1);
	sf::Vector2f p3 = getPoint(2);

	return 0.5 * std::abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)));
}

double CTriangleDecorator::GetPerimetr() const
{
	sf::Vector2f p1 = getPoint(0);
	sf::Vector2f p2 = getPoint(1);
	sf::Vector2f p3 = getPoint(2);

	double a = std::sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	double b = std::sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2));
	double c = std::sqrt(pow(p3.x - p1.x, 2) + pow(p3.y - p1.y, 2));

	return a + b + c;
}

void CTriangleDecorator::Draw(sf::RenderWindow& window) const
{
	window.draw(*this);
}

std::string CTriangleDecorator::PrintInfo() const
{
	std::stringstream ss;
	ss << "TRIANGLE: P=" << GetPerimetr() << "; S=" << GetSquare();
	return ss.str();
}

