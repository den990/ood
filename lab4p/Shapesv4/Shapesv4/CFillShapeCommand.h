#pragma once
#include "ICommand.h"
#include "CUserInterface.h"

class CFillShapeCommand : public ICommand
{
public:
	CFillShapeCommand(CUserInterface* userInterface);
	void Execute() override;
private:
	CUserInterface* m_userInterface;
};