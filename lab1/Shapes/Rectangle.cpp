#include "Rectangle.h"
#include <iostream>
#include "DrawingRectangle.h"

shape::Rectangle::Rectangle(std::string id, std::string color, std::string type, double left, double top, double width, double height)
	: Shape(id, color, type, std::make_unique<DrawingRectangle>())
	, m_left(left)
	, m_top(top)
	, m_width(width)
	, m_height(height)
{
}

shape::Rectangle::~Rectangle()
{
}

double shape::Rectangle::GetLeft() const
{
	return m_left;
}

double shape::Rectangle::GetTop() const
{
	return m_top;
}

double shape::Rectangle::GetWidth() const
{
	return m_width;
}

double shape::Rectangle::GetHeight() const
{
	return m_height;
}

std::string shape::Rectangle::GetLineColour() const
{
	return this->GetColor();
}

void shape::Rectangle::AppendProperties(std::ostream& strm) const
{
	strm << m_left << ' ' << m_top << ' ' << m_width << m_height << std::endl;
}
