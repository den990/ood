#include "CBuilder.h"

void CBuilder::SetFillColor()
{
	m_shape->SetFillColor(sf::Color(m_fillColor));
}

void CBuilder::SetBorderColor()
{
	m_shape->SetOutlineColor(sf::Color(m_borderColor));
}

void CBuilder::SetBorderThickness()
{
	m_shape->SetOutlineThickness(m_borderThickness);
}

ShapeDecorator* CBuilder::GetShape()
{
	return m_shape;
}
