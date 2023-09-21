#pragma once
#include "Shape.h"
#include "IVisualObjectInfo.h"
namespace shape
{
	class Circle final : public Shape, IVisualObjectInfo
	{
	public:
		Circle(std::string id, std::string color, std::string type, double x, double y, double r);
		std::vector<Point> GetCoords() const override;
		double GetRadius() const override;
		std::string GetLineColour() const override;
		~Circle();
	private:
		void AppendProperties(std::ostream& strm) const override;
		Point m_coords;
		double m_r;
	};
}