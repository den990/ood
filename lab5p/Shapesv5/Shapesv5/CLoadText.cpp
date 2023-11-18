#include "CLoadText.h"

IMementoShape CLoadText::Import(std::string fileName)
{
	std::ifstream input(fileName + ".txt");
	std::vector<ShapeDecorator*> copyShapes = ReadShapeInfo(input);
	std::vector<ShapeDecorator*> copySelectedShapes;
	std::vector<std::pair<ShapeDecorator*, sf::Vector2f>> previousPositions;
	std::vector<std::pair<ShapeDecorator*, sf::Color>> shapeColors;
	std::vector<std::pair<ShapeDecorator*, float>> edgeWidths;
	std::vector<std::pair<ShapeDecorator*, sf::Color>> edgeColors;
	IMementoShape mementoShape = IMementoShape(copyShapes, copySelectedShapes, previousPositions, shapeColors, edgeWidths, edgeColors);
	return mementoShape;
}
