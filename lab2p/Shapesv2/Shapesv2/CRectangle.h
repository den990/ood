#pragma once
#include "include.h"
#include "CSimpleShapeDecorator.h"5

class CRectangle : public CSimpleShapeDecorator
{
public:
	CRectangle(sf::RectangleShape* shape, const sf::Vector2f& bottomRight, const sf::Vector2f& topLeft);
	float GetSquare() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	~CRectangle() = default;
private:
	float m_width;
	float m_height;
};