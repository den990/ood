#pragma once
#include "ICommand.h"
#include "CUserInterface.h"

class CSetCurrentWidthCommand : public ICommand
{
public:
	CSetCurrentWidthCommand(CUserInterface* userInterface, float width);
	void Execute() override;
private:
	float m_width;
	CUserInterface* m_userInterface;
};