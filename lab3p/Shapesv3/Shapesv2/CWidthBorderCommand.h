#pragma once
#include "ICommand.h"
#include "CUserInterface.h"

class CWidthBorderCommand : public ICommand
{
public:
	CWidthBorderCommand(CUserInterface* userInterface);
	void Execute() override;
private:
	CUserInterface* m_userInterface;
};