#include "CCreateTriangleCommand.h"

CCreateTriangleCommand::CCreateTriangleCommand(CUserInterface* userInterface)
	:m_userInterface(userInterface)
{
}

void CCreateTriangleCommand::Execute()
{
	std::string args = DEFAULT_TRIANGLE_FIRST_VERTEX_X + " " + DEFAULT_TRIANGLE_FIRST_VERTEX_Y +
		+" " + DEFAULT_TRIANGLE_SECOND_VERTEX_X + " " + DEFAULT_TRIANGLE_SECOND_VERTEX_Y +
		+" " + DEFAULT_TRIANGLE_THIRD_VERTEX_X + " " + DEFAULT_TRIANGLE_THIRD_VERTEX_Y +
		+" " + DEFAULT_TRIANGLE_OUTLINE_COLOR + " " + DEFAULT_TRIANGLE_FILL_COLOR;
	std::istringstream sstrm(args);
	m_userInterface->m_shapeHandler->CreateTriangle(sstrm);
}
