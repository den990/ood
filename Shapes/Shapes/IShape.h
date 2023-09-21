#pragma once
#include <iomanip>
#include <iostream>
#include <sstream>
#include "IDrawingStrategy.h"

class IShape
{
public:
	IShape(std::unique_ptr<IDrawingStrategy>&& drawingStrategy)
	:m_drawingStrategy(std::move(drawingStrategy)){};
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual uint32_t GetOutlineColour() const = 0;
	virtual std::string ToString() const = 0;

	virtual std::string GetFigureType() const = 0;
	virtual void SetDrawingStrategy(std::unique_ptr<IDrawingStrategy> strategy) = 0;
	virtual ~IShape() = default;
private:
	std::unique_ptr<IDrawingStrategy> m_drawingStrategy;
	std::string m_id;
};