#pragma once
#include "ICommand.h"
#include "CUserInterface.h"

class CCreateRectangleCommand : public ICommand
{
public:
	CCreateRectangleCommand(CUserInterface* userInterface);
	void Execute() override;
private:
	CUserInterface* m_userInterface;
};