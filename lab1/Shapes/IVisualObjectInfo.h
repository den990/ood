#pragma once
#include "Point.h"
class IVisualObjectInfo
{
public:
    virtual double GetLeft() const = 0;
    virtual double GetTop() const = 0;
    virtual double GetWidth() const = 0;
    virtual double GetHeight() const = 0;
    virtual double GetRadius() const = 0;
    virtual std::vector<Point> GetCoords() const = 0;
    virtual std::string GetLineColour() const = 0;
};