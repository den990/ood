#pragma once
#include "include.h"
#include "CSimpleShapeDecorator.h"

class CTriangle : public CSimpleShapeDecorator
{
public:
	CTriangle(sf::ConvexShape* shape, sf::Vector2f vertex1, sf::Vector2f vertex2, sf::Vector2f vertex3);
	float GetSquare() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	~CTriangle() = default;
private:
	float GetDistance(const sf::Vector2f& point1, const sf::Vector2f& point2) const;
	sf::Vector2f m_vertex1;
	sf::Vector2f m_vertex2;
	sf::Vector2f m_vertex3;
};