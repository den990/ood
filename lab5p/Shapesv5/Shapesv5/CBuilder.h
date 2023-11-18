#pragma once
#include "ShapeDecorator.h"

class CBuilder
{
public:
	virtual void SetShape() = 0;
	virtual void SetPosition() = 0;
	virtual void SetFillColor();
	virtual void SetBorderColor();
	virtual void SetBorderThickness();

	ShapeDecorator* GetShape();
protected:
	ShapeDecorator* m_shape = nullptr;
	unsigned int m_fillColor;
	unsigned int m_borderColor;
	float m_borderThickness;
};