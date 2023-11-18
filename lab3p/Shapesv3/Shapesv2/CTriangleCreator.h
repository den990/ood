#pragma once
#include "CShapeCreator.h"
#include "CTriangle.h"

class CTriangleCreator : public CShapeCreator
{
public:
	ShapeDecorator* CreateShape(std::istream& input) override;
};