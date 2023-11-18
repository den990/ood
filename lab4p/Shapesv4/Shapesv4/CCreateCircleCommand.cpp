#include "CCreateCircleCommand.h"

CCreateCircleCommand::CCreateCircleCommand(CUserInterface* userInterface)
	:m_userInterface(userInterface)
{
}

void CCreateCircleCommand::Execute()
{
	std::string args = DEFAULT_CIRCLE_CENTER_POINT_X + " " + DEFAULT_CIRCLE_CENTER_POINT_Y + " " + DEFAULT_CIRCLE_RADIUS +
		+" " + DEFAULT_CIRCLE_OUTLINE_COLOR + " " + DEFAULT_CIRCLE_FILL_COLOR;
	std::istringstream sstrm(args);
	m_userInterface->m_shapeHandler->CreateCircle(sstrm);
}
