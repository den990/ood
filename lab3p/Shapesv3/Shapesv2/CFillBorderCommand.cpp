#include "CFillBorderCommand.h"

CFillBorderCommand::CFillBorderCommand(CUserInterface* userInterface)
	:m_userInterface(userInterface)
{
}

void CFillBorderCommand::Execute()
{
	m_userInterface->FillBorder();
}
