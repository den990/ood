#include "CSave.h"

void CSave::PrintShapeInfo(std::ostream& output, std::vector<ShapeDecorator*> shapes) const
{
	for (const auto& shape : shapes)
	{
		if (typeid(*shape) == typeid(CCircle))
		{
			output << GetCircleInfo(static_cast<CCircle*>(shape));
		}
		else if (typeid(*shape) == typeid(CTriangle))
		{
			output << GetTriangleInfo(static_cast<CTriangle*>(shape));
		}
		else if (typeid(*shape) == typeid(CRectangle))
		{
			output << GetRectangleInfo(static_cast<CRectangle*>(shape));
		}
		else if (typeid(*shape) == typeid(CShapeComposite))
		{
			output << COMPOSITE_START << std::endl;
			PrintShapeInfo(output, static_cast<CShapeComposite*>(shape)->GetShapes());
			output << COMPOSITE_END << std::endl;
		}
	}
}

std::string CSave::GetCircleInfo(CCircle* shape) const
{
	sf::Vector2f position = shape->GetPosition();
	float radius = shape->GetRadius();
	float borderWidth = shape->GetEdgeWidth();
	sf::Color outlineColor = shape->GetEdgeColor();
	sf::Color fillColor = shape->GetColor();

	std::stringstream strm;

	strm << shape->GetType() << std::endl // можно перенести название в сам class CCircle
		<< position.x << " " << position.y << " "
		<< radius << " "
		<< borderWidth << " "
		<< outlineColor.toInteger() << " "
		<< fillColor.toInteger() << std::endl;

	return strm.str();
}

std::string CSave::GetTriangleInfo(CTriangle* shape) const
{
	sf::Vector2f vertex1 = shape->GetVertex1();
	sf::Vector2f vertex2 = shape->GetVertex2();
	sf::Vector2f vertex3 = shape->GetVertex3();

	sf::Vector2f position = shape->GetPosition();

	vertex1 = { vertex1.x + position.x, vertex1.y + position.y };
	vertex2 = { vertex2.x + position.x, vertex2.y + position.y };
	vertex3 = { vertex3.x + position.x, vertex3.y + position.y };

	float borderWidth = shape->GetEdgeWidth();
	sf::Color outlineColor = shape->GetEdgeColor();
	sf::Color fillColor = shape->GetColor();

	std::stringstream strm;

	strm << shape->GetType() << std::endl
		<< vertex1.x << " " << vertex1.y << " "
		<< vertex2.x << " " << vertex2.y << " "
		<< vertex3.x << " " << vertex3.y << " "
		<< borderWidth << " "
		<< outlineColor.toInteger() << " "
		<< fillColor.toInteger() << std::endl;

	return strm.str();
}

std::string CSave::GetRectangleInfo(CRectangle* shape) const
{
	sf::Vector2f topleft = shape->GetPosition();
	sf::Vector2f bottomRight;
	bottomRight.x = topleft.x + shape->GetWidth();
	bottomRight.y = topleft.y - shape->GetHeight();
	float borderWidth = shape->GetEdgeWidth();
	sf::Color outlineColor = shape->GetEdgeColor();
	sf::Color fillColor = shape->GetColor();

	std::stringstream strm;

	strm << shape->GetType() << std::endl
		<< topleft.x << " " << topleft.y << " "
		<< bottomRight.x << " " << bottomRight.y << " "
		<< borderWidth << " "
		<< outlineColor.toInteger() << " "
		<< fillColor.toInteger() << std::endl;

	return strm.str();
}
