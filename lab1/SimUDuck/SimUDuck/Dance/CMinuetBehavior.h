#pragma once
#include <iostream>
#include "IDanceBehavior.h"

class CMinuetBehavior : public IDanceBehavior
{
	void Dance() override {
		std::cout << "I\'m dance minuet" << std::endl;
	}
};