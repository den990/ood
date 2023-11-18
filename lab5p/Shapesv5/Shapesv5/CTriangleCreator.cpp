#include "CTriangleCreator.h"

ShapeDecorator* CTriangleCreator::CreateShape(std::istream& input)
{
    sf::Vector2f vertex1;
    sf::Vector2f vertex2;
    sf::Vector2f vertex3;
    std::string outlineColorStr;
    std::string fillColorStr;

    input >> vertex1.x >> vertex1.y >> vertex2.x >> vertex2.y >> vertex3.x >> vertex3.y >> outlineColorStr >> fillColorStr;

    sf::ConvexShape* triangle = new sf::ConvexShape();
    triangle->setPointCount(3);
    triangle->setPoint(0, vertex1);
    triangle->setPoint(1, vertex2);
    triangle->setPoint(2, vertex3);
    triangle->setOutlineColor(GetColor(std::stoul(outlineColorStr, nullptr, 16)));
    triangle->setFillColor(GetColor(std::stoul(fillColorStr, nullptr, 16)));

    CTriangle* triangleDecorator = new CTriangle(triangle, vertex1, vertex2, vertex3);

    return triangleDecorator;
}
