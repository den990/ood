#include "CShapeController.h"
const std::string NAME_WINDOW = "Shape";
const std::string INPUT_FILE_NAME = "input.txt";
const std::string OUTPUT_FILE_NAME = "output.txt";
const std::string TYPE_RECTANGLE = "RECTANGLE:";
const std::string TYPE_CIRCLE = "CIRCLE:";
const std::string TYPE_TRIANGLE = "TRIANGLE:";
const std::string ERROR_WRITE_FILE = "Error, failed to write data to file";

CShapeController::CShapeController()
	: m_window(sf::VideoMode(1800, 900), NAME_WINDOW)
	,m_actionMap({
		  { "CIRCLE", [this](std::istringstream& args) {
			   return m_shapeHandler->CreateCircle(args);
		   } },
		  { "TRIANGLE", [this](std::istringstream& args) {
			   return m_shapeHandler->CreateTriangle(args);
		   } },
		  { "RECTANGLE", [this](std::istringstream& args) {
			   return m_shapeHandler->CreateRectangle(args);
		   } }
		})
{
	m_shapeHandler = new CShapeHandler();
	m_userInterface = new CUserInterface(new CDragAndDropState(), m_window, m_shapeHandler);
}

void CShapeController::Start()
{
	ReadFileAndFillData(INPUT_FILE_NAME);

	while (m_window.isOpen())
	{
		sf::Event event;
		if (m_window.waitEvent(event))
		{
			auto position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window));
			m_shapeHandler->SetCursorPosition(position);

			switch (event.type)
			{
			case sf::Event::Closed:
			{
				m_window.close();
				break;
			}
			case sf::Event::MouseButtonPressed:
			{
				if (typeid(*m_userInterface->GetState()) == typeid(CDragAndDropState))
				{
					m_shapeHandler->DragAndDrop(event);
				}
				else if (typeid(*m_userInterface->GetState()) == typeid(CFillShapeState))
				{
					m_shapeHandler->Accept(new CFillShapeVisitor(m_userInterface->GetCurrentColor()), event);
				}
				else if (typeid(*m_userInterface->GetState()) == typeid(CFillBorderState))
				{
					m_shapeHandler->Accept(new CFillBorderVisitor(m_userInterface->GetCurrentColor()), event);
				}
				else if (typeid(*m_userInterface->GetState()) == typeid(CWidthBorderState))
				{
					m_shapeHandler->Accept(new CWidthBorderVisitor(m_userInterface->GetCurrentWidth()), event);
				}

				auto buttons = m_userInterface->GetButtons();
				for (const auto& button : buttons)
				{
					if (button->IsPointInButton({ (float)event.mouseButton.x, (float)event.mouseButton.y }))
					{
						button->PressButton();
						break;
					}
				}

				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				m_shapeHandler->NotMove();
				break;
			}
			case sf::Event::KeyPressed:
			{
				m_shapeHandler->HandleKey(event);
				break;
			}
			}
		}
		m_shapeHandler->Moving();
		Draw();
	}

	WriteData(OUTPUT_FILE_NAME);
}



void CShapeController::Draw()
{
	m_window.clear();

	DrawUserInterface();
	DrawShapes();

	m_window.display();
}

void CShapeController::DrawShapes()
{
	auto shapes = m_shapeHandler->GetShapes();
	for (const auto& shape : shapes)
	{
		shape->Draw(m_window);
	}
}

void CShapeController::DrawUserInterface() const
{
	m_userInterface->Draw();
}


void CShapeController::ReadFileAndFillData(const std::string& fileName)
{
	std::ifstream fileInput(fileName);
	std::string commandLine;

	while (getline(fileInput, commandLine))
	{
		std::istringstream sstrm(commandLine);

		std::string action;
		sstrm >> action;

		auto it = m_actionMap.find(action);
		if (it != m_actionMap.end())
		{
			it->second(sstrm);
		}
	}
}




void CShapeController::WriteData(const std::string& fileName)
{
	std::ofstream output(fileName);
	if (!output)
	{
		output << ERROR_WRITE_FILE << std::endl;
		return;
	}
	auto shapes = m_shapeHandler->GetShapes();
	for (const auto& shape : shapes)
	{
		output << shape->ToString() << std::endl;
	}
}