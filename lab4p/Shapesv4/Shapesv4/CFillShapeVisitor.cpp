#include "CFillShapeVisitor.h"

CFillShapeVisitor::CFillShapeVisitor(sf::Color color)
	:m_color(color)
{}

void CFillShapeVisitor::VisiteShape(ShapeDecorator * shape)
{
	shape->SetFillColor(m_color);
}
