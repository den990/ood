#pragma once
#include "include.h"


class CCircleDecorator : public sf::CircleShape
{
public:
	CCircleDecorator(const sf::Vector2f& center, float radius);
	double GetSquare() const;
	double GetPerimetr() const;
	void Draw(sf::RenderWindow& window) const;
	std::string PrintInfo() const;
};