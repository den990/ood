#pragma once
#include "CSave.h"

class CSaveBinary : public CSave
{
public:
	void Save(std::string& fileName, std::vector<ShapeDecorator*> shapes) override;
};