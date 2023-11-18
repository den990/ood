#pragma once
#include "CBuilder.h"

class CShapeBuilderCreator
{
public:
	void SetBuilder(CBuilder* builder);
	ShapeDecorator* CreateShape();
private:
	CBuilder* m_builder;
};