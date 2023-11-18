#pragma once
#include "include.h"
#include "CSimpleShapeDecorator.h"

class CCircle : public CSimpleShapeDecorator
{
public:
	CCircle(sf::CircleShape* shape, sf::Vector2f center, float radius);
	float GetSquare() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	~CCircle() = default;
private:
	sf::Vector2f m_center;
	float m_radius;
};