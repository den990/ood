#pragma once
#include "include.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "ShapeDecorator.h"
#include "CShapeComposite.h"

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

    void HandleMouse(sf::Event event);
    void AddShapeInSelect(ShapeDecorator* shape);
    void RemoveShapeInSelect(ShapeDecorator* shape);
    void ClearSelectedShapes(ShapeDecorator* shape);


    void HandleKey(sf::Event event);
    void GroupShapes();
    void UngroupShapes();

    void PreparingForMove(ShapeDecorator* shape);
    void Moving() const;

    sf::Vector2f ParseCoordinates(const std::string& coordStr);
    sf::RenderWindow m_window;
    sf::Vector2f m_cursorPosition;
    sf::Vector2f m_cursorOffset;
    std::vector<ShapeDecorator*> m_shapes;
    std::vector<ShapeDecorator*> m_selectedShapes;
    bool m_move = false;
};