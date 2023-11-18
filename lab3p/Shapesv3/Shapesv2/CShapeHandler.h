#pragma once
#include "CCircleCreator.h"
#include "CRectangleCreator.h"
#include "CTriangleCreator.h"
#include "ShapeDecorator.h"
#include "CShapeComposite.h"

class CShapeHandler
{
public:
	void CreateCircle(std::istringstream& args);
	void CreateTriangle(std::istringstream& args);
	void CreateRectangle(std::istringstream& args);

	void Moving() const;
	void SetCursorPosition(sf::Vector2f position);
	void DragAndDrop(sf::Event event);

	void HandleKey(sf::Event event);

	std::vector<ShapeDecorator*> GetShapes() const;

	void NotMove();

	void FillShape(sf::Event event, sf::Color color);
	void FillOutlineColor(sf::Event event, sf::Color color);
	void SetOutlineThickness(sf::Event event, float width);

private:

	void GroupShapes();
	void UngroupShapes();

	void AddShapeInSelect(ShapeDecorator* shape);
	void RemoveShapeInSelect(ShapeDecorator* shape);
	void ClearSelectedShapes(ShapeDecorator* shape);

	void HandleMouse(sf::Event event);
	void PreparingForMove(sf::Event event);

	std::vector<ShapeDecorator*> m_shapes;
	std::vector<ShapeDecorator*> m_selectedShapes;
	bool m_move = false;
	sf::Vector2f m_cursorPosition, m_cursorOffset;
};