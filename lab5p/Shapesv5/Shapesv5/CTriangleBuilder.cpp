#include "CTriangleBuilder.h"

CTriangleBuilder::CTriangleBuilder(std::vector<unsigned int> args)
	: m_vertexFirst((float)args[0], (float)args[1])
	, m_vertexSecond((float)args[2], (float)args[3])
	, m_vertexThird((float)args[4], (float)args[5])
{
	m_borderThickness = args[6];
	m_borderColor = args[7];
	m_fillColor = args[8];
}

void CTriangleBuilder::SetShape()
{
	m_shape = new CTriangle(new sf::ConvexShape(3), m_vertexFirst, m_vertexSecond, m_vertexThird);
}

void CTriangleBuilder::SetPosition()
{
	CTriangle* triangle = static_cast<CTriangle*>(m_shape);
	triangle->SetPosition();
}
