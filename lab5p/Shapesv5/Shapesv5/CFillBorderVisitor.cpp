#include "CFillBorderVisitor.h"

CFillBorderVisitor::CFillBorderVisitor(sf::Color color)
	:m_color(color)
{
}

void CFillBorderVisitor::VisiteShape(ShapeDecorator* shape)
{
	shape->SetOutlineColor(m_color);
}
