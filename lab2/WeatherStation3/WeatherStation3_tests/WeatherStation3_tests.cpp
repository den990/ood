#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../WeatherStation3/WeatherData.h"
#include "../WeatherStation3/CPriorityObserver.h"
#include <sstream>

TEST_CASE("Testing with priority")
{
	std::ostringstream oss;
	CWeatherData weatherData;

	CPriorityTestObserver firstObserver(1, oss);
	CPriorityTestObserver secondObserver(2, oss);
	CPriorityTestObserver thirdObserver(3, oss);
	CPriorityTestObserver fourthObserver(4, oss);

	weatherData.RegisterObserver(firstObserver, 2);
	weatherData.RegisterObserver(secondObserver, 0);
	weatherData.RegisterObserver(thirdObserver, 1);
	weatherData.RegisterObserver(fourthObserver, 3);

	weatherData.SetMeasurements(10, 10, 720);

	REQUIRE(oss.str() == "4132");
}

