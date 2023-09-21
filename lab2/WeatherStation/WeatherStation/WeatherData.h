#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "Observer.h"

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class CDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Hum " << data.humidity << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
	}
};

struct Stats
{
	double minValue = std::numeric_limits<double>::infinity();
	double maxValue = -std::numeric_limits<double>::infinity();
	double accValue = 0;
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void UpdateStats(const double current, Stats& data)
	{
		if (data.minValue > current)
		{
			data.minValue = current;
		}
		if (data.maxValue < current)
		{
			data.maxValue = current;
		}
		data.accValue += current;
	}
	void DisplayStats(Stats& data, const char* text)
	{
		std::cout << "Max " << text << " " << data.maxValue << std::endl;
		std::cout << "Min " << text << " " << data.minValue << std::endl;
		std::cout << "Average " << text << " " << data.accValue / m_countAcc << std::endl;
		std::cout << "----------------" << std::endl;
	}
	void Update(SWeatherInfo const& data) override
	{
		UpdateStats(data.temperature, m_temperature);
		UpdateStats(data.humidity, m_humidity);
		UpdateStats(data.pressure, m_pressure);
		++m_countAcc;

		DisplayStats(m_temperature, "temperature");
		DisplayStats(m_humidity, "humidity");
		DisplayStats(m_pressure, "pressure");
	}

	Stats m_temperature;
	Stats m_humidity;
	Stats m_pressure;
	unsigned m_countAcc = 0;
};

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	// Температура в градусах Цельсия
	double GetTemperature()const
	{
		return m_temperature;
	}
	// Относительная влажность (0...100)
	double GetHumidity()const
	{
		return m_humidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure()const
	{
		return m_pressure;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;

		MeasurementsChanged();
	}
protected:
	SWeatherInfo GetChangedData()const override
	{
		SWeatherInfo info;
		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		return info;
	}
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;
};
