#include "CWidthBorderCommand.h"

CWidthBorderCommand::CWidthBorderCommand(CUserInterface* userInterface)
	:m_userInterface(userInterface)
{
}

void CWidthBorderCommand::Execute()
{
	m_userInterface->WidthBorder();
}