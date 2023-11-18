#pragma once
#include "CCircleCreator.h"
#include "CRectangleCreator.h"
#include "CTriangleCreator.h"
#include "ShapeDecorator.h"
#include "CShapeComposite.h"
#include <stack>
#include "IMementoShape.h"
#include "IVisitor.h"

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

	void Accept(IVisitor* visitor, sf::Event event);

	void SaveHistory(sf::Event& event);
private:

	void GroupShapes(sf::Event& event);
	void UngroupShapes(sf::Event& event);
	void Undo();


	void SetPreviousState(const IMementoShape& state);

	void AddShapeInSelect(ShapeDecorator* shape);
	void RemoveShapeInSelect(ShapeDecorator* shape);
	void ClearSelectedShapes(ShapeDecorator* shape);

	void HandleMouse(sf::Event event);
	void PreparingForMove(sf::Event event);


	std::vector<ShapeDecorator*> CopyShapes(std::vector<ShapeDecorator*> shapes);

	std::vector<ShapeDecorator*> m_shapes;
	std::vector<ShapeDecorator*> m_selectedShapes;
	bool m_move = false;
	sf::Vector2f m_cursorPosition, m_cursorOffset;
	std::stack<IMementoShape> m_stackHistory = std::stack<IMementoShape>{};
};