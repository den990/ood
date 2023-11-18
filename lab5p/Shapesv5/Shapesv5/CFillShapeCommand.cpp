#include "CFillShapeCommand.h"

CFillShapeCommand::CFillShapeCommand(CUserInterface* userInterface)
	:m_userInterface(userInterface)
{
}

void CFillShapeCommand::Execute()
{
	m_userInterface->FillShape();
}