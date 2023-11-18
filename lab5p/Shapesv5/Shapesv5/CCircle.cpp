#include "CCircle.h"

CCircle::CCircle(sf::CircleShape* shape, sf::Vector2f center, float radius)
	:m_center(center)
	,m_radius(radius)
{
	m_shape = shape;
	m_type = TYPE_CIRCLE;
}

float CCircle::GetSquare() const
{
	return M_PI * m_radius * m_radius;
}

float CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

std::string CCircle::ToString() const
{
	std::stringstream ss;
	ss << "CIRCLE: P=" << GetPerimeter() << "; S=" << GetSquare();
	return ss.str();
}

float CCircle::GetRadius() const
{
	return m_radius;
}

