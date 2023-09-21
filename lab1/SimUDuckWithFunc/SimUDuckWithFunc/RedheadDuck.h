#ifndef REDHEADDUCK_H
#define REDHEADDUCK_H

#include "Duck.h"

#include <memory>

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(MakeFlyWithWings(), quack, DanceMinuet)
	{
	}

	void Display() const override
	{
		std::cout << "I'm redhead duck" << std::endl;
	}
};

#endif
