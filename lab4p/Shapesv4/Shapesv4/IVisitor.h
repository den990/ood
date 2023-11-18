#pragma once
#include "ShapeDecorator.h"

class IVisitor
{
public:
	virtual void VisiteShape(ShapeDecorator* shape) = 0;
};