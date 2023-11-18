#pragma once
#include "ICommand.h"
#include "CUserInterface.h"

class CFillBorderCommand : public ICommand
{
public:
	CFillBorderCommand(CUserInterface* userInterface);
	void Execute() override;
private:
	CUserInterface* m_userInterface;
};