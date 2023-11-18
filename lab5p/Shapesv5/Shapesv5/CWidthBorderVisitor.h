#pragma once
#include "IVisitor.h"

class CWidthBorderVisitor : public IVisitor
{
public:
	CWidthBorderVisitor(float width);
	void VisiteShape(ShapeDecorator* shape) override;
private:
	float m_width;
};