#pragma once
#include <sstream>

enum class Status
{
	OK,
	ERROR
};

struct Result
{
	Status status;
	std::string errorMessage;
};