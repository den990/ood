#include "CRectangleBuilder.h"

CRectangleBuilder::CRectangleBuilder(std::vector<unsigned int> args)
	: m_leftTop((float)args[0], (float)args[1])
	, m_rightBottom((float)args[2], (float)args[3])
{
	m_borderThickness = args[4];
	m_borderColor = args[5];
	m_fillColor = args[6];
}

void CRectangleBuilder::SetShape()
{
	sf::Vector2f size;
	size.x =abs(m_rightBottom.x - m_leftTop.x);
	size.y = abs(m_rightBottom.y - m_leftTop.y);
	m_shape = new CRectangle(new sf::RectangleShape(size), m_leftTop, m_rightBottom);
}

void CRectangleBuilder::SetPosition()
{
	m_shape->SetPosition(m_leftTop);
}
