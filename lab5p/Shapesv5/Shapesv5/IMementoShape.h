#pragma once
#include "ShapeDecorator.h"

class IMementoShape
{
public:
    IMementoShape(
        std::vector<ShapeDecorator*> shapes,
        std::vector<ShapeDecorator*> selectedShapes,
        std::vector<std::pair<ShapeDecorator*, sf::Vector2f>> previousPositions,
        std::vector<std::pair<ShapeDecorator*, sf::Color>> shapeColors,
        std::vector<std::pair<ShapeDecorator*, float>> edgeWidths,
        std::vector<std::pair<ShapeDecorator*, sf::Color>> edgeColors)
        : m_shapes(shapes)
        , m_selectedShapes(selectedShapes)
        , m_previousPositions(previousPositions)
        , m_shapeColors(shapeColors)
        , m_edgeWidths(edgeWidths)
        , m_edgeColors(edgeColors)
    {}

    std::vector<ShapeDecorator*> m_shapes;
    std::vector<ShapeDecorator*> m_selectedShapes;
    std::vector<std::pair<ShapeDecorator*, sf::Vector2f>> m_previousPositions;
    std::vector<std::pair<ShapeDecorator*, sf::Color>> m_shapeColors;
    std::vector<std::pair<ShapeDecorator*, float>> m_edgeWidths;
    std::vector<std::pair<ShapeDecorator*, sf::Color>> m_edgeColors;
};
