#pragma once
#include "include.h"
#include "ShapeDecorator.h"

class CRectangle : public ShapeDecorator
{
public:
	CRectangle(ShapePtr&& shape, const sf::Vector2f& bottomRight, const sf::Vector2f& topLeft);
	float GetSquare() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	~CRectangle() = default;
private:
	float m_width;
	float m_height;
};