#pragma once
#include "include.h"


class CTriangleDecorator : public sf::ConvexShape
{
public:
	CTriangleDecorator(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3);
	double GetSquare() const ;
	double GetPerimetr() const ;
	void Draw(sf::RenderWindow& window) const ;
	std::string PrintInfo() const ;
};