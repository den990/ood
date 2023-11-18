#include "CShapeComposite.h"

float CShapeComposite::GetSquare() const
{
    float square = 0;

    for (const auto& shape : m_shapes)
    {
        square += shape->GetSquare();
    }

    return square;
}

float CShapeComposite::GetPerimeter() const
{
    float perimeter = 0;

    for (const auto& shape : m_shapes)
    {
        perimeter += shape->GetPerimeter();
    }

    return perimeter;
}

std::string CShapeComposite::ToString() const
{
    std::ostringstream strm;

    strm << "Composite shape: "
        << "Square: " << GetSquare() << "; "
        << "Perimeter: " << GetPerimeter();

    return strm.str();
}

void CShapeComposite::SetOutlineThickness(float thickness) const
{
    for (const auto& shape : m_shapes)
    {
        shape->SetOutlineThickness(thickness);
    }
}

void CShapeComposite::SetOutlineColor(sf::Color color) const
{
    for (const auto& shape : m_shapes)
    {
        shape->SetOutlineColor(color);
    }
}

void CShapeComposite::SetFillColor(sf::Color color) const
{
    for (const auto& shape : m_shapes)
    {
        shape->SetFillColor(color);
    }
}

void CShapeComposite::SetPosition(sf::Vector2f position) const
{
    sf::Vector2f finishPosition;
    finishPosition.x = GetPosition().x - position.x;
    finishPosition.y = GetPosition().y - position.y;

    for (const auto& shape : m_shapes)
    {
        shape->SetPosition({ shape->GetPosition().x - finishPosition.x, shape->GetPosition().y - finishPosition.y });
    }
}

sf::Vector2f CShapeComposite::GetPosition() const
{
    sf::FloatRect bound = GetGlobalBounds();
    return { bound.left, bound.top };
}

sf::Color CShapeComposite::GetColor() const
{
    return sf::Color();
}

sf::Color CShapeComposite::GetEdgeColor() const
{
    return sf::Color();
}

float CShapeComposite::GetEdgeWidth() const
{
    return 0.0f;
}

void CShapeComposite::Draw(sf::RenderWindow& window) const
{
    if (m_select)
    {
        sf::FloatRect bound = GetGlobalBounds();
        window.draw(GetBounds({ bound.left,bound.top }, { bound.width, bound.height }));
    }

    for (const auto& shape : m_shapes)
    {
        shape->Draw(window);
    }
}

sf::FloatRect CShapeComposite::GetGlobalBounds() const
{
    sf::FloatRect firstShape = m_shapes.front()->GetGlobalBounds();
    sf::Vector2f min, max;
    min.x = firstShape.left;
    min.y = firstShape.top;
    max.x = min.x + firstShape.width;
    max.y = min.y + firstShape.height;

    for (const auto& shape : m_shapes)
    {
        sf::FloatRect bound = shape->GetGlobalBounds();

        if (bound.left < min.x)
        {
            min.x = bound.left;
        }
        if (bound.top < min.y)
        {
            min.y = bound.top;
        }
        if ((bound.left + bound.width) > max.x)
        {
            max.x = bound.left + bound.width;
        }
        if ((bound.top + bound.height) > max.y)
        {
            max.y = bound.top + bound.height;
        }
    }

    return sf::FloatRect(min.x, min.y, abs(max.x - min.x), abs(max.y - min.y));
}

void CShapeComposite::Add(ShapeDecorator* shape)
{
    m_shapes.push_back(shape);
}

void CShapeComposite::Remove(ShapeDecorator* shape)
{
    auto it = std::find(m_shapes.begin(), m_shapes.end(), shape);
    if (it != m_shapes.end())
    {
        m_shapes.erase(it);
    }
}

std::vector<ShapeDecorator*> CShapeComposite::GetShapes() const
{
    return m_shapes;
}

