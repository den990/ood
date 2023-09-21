#include <iostream>

#pragma once

struct Point
{
	double x;
	double y;
};

std::ostream& operator<<(std::ostream& stream, const Point& point);

double GetDistance(const Point& left, const Point& right);
