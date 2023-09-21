#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "Duck.h"

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(MakeFlyWithWings(), quack, DanceWaltz)
	{
	}

	void Display() const override
	{
		std::cout << "I'm mallard duck" << std::endl;
	}
};

#endif
