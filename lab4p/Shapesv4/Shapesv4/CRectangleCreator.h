#pragma once
#include "CShapeCreator.h"
#include "CRectangle.h"

class CRectangleCreator : public CShapeCreator
{
public:
	ShapeDecorator* CreateShape(std::istream& input) override;
};