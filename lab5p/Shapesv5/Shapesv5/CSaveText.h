#pragma once
#include "CSave.h"

class CSaveText : public CSave
{
public:
	void Save(std::string& fileName, std::vector<ShapeDecorator*> shapes) override;
};