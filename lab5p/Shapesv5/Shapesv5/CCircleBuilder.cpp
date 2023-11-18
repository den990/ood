#include "CCircleBuilder.h"

CCircleBuilder::CCircleBuilder(std::vector<unsigned int> args)
	:m_centerPoint((float)args[0], (float)args[1])
	, m_radius((float)args[2])
{
	m_borderThickness = args[3];
	m_borderColor = args[4];
	m_fillColor = args[5];
}

void CCircleBuilder::SetShape()
{
	m_shape = new CCircle(new sf::CircleShape(m_radius), m_centerPoint, m_radius);
}

void CCircleBuilder::SetPosition()
{
	m_shape->SetPosition(m_centerPoint);
}
