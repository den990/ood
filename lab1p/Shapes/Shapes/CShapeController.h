#pragma once
#include "include.h"
#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"

class CShapeController
{
public:
    CShapeController();
    void Start();

private:
    void ReadFileAndFillData(const std::string& fileName);
    void DrawShapes();
    void HandleEvents();
    void WriteData(const std::string& fileName);

    sf::Vector2f ParseCoordinates(const std::string& coordStr);
    sf::RenderWindow m_window;
    std::vector<std::unique_ptr<sf::Shape>> m_shapes;
};