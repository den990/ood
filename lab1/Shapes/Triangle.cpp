#include "Triangle.h"
#include <iostream>
#include "DrawingTriangle.h"
shape::Triangle::Triangle(std::string id, std::string color, std::string type, double x1, double y1, double x2, double y2, double x3, double y3)
	: Shape(id, color, type, std::make_unique<DrawingTriangle>())
	, m_x1(x1)
	, m_y1(y1)
	, m_x2(x2)
	, m_y2(y2)
	, m_x3(x3)
	, m_y3(y3)
{
}

shape::Triangle::~Triangle()
{
}

void shape::Triangle::AppendProperties(std::ostream& strm) const
{
	strm << m_x1 << ' ' << m_y1 << ' ' << m_x2 << ' ' << m_y2 << ' ' << m_x3 << ' ' <<  m_y3 << ' ' << std::endl;
}
