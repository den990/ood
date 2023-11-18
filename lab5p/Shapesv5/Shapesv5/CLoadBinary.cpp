#include "CLoadBinary.h"

IMementoShape CLoadBinary::Import(std::string fileName)
{
	std::fstream input(fileName + ".bin", std::ios::out | std::ios::binary | std::ios::in);
	std::string result;

	char ch[1];
	while (input.read(ch, 1))
	{
		result += ch[0];
	}

	std::stringstream strm(result);
	std::vector<ShapeDecorator*> copyShapes = ReadShapeInfo(strm);
	std::vector<ShapeDecorator*> copySelectedShapes;
	std::vector<std::pair<ShapeDecorator*, sf::Vector2f>> previousPositions;
	std::vector<std::pair<ShapeDecorator*, sf::Color>> shapeColors;
	std::vector<std::pair<ShapeDecorator*, float>> edgeWidths;
	std::vector<std::pair<ShapeDecorator*, sf::Color>> edgeColors;
	IMementoShape mementoShape = IMementoShape(copyShapes, copySelectedShapes, previousPositions, shapeColors, edgeWidths, edgeColors);
	return mementoShape;
}
