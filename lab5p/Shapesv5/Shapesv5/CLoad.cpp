#include "CLoad.h"

std::vector<ShapeDecorator*> CLoad::ReadShapeInfo(std::istream& input)
{
	std::string str, substr, type;

	CShapeBuilderCreator shapesCreator = CShapeBuilderCreator();
	std::vector<ShapeDecorator*> shapes;
	std::vector<unsigned int> args;

	while (std::getline(input, type))
	{
		if (type == COMPOSITE_START)
		{
			shapesCreator.SetBuilder(new CCompositeBuilder(ReadShapeInfo(input)));
		}
		else if (type == COMPOSITE_END)
		{
			return shapes;
		}
		else
		{
			std::getline(input, str);
			std::stringstream stream(str);
			while (stream >> substr)
			{
				args.push_back(std::stoul(substr));
			}

			if (type == TYPE_CIRCLE)
			{
				shapesCreator.SetBuilder(new CCircleBuilder(args));
			}
			if (type == TYPE_TRIANGLE)
			{
				shapesCreator.SetBuilder(new CTriangleBuilder(args));
			}
			if (type == TYPE_RECTANGLE)
			{
				shapesCreator.SetBuilder(new CRectangleBuilder(args));
			}
		}

		args.clear();
		shapes.push_back(shapesCreator.CreateShape());


	}

	return shapes;
}
