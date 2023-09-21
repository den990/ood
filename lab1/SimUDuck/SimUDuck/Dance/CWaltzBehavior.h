#pragma once
#include <iostream>
#include "IDanceBehavior.h"

class CWaltzBehavior : public IDanceBehavior
{
public:
	void Dance() override {
		std::cout << "I\'m dance waltz" << std::endl;
	}
};