#include "ShapeControllerNew.h"
ShapeController::ShapeController(std::istream& input, std::ostream& output)
	:m_input(input)
	,m_output(output)
{
}

void ShapeController::Start()
{
	m_output << "Please enter command: AddShape <id> <color> <type> <parameters>" << std::endl;
	std::string inputCommand;
	getline(m_input, inputCommand);
	Result result;
	if ((result = ValidationCommand(inputCommand)).status == Status::ERROR)
	{
		m_output << result.errorMessage << std::endl;
	}
}

Result ShapeController::ValidationCommand(std::string& inputCommand)
{
	std::transform(inputCommand.begin(), inputCommand.end(), inputCommand.begin(), std::tolower);
	std::string command, id, color, type, parameters;
	std::istringstream iss(inputCommand);
	iss >> command >> id >> color >> type;
	if (command != "AddShape" || id.empty() || color.empty() || type.empty()) 
	{
		return { Status::ERROR, "Invalid command format. Usage: AddShape <id> <color> <type> <parameters>" };
	}
	else 
	{

		getline(iss, parameters); // мб убрать
		return { Status::OK };
	}
}


