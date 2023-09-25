#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "Observer.h"
#include <string>

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

struct Stats
{
	double minValue = std::numeric_limits<double>::infinity();
	double maxValue = -std::numeric_limits<double>::infinity();
	double accValue = 0;
};

class CDisplay : public IObserver<SWeatherInfo>
{
	void Update(const SWeatherInfo& data, const IObservable<SWeatherInfo>& observable) override
	{
		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Hum " << data.humidity << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
	}
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/

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

class CStatisticData
{
public:

	void Update(double data)
	{
		if (m_min > data)
		{
			m_min = data;
		}

		if (m_max < data)
		{
			m_max = data;
		}

		m_sum += data;
		m_count++;
	}

	std::string DisplayStats(std::string text)
	{
		return "Max " + text + " " + std::to_string(m_max) + "\n"
			+ "Min " + text + " " + std::to_string(m_min) + "\n"
			+ "Average " + text + " " + std::to_string(m_sum / m_count) + "\n"
			+ "----------------";
	}


private:
	double m_min = std::numeric_limits<double>::infinity();
	double m_max = -std::numeric_limits<double>::infinity();
	double m_sum = 0;
	unsigned m_count = 0;
};


class CStats
{
public:
	void UpdateStats(const SWeatherInfo& data)
	{
		m_temperature.Update(data.temperature);
		m_humidity.Update(data.humidity);
		m_pressure.Update(data.pressure);
	}
	void DisplayStats(std::ostream& out)
	{
		out << m_temperature.DisplayStats("temperature") << std::endl;
		out << m_humidity.DisplayStats("humidity") << std::endl;
		out << m_pressure.DisplayStats("pressure") << std::endl;
	}
private:
	CStatisticData m_temperature;
	CStatisticData m_humidity;
	CStatisticData m_pressure;
};


class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay(const CWeatherData& observerIn, const CWeatherData& observerOut, std::ostream& output)
		: m_observerIn(observerIn)
		, m_observerOut(observerOut)
		, m_out(output)
	{};
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/

	void Update(const SWeatherInfo& data, const IObservable<SWeatherInfo>& observable) override
	{
		

		if (&observable == &m_observerIn)
		{
			m_statisticOfInObserver.UpdateStats(data);
			m_statisticOfInObserver.DisplayStats(m_out);
		}

		if (&observable == &m_observerOut)
		{
			m_statisticOfOutObserver.UpdateStats(data);
			m_statisticOfOutObserver.DisplayStats(m_out);
		}
	}


	const CWeatherData& m_observerIn;
	const CWeatherData& m_observerOut;
	CStats m_statisticOfInObserver;
	CStats m_statisticOfOutObserver;
	std::ostream& m_out;
};


