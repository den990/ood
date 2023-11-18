#pragma once
#include "CShapeCreator.h"
#include "CCircle.h"

class CCircleCreator : public CShapeCreator
{
public:
	ShapeDecorator* CreateShape(std::istream& input) override;
};