#pragma once
#include "CLoad.h"

class CLoadText : public CLoad
{
public:
	IMementoShape Import(std::string fileName) override;
};