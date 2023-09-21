#include "Point.h"
#include "CSolidShape.h"
#include "DrawRectangle.h"

#pragma once

class CRectangle : public CSolidShape
{
public:
	CRectangle(Point topLeftPoint, double width, double height, uint32_t outlineColour, uint32_t fillColour)
		:IShape(std::make_unique<DrawRectangle>());

	double GetArea() const override;
	double GetPerimeter() const override;

	Point GetLeftTop() const;
	Point GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
	void SetDrawingStrategy(std::unique_ptr<IDrawingStrategy> strategy);

private:
	void AppendProperties(std::ostream& strm) const override;

	Point m_topLeft;
	double m_width;
	double m_height;
};
