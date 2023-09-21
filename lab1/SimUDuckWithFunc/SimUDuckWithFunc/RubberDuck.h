#ifndef RUBBERDUCK_H
#define RUBBERDUCK_H

#include "Duck.h"
#include <iostream>

class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck(FlyNoWay, Squek, DanceNoWay)
	{
	}

	void Display() const override
	{
		std::cout << "I'm rubber duck" << std::endl;
	}

};

#endif
