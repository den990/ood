#include <iostream>
#include "Observer.h"
#include "WeatherData.h"
int main()
{
    CWeatherData weatherData;
    CWeatherDataPro weatherDataPro;
    CStatsDisplay display(weatherData, weatherDataPro, std::cout);

    weatherDataPro.RegisterObserver(display, 0);

    weatherDataPro.SetMeasurements(3, 0.7, 760, 180, 2);

    weatherDataPro.SetMeasurements(5, 0.32, 750, 190, 9);

}

