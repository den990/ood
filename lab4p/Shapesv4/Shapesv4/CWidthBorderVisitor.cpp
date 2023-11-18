#include "CWidthBorderVisitor.h"

CWidthBorderVisitor::CWidthBorderVisitor(float width)
	:m_width(width)
{
}

void CWidthBorderVisitor::VisiteShape(ShapeDecorator* shape)
{
	shape->SetOutlineThickness(m_width);
}
