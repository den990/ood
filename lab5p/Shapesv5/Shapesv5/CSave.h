#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "CCircle.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CShapeComposite.h"

class CSave
{
public:
	virtual void Save(std::string& fileName, std::vector<ShapeDecorator*> shapes) = 0;
protected:
	void PrintShapeInfo(std::ostream& output, std::vector<ShapeDecorator*> shapes) const;
private:
	std::string GetCircleInfo(CCircle* shape) const;
	std::string GetTriangleInfo(CTriangle* shape) const;
	std::string GetRectangleInfo(CRectangle* shape) const;
};