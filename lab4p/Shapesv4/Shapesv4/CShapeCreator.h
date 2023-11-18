#pragma once
#include "ShapeDecorator.h"

class CShapeCreator
{
public:
	virtual ShapeDecorator* CreateShape(std::istream& input) = 0;
protected:
	sf::Color GetColor(uint32_t color);
};