#include "CRectangle.h"

CRectangle::CRectangle(sf::RectangleShape* shape, const sf::Vector2f& topLeft, const sf::Vector2f& bottomRight)
    :m_width(abs(topLeft.x - bottomRight.x))
    ,m_height(abs(topLeft.y - bottomRight.y))
{
    m_type = TYPE_RECTANGLE;
    m_shape = shape;
}

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

float CRectangle::GetWidth() const
{
    return m_width;
}

float CRectangle::GetHeight() const
{
    return m_height;
}
