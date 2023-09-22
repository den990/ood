#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../WeatherStation2/Observer.h"
#include "../WeatherStation2/WeatherData.h"
TEST_CASE("Test with Remove")
{
    CWeatherData wd;
    CDisplay display;
    CStatsDisplay statsDisplay;
    CStatsDisplay statsDisplay2;

    wd.RegisterObserver(display);
    wd.RegisterObserver(statsDisplay);
    wd.RegisterObserver(statsDisplay2);

    SECTION("Remove observer during update") {
        // Устанавливаем начальные значения
        wd.SetMeasurements(3, 0.7, 760);
        wd.SetMeasurements(4, 0.8, 761);

        // Удаляем одного из наблюдателей во время обновления
        wd.RemoveObserver(statsDisplay);

        // Устанавливаем новые значения
        wd.SetMeasurements(10, 0.8, 761);
        wd.SetMeasurements(-10, 0.8, 761);

        // В данном случае statsDisplay больше не должен получать обновления
        REQUIRE(statsDisplay.GetMinTemperature() == 3.0);
        REQUIRE(statsDisplay.GetMaxTemperature() == 10.0);
        REQUIRE(statsDisplay.GetMinHumidity() == 0.7);
        REQUIRE(statsDisplay.GetMaxHumidity() == 0.8);
        REQUIRE(statsDisplay.GetMinPressure() == 760.0);
        REQUIRE(statsDisplay.GetMaxPressure() == 761.0);
    }

    SECTION("No observer removal during update") {
        // Устанавливаем начальные значения
        wd.SetMeasurements(3, 0.7, 760);
        wd.SetMeasurements(4, 0.8, 761);

        // Устанавливаем новые значения без удаления наблюдателей
        wd.SetMeasurements(10, 0.8, 761);
        wd.SetMeasurements(-10, 0.8, 761);

        // Все наблюдатели должны получить обновления
        REQUIRE(statsDisplay.GetMinTemperature() == -10.0);
        REQUIRE(statsDisplay.GetMaxTemperature() == 10.0);
        REQUIRE(statsDisplay.GetMinHumidity() == 0.7);
        REQUIRE(statsDisplay.GetMaxHumidity() == 0.8);
        REQUIRE(statsDisplay.GetMinPressure() == 760.0);
        REQUIRE(statsDisplay.GetMaxPressure() == 761.0);
    }

}
