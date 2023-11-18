#include "CSetCurrentWidthCommand.h"

CSetCurrentWidthCommand::CSetCurrentWidthCommand(CUserInterface* userInterface, float width)
	:m_userInterface(userInterface)
	,m_width(width)
{
}

void CSetCurrentWidthCommand::Execute()
{
	m_userInterface->SetCurrentWidth(m_width);
}