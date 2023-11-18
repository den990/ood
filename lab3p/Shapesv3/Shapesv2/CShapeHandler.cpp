#include "CShapeHandler.h"

void CShapeHandler::CreateCircle(std::istringstream& args)
{
	CCircleCreator creator;
	ShapeDecorator* circle = creator.CreateShape(args);
	m_shapes.push_back(circle);
}

void CShapeHandler::CreateTriangle(std::istringstream& args)
{
	CTriangleCreator creator;
	ShapeDecorator* triangle = creator.CreateShape(args);
	m_shapes.push_back(triangle);
}

void CShapeHandler::CreateRectangle(std::istringstream& args)
{
	CRectangleCreator creator;
	ShapeDecorator* rectangle = creator.CreateShape(args);
	m_shapes.push_back(rectangle);
}

void CShapeHandler::HandleMouse(sf::Event event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		for (const auto& shape : m_shapes)
		{
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				for (const auto& shape : m_selectedShapes)
				{
					ClearSelectedShapes(shape); // написать функцию для очищения
				}
			}
			if (shape->IsPointInShape({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
			{
				if (shape->GetSelect())
				{
					RemoveShapeInSelect(shape);
				}
				else
				{
					AddShapeInSelect(shape);
				}
				break;
			}
		}
	}
}

void CShapeHandler::AddShapeInSelect(ShapeDecorator* shape)
{
	m_selectedShapes.push_back(shape);
	shape->SetSelect(true);
}

void CShapeHandler::RemoveShapeInSelect(ShapeDecorator* shape)
{
	auto it = std::find(m_selectedShapes.begin(), m_selectedShapes.end(), shape);
	m_selectedShapes.erase(it);
	shape->SetSelect(false);
}

void CShapeHandler::ClearSelectedShapes(ShapeDecorator* shape)
{
	shape->SetSelect(false);
	m_selectedShapes.clear();
}

void CShapeHandler::PreparingForMove(sf::Event event)
{
	for (const auto& shape : m_shapes)
	{
		if (shape->IsPointInShape({ (float)event.mouseButton.x, (float)event.mouseButton.y }) && shape->GetSelect())
		{
			m_move = true;
			m_cursorOffset.x = m_cursorPosition.x - shape->GetPosition().x;
			m_cursorOffset.y = m_cursorPosition.y - shape->GetPosition().y;
			break;
		}
	}

}

void CShapeHandler::Moving() const
{
	if (m_selectedShapes.size() == 1 && m_move)
	{
		m_selectedShapes.back()->SetPosition({
			m_cursorPosition.x - m_cursorOffset.x,
			m_cursorPosition.y - m_cursorOffset.y
			});
	}
}

void CShapeHandler::SetCursorPosition(sf::Vector2f position)
{
	m_cursorPosition = position;
}

void CShapeHandler::DragAndDrop(sf::Event event)
{
	HandleMouse(event);
	PreparingForMove(event);
}

void CShapeHandler::HandleKey(sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			GroupShapes();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			UngroupShapes();
		}
	}
}

std::vector<ShapeDecorator*> CShapeHandler::GetShapes() const
{
	return m_shapes;
}

void CShapeHandler::NotMove() 
{
	m_move = false;
}

void CShapeHandler::GroupShapes()
{
	if (m_selectedShapes.size() > 1)
	{

		CShapeComposite* compositeShape = new CShapeComposite();

		std::vector<ShapeDecorator*> copySelectedShapes = m_selectedShapes;

		for (const auto& shape : copySelectedShapes)
		{
			compositeShape->Add(shape);
			auto it = find(m_shapes.begin(), m_shapes.end(), shape);
			m_shapes.erase(it);
			RemoveShapeInSelect(shape);
		}

		AddShapeInSelect(compositeShape);
		m_shapes.push_back(compositeShape);
	}
}

void CShapeHandler::UngroupShapes()
{
	if (m_selectedShapes.size() == 1 && dynamic_cast<CShapeComposite*>(m_selectedShapes.back()))
	{

		CShapeComposite* compositeShape = static_cast<CShapeComposite*>(m_selectedShapes.back());

		std::vector<ShapeDecorator*> compositeShapes = compositeShape->GetShapes();

		auto it = find(m_shapes.begin(), m_shapes.end(), m_selectedShapes.back());
		m_shapes.erase(it);
		RemoveShapeInSelect(m_selectedShapes.back());

		for (const auto& shape : compositeShapes)
		{
			AddShapeInSelect(shape);
			m_shapes.push_back(shape);
		}
	}
}

void CShapeHandler::FillShape(sf::Event event, sf::Color color)
{
	for (const auto& shape : m_shapes)
	{
		if (shape->IsPointInShape({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			shape->SetFillColor(color);
		}
	}
}

void CShapeHandler::FillOutlineColor(sf::Event event, sf::Color color)
{
	for (const auto& shape : m_shapes)
	{
		if (shape->IsPointInShape({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			shape->SetOutlineColor(color);
		}
	}
}

void CShapeHandler::SetOutlineThickness(sf::Event event, float width)
{
	for (const auto& shape : m_shapes)
	{
		if (shape->IsPointInShape({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			shape->SetOutlineThickness(width);
		}
	}
}
