#include "CCircleCreator.h"

ShapeDecorator* CCircleCreator::CreateShape(std::istream& input)
{
    sf::Vector2f center;
    float radius;
    std::string outlineColorStr;
    std::string fillColorStr;

    input >> center.x >> center.y >> radius >> outlineColorStr >> fillColorStr;

    sf::CircleShape* circle = new sf::CircleShape();
    circle->setPosition(center);
    circle->setRadius(radius);
    circle->setOutlineColor(GetColor(std::stoul(outlineColorStr, nullptr, 16)));
    circle->setFillColor(GetColor(std::stoul(fillColorStr, nullptr, 16)));

    CCircle* circleDecorator = new CCircle(circle, center, radius);

    return circleDecorator;
}
