//martian_weather
//Nick Robinson

#include <iostream>
#include <cstring>
#include "weatherdata.h"

WeatherData::WeatherData()
{
	temp = 0;
	time = 0;
	wind = 0;
}

void WeatherData::setTime(int tm)
{
	time = tm;
}

void WeatherData::setTemp(double tmp)
{
	temp = tmp;
}

void WeatherData::setWind(double wnd)
{
	wind = wnd;
}

int WeatherData::getTime()
{
	return time;
}

double WeatherData::getTemp()
{
	return temp;
}

double WeatherData::getWind()
{
	return wind;
}


