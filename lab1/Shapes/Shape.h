#pragma once
#include <string>
#include "IDrawingStrategy.h"
#include <cassert>

namespace shape
{
	class Shape
	{
	public:
		Shape(std::string id, std::string color, std::string type, std::unique_ptr<IDrawingStrategy>&& drawingStrategy);
		virtual ~Shape();

		void MoveShape();
		void SetColor(std::string newColor);
		void ChangeShape(std::string shapeId, std::string shapeType, std::istream& args);
		virtual void Draw();
		void SetDrawingStrategyBehavior(std::unique_ptr<IDrawingStrategy>&& drawingStrategy);

		std::string GetColor() const;
		std::string GetType() const;
		std::string GetId() const;
		std::string ToString() const;

	private:
		virtual void AppendProperties(std::ostream& strm) const = 0;
		std::string m_id;
		std::string m_color;
		std::string m_type;
		std::unique_ptr<IDrawingStrategy> m_drawingStrategy;
	};

} // namespace shape