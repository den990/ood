#pragma once
#include "include.h"
#include "CSimpleShapeDecorator.h"

class CRectangle : public CSimpleShapeDecorator
{
public:
	CRectangle(sf::RectangleShape* shape, const sf::Vector2f& topLeft, const sf::Vector2f& bottomRight);
	float GetSquare() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	~CRectangle() = default;
	float GetWidth() const;
	float GetHeight() const;
private:
	float m_width;
	float m_height;
};