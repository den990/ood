#pragma once
#include "IMementoShape.h"
#include "CShapeBuilderCreator.h"
#include "CCompositeBuilder.h"
#include "CCircleBuilder.h"
#include "CRectangleBuilder.h"
#include "CTriangleBuilder.h"

class CLoad
{
public:
	virtual IMementoShape Import(std::string fileName) = 0;
protected:
	std::vector<ShapeDecorator*> ReadShapeInfo(std::istream& input);
};