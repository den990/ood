#include "CCreateRectangleCommand.h"

CCreateRectangleCommand::CCreateRectangleCommand(CUserInterface* userInterface)
	:m_userInterface(userInterface)
{
}

void CCreateRectangleCommand::Execute()
{
	std::string args = DEFAULT_RECTANGLE_LEFT_TOP_X + " " + DEFAULT_RECTANGLE_LEFT_TOP_Y + " " + DEFAULT_RECTANGLE_WIDTH + " " + DEFAULT_RECTANGLE_HEIGHT +
		+" " + DEFAULT_RECTANGLE_OUTLINE_COLOR + " " + DEFAULT_RECTANGLE_FILL_COLOR;
	std::istringstream sstrm(args);
	m_userInterface->m_shapeHandler->CreateRectangle(sstrm);
}
