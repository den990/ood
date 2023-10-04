#pragma once
#include "include.h"

class CRectangleDecorator : public sf::RectangleShape
{
public:
	CRectangleDecorator(const sf::Vector2f& bottomRight, const sf::Vector2f& topLeft);
	double GetSquare() const ;
	double GetPerimetr() const;
	void Draw(sf::RenderWindow& window) const ;
	std::string PrintInfo() const;
};