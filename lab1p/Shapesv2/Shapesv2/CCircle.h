#pragma once
#include "include.h"
#include "ShapeDecorator.h"

class CCircle : public ShapeDecorator
{
public:
	CCircle(ShapePtr&& shape, sf::Vector2f center, float radius);
	float GetSquare() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	~CCircle() = default;
private:
	sf::Vector2f m_center;
	float m_radius;
};