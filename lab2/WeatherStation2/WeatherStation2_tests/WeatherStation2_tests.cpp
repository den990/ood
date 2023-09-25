#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../WeatherStation2/WeatherData.h"
#include "../WeatherStation2/CDestructionObserver.h"
TEST_CASE("Test with Remove")
{
    SECTION("Remove observer during update") {
        CWeatherData weatherData;
        CDestructionTestObserver destructionTestObserver(weatherData);

        weatherData.RegisterObserver(destructionTestObserver);
        weatherData.SetMeasurements(0, 0, 770);
    }

}
