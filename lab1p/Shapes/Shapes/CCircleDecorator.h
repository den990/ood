#pragma once
#include "include.h"


class CCircleDecorator : public sf::CircleShape
{
public:
	CCircleDecorator(float x, float y, float radius);
	double GetSquare() const;
	double GetPerimetr() const;
	void Draw(sf::RenderWindow& window) const;
	std::string PrintInfo() const;
};