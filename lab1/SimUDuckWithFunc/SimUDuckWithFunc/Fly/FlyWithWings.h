#pragma once
#include <iostream>
#include <functional>

using FlyBehavior = std::function<void()>;


FlyBehavior MakeFlyWithWings() 
{
	return [flightCount = 0]() mutable->void {
		std::cout << "I'm flying with wings!!! Count: " << ++flightCount << std::endl;
	};
}

