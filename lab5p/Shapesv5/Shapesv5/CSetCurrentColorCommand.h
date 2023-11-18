#pragma once
#include "ICommand.h"
#include "CUserInterface.h"

class CSetCurrentColorCommand : public ICommand
{
public:
	CSetCurrentColorCommand(CUserInterface* userInterface, sf::Color color);
	void Execute() override;
private:
	sf::Color m_color;
	CUserInterface* m_userInterface;
};