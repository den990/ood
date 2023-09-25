#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../WeatherStationDuo/Observer.h"
#include "../WeatherStationDuo/WeatherData.h"

TEST_CASE("")
{
	std::ostringstream oss;

	CWeatherData weatherDataIn;
	CWeatherData weatherDataOut;

	CStatsDisplay display(weatherDataIn, weatherDataOut, oss);

	weatherDataIn.RegisterObserver(display, 0);
	weatherDataOut.RegisterObserver(display, 0);

	weatherDataIn.SetMeasurements(3, 0.7, 760);
	weatherDataOut.SetMeasurements(5, 0.24, 780);
	std::stringstream expectedString;

	expectedString << "Max temperature 3.000000" << "\n" <<
		"Min temperature 3.000000" << "\n" <<
		"Average temperature 3.000000" << "\n" <<
		"----------------" << "\n" <<
		"Max humidity 0.700000" << "\n" <<
		"Min humidity 0.700000" << "\n" <<
		"Average humidity 0.700000" << "\n" <<
		"----------------" << "\n" <<
		"Max pressure 760.000000" << "\n" <<
		"Min pressure 760.000000" << "\n" <<
		"Average pressure 760.000000" << "\n" <<
		"----------------" << "\n" <<
		"Max temperature 5.000000" << "\n" <<
		"Min temperature 5.000000" << "\n" <<
		"Average temperature 5.000000" << "\n" <<
		"----------------" << "\n" <<
		"Max humidity 0.240000" << "\n" <<
		"Min humidity 0.240000" << "\n" <<
		"Average humidity 0.240000" << "\n" <<
		"----------------" << "\n" <<
		"Max pressure 780.000000" << "\n" <<
		"Min pressure 780.000000" << "\n" <<
		"Average pressure 780.000000" << "\n" <<
		"----------------" << "\n";
	
	REQUIRE(oss.str() == expectedString.str());

	weatherDataIn.SetMeasurements(10, 0.24, 751);
	weatherDataOut.SetMeasurements(2, 0.9, 720);

	expectedString << 
		"Max temperature 10.000000" << "\n" <<
		"Min temperature 3.000000" << "\n" <<
		"Average temperature 6.500000" << "\n" <<
		"----------------" << "\n" <<
		"Max humidity 0.700000" << "\n" <<
		"Min humidity 0.240000" << "\n" <<
		"Average humidity 0.470000" << "\n" <<
		"----------------" << "\n" <<
		"Max pressure 760.000000" << "\n" <<
		"Min pressure 751.000000" << "\n" <<
		"Average pressure 755.500000" << "\n" <<
		"----------------" << "\n" <<
		"Max temperature 5.000000" << "\n" <<
		"Min temperature 2.000000" << "\n" <<
		"Average temperature 3.500000" << "\n" <<
		"----------------" << "\n" <<
		"Max humidity 0.900000" << "\n" <<
		"Min humidity 0.240000" << "\n" <<
		"Average humidity 0.570000" << "\n" <<
		"----------------" << "\n" <<
		"Max pressure 780.000000" << "\n" <<
		"Min pressure 720.000000" << "\n" <<
		"Average pressure 750.000000" << "\n" <<
		"----------------" << "\n";

	REQUIRE(oss.str() == expectedString.str());
}