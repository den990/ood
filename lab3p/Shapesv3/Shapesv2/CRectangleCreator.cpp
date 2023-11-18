#include "CRectangleCreator.h"

ShapeDecorator* CRectangleCreator::CreateShape(std::istream& input)
{
    sf::Vector2f bottomRight, topLeft;
    std::string outlineColorStr;
    std::string fillColorStr;

    input >> bottomRight.x >> bottomRight.y >> topLeft.x >> topLeft.y >> outlineColorStr >> fillColorStr;

    sf::RectangleShape* rectangle = new sf::RectangleShape();
    rectangle->setPosition(topLeft);
    rectangle->setSize({abs(bottomRight.x - topLeft.x), abs(topLeft.y - bottomRight.y)});
    rectangle->setOutlineColor(GetColor(std::stoul(outlineColorStr, nullptr, 16)));
    rectangle->setFillColor(GetColor(std::stoul(fillColorStr, nullptr, 16)));
    
    CRectangle* rectangleDecorator = new CRectangle(rectangle, topLeft, bottomRight);

    return rectangleDecorator;
}
