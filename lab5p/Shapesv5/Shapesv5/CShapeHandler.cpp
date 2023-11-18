#include "CShapeHandler.h"

CShapeHandler::CShapeHandler()
{
	m_fileHandler = new CFileHandler(FILE_HANDLER_NAME, this, new CSaveText(), new CLoadText());
}

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
	shape->SetSelect(true);
	m_selectedShapes.push_back(shape);
	
}

void CShapeHandler::RemoveShapeInSelect(ShapeDecorator* shape)
{
	shape->SetSelect(false);
	auto it = std::find(m_selectedShapes.begin(), m_selectedShapes.end(), shape);
	m_selectedShapes.erase(it);

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
			SaveHistory(event);

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
			GroupShapes(event);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			UngroupShapes(event);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			Undo();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			SaveShapes();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		{
			LoadShapes();
		}
	}
}

void CShapeHandler::SaveShapes()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		if (m_fileHandler->GetTypeSave() != typeid(CSaveText).name())
		{
			m_fileHandler->m_saveIn = new CSaveText();
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		if (m_fileHandler->GetTypeSave() != typeid(CSaveBinary).name())
		{
			m_fileHandler->m_saveIn = new CSaveBinary();
		}
	}
	m_fileHandler->Save();

}

void CShapeHandler::RestoreState(const IMementoShape& shapeMemento)
{
	m_shapes = shapeMemento.m_shapes;
	m_selectedShapes = shapeMemento.m_selectedShapes;

	m_cursorPosition = { 0, 0 };
	m_cursorOffset = { 0, 0 };
	m_move = false;
}

void CShapeHandler::LoadShapes()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		if (m_fileHandler->GetTypeImport() != typeid(CLoadText).name())
		{
			m_fileHandler->m_importFrom = new CLoadText();
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		if (m_fileHandler->GetTypeImport() != typeid(CLoadBinary).name())
		{
			m_fileHandler->m_importFrom = new CLoadBinary();
		}
	}
	m_fileHandler->Import();
}

std::vector<ShapeDecorator*> CShapeHandler::GetShapes() const
{
	return m_shapes;
}

void CShapeHandler::NotMove() 
{
	m_move = false;
}

void CShapeHandler::GroupShapes(sf::Event& event)
{
	if (m_selectedShapes.size() > 1)
	{
		SaveHistory(event);

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

void CShapeHandler::UngroupShapes(sf::Event& event)
{
	if (m_selectedShapes.size() == 1 && dynamic_cast<CShapeComposite*>(m_selectedShapes.back()))
	{
		SaveHistory(event);

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

void CShapeHandler::Undo()
{
	if (m_stackHistory.size() > 0)
	{
		SetPreviousState(m_stackHistory.top());
		m_stackHistory.pop();
	}

}

void CShapeHandler::SaveHistory(sf::Event& event)
{
	std::vector<ShapeDecorator*> copyShapes = CopyShapes(m_shapes);
	std::vector<ShapeDecorator*> copySelectedShapes;
	std::vector<std::pair<ShapeDecorator*, sf::Vector2f>> previousPositions;
	std::vector<std::pair<ShapeDecorator*, sf::Color>> shapeColors;
	std::vector<std::pair<ShapeDecorator*, float>> edgeWidths;
	std::vector<std::pair<ShapeDecorator*, sf::Color>> edgeColors;

	for (auto shape : copyShapes)
	{
		if (shape->GetSelect() || shape->IsPointInShape({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			copySelectedShapes.push_back(shape);
			previousPositions.emplace_back(shape, shape->GetPosition());
			shapeColors.emplace_back(shape, shape->GetColor());
			edgeWidths.emplace_back(shape, shape->GetEdgeWidth());
			edgeColors.emplace_back(shape, shape->GetEdgeColor());
		}
	}

	IMementoShape mementoShape = IMementoShape(copyShapes, copySelectedShapes, previousPositions, shapeColors, edgeWidths, edgeColors);
	m_stackHistory.push(mementoShape);
}


void CShapeHandler::SetPreviousState(const IMementoShape& state)
{
	m_shapes = state.m_shapes;
	m_selectedShapes = state.m_selectedShapes;

	for (const auto& pair : state.m_previousPositions)
	{
		pair.first->SetPosition(pair.second);
	}

	for (const auto& pair : state.m_shapeColors)
	{
		pair.first->SetFillColor(pair.second);
	}

	for (const auto& pair : state.m_edgeWidths)
	{
		pair.first->SetOutlineThickness(pair.second);
	}

	for (const auto& pair : state.m_edgeColors)
	{
		pair.first->SetOutlineColor(pair.second);
	}

	m_cursorOffset = { 0, 0 };
	m_cursorPosition = { 0, 0 };
	m_move = false;
}



void CShapeHandler::Accept(IVisitor* visitor, sf::Event event)
{
	for (const auto& shape : m_shapes)
	{
		if (shape->IsPointInShape({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
		{
			SaveHistory(event);

			visitor->VisiteShape(shape);
			break;
		}
	}
}

std::vector<ShapeDecorator*> CShapeHandler::CopyShapes(std::vector<ShapeDecorator*> shapes)
{
	std::vector<ShapeDecorator*> copyShapes;

	for (const auto& shape : shapes)
	{
		if (typeid(*shape) == typeid(CCircle))
		{
			CCircle* circleDecorator = new CCircle(*(CCircle*)shape);
			copyShapes.push_back(circleDecorator);
		}
		else if (typeid(*shape) == typeid(CTriangle))
		{
			CTriangle* triangleDecorator = new CTriangle(*(CTriangle*)shape);
			copyShapes.push_back(triangleDecorator);
		}
		else if (typeid(*shape) == typeid(CRectangle))
		{
			CRectangle* rectangleDecorator = new CRectangle(*(CRectangle*)shape);
			copyShapes.push_back(rectangleDecorator);
		}
		else if (typeid(*shape) == typeid(CShapeComposite))
		{
			CShapeComposite* compositeShapeDecorator = new CShapeComposite(*(CShapeComposite*)shape);
			copyShapes.push_back(compositeShapeDecorator);
		}
	}

	return copyShapes;
}
