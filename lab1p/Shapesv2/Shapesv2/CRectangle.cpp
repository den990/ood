#include "CRectangle.h"

CRectangle::CRectangle(ShapePtr&& shape, const sf::Vector2f& bottomRight, const sf::Vector2f& topLeft)
    :ShapeDecorator(std::move(shape))
    ,m_width(abs(topLeft.x - bottomRight.x))
    ,m_height(abs(topLeft.y - bottomRight.y))
{}

float CRectangle::GetSquare() const
{
    return m_height * m_width;
}

float CRectangle::GetPerimeter() const
{
    return 2 * (m_height + m_width);
}

std::string CRectangle::ToString() const
{
    std::stringstream ss;
    ss << "RECTANGLE: P=" << GetPerimeter() << "; S=" << GetSquare();
    return ss.str();
}
