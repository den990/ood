#pragma once
#include "IShape.h"
#include "Point.h"
class IVisualObjectInfo 
{
public:
	IVisualObjectInfo(std::shared_ptr<IShape> shape)
		:m_shape(shape) {};
	Point Get();
private:
	std::shared_ptr<IShape> m_shape;
};