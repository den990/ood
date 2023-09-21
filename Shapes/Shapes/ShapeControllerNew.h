#pragma once
#include "Result.h"
#include <iostream>
#include <algorithm>
class ShapeController
{
public:
	ShapeController(std::istream& input, std::ostream& output);
	void Start();
	Result ValidationCommand(std::string& inputCommand);
private:
	std::ostream& m_output;
	std::istream& m_input;
};