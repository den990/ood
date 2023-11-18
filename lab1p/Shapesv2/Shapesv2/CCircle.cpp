#include "CCircle.h"

CCircle::CCircle(ShapePtr&& shape, sf::Vector2f center, float radius)
	:ShapeDecorator(std::move(shape))
	,m_center(center)
	,m_radius(radius)
{}

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

