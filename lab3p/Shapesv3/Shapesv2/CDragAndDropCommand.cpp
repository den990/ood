#include "CDragAndDropCommand.h"

CDragAndDropCommand::CDragAndDropCommand(CUserInterface* userInterface)
	:m_userInterface(userInterface)
{
}

void CDragAndDropCommand::Execute()
{
	m_userInterface->DragAndDrop();
}
