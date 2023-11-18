#pragma once
#include "CLoad.h"

class CLoadBinary : public CLoad
{
public:
	IMementoShape Import(std::string fileName) override;
};