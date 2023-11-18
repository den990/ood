#include "CTriangle.h"

CTriangle::CTriangle(ShapePtr&& shape, sf::Vector2f vertex1, sf::Vector2f vertex2, sf::Vector2f vertex3)
	:ShapeDecorator(std::move(shape))
	,m_vertex1(vertex1)
	,m_vertex2(vertex2)
	,m_vertex3(vertex3)
{
}

float CTriangle::GetSquare() const
{
	double a = GetDistance(m_vertex1, m_vertex2);
	double b = GetDistance(m_vertex2, m_vertex3);
	double c = GetDistance(m_vertex3, m_vertex1);

	double p = (a + b + c) / 2; 
	return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

float CTriangle::GetPerimeter() const
{
	double a = GetDistance(m_vertex1, m_vertex2);
	double b = GetDistance(m_vertex2, m_vertex3);
	double c = GetDistance(m_vertex3, m_vertex1);

	return a + b + c;
}

std::string CTriangle::ToString() const
{
	std::stringstream ss;
	ss << "TRIANGLE: P=" << GetPerimeter() << "; S=" << GetSquare();
	return ss.str();
}

float CTriangle::GetDistance(const sf::Vector2f& point1, const sf::Vector2f& point2) const
{
	double dx = point2.x - point1.x;
	double dy = point2.y - point1.y;
	return std::sqrt(dx * dx + dy * dy);
}
