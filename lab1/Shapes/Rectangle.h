#pragma once
#include "Shape.h"
#include "IVisualObjectInfo.h"

namespace shape
{
	class Rectangle final : public Shape, IVisualObjectInfo
	{
	public:
		Rectangle(std::string id, std::string color, std::string type, double left, double top, double width, double height);
		~Rectangle();
		double GetLeft() const override;
		double GetTop() const override;
		double GetWidth() const override;
		double GetHeight() const override;
		std::string GetLineColour() const override;

	private:
		void AppendProperties(std::ostream& strm) const override;
		double m_left;
		double m_top;
		double m_width;
		double m_height;
	};
}
