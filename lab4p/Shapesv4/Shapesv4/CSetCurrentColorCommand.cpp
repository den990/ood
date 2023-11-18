#include "CSetCurrentColorCommand.h"

CSetCurrentColorCommand::CSetCurrentColorCommand(CUserInterface* userInterface, sf::Color color)
	:m_userInterface(userInterface)
	,m_color(color)
{
}

void CSetCurrentColorCommand::Execute()
{
	m_userInterface->SetCurrentColor(m_color);
}
