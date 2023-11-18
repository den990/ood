#include "CTriangle.h"

CTriangle::CTriangle(sf::ConvexShape* shape, sf::Vector2f vertex1, sf::Vector2f vertex2, sf::Vector2f vertex3)
	:m_vertex1(vertex1)
	,m_vertex2(vertex2)
	,m_vertex3(vertex3)
{
	m_type = TYPE_TRIANGLE;
	m_shape = shape;
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

sf::Vector2f CTriangle::GetVertex1() const
{
	return m_vertex1;
}

sf::Vector2f CTriangle::GetVertex2() const
{
	return m_vertex2;
}

sf::Vector2f CTriangle::GetVertex3() const
{
	return m_vertex3;
}

void CTriangle::SetPosition()
{
	sf::ConvexShape* triangle = static_cast<sf::ConvexShape*>(m_shape);

	triangle->setPoint(0, sf::Vector2f(m_vertex1.x, m_vertex1.y));
	triangle->setPoint(1, sf::Vector2f(m_vertex2.x, m_vertex2.y));
	triangle->setPoint(2, sf::Vector2f(m_vertex3.x, m_vertex3.y));
}
