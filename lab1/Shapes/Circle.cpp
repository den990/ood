#include "Circle.h"
#include <iostream>
#include "DrawingCircle.h"

shape::Circle::Circle(std::string id, std::string color, std::string type, double x, double y, double r)
	: Shape(id, color, type, std::make_unique<DrawingCricle>())
	, m_coords({x, y})
	, m_r(r)
{
}

std::vector<Point> shape::Circle::GetCoords() const
{
	return { m_coords };
}

double shape::Circle::GetRadius() const
{
	return m_r;
}

std::string shape::Circle::GetLineColour() const
{
	return this->GetColor();
}

shape::Circle::~Circle()
{
}

void shape::Circle::AppendProperties(std::ostream& strm) const
{
	strm << m_coords.x << ' ' << m_coords.y << ' ' << m_r << std::endl;
}
