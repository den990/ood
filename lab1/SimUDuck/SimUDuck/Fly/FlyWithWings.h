#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include "IFlyBehavior.h"
#include <iostream>

class FlyWithWings : public IFlyBehavior
{
public:
	void Fly() override
	{
		m_flyCount++;
		std::cout << "I'm flying with wings!!! Count: " << m_flyCount << std::endl;
	}
private:
	int m_flyCount = 0; //добавить класс полётов, с подсчётом, без дублирования
};

#endif
