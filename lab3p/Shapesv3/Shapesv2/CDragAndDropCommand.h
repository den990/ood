#pragma once
#include "ICommand.h"
#include "CUserInterface.h"

class CDragAndDropCommand : public ICommand
{
public:
	CDragAndDropCommand(CUserInterface* userInterface);
	void Execute() override;
private:
	CUserInterface* m_userInterface;
};