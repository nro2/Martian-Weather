//martian_weather
//Nick Robinson

#include <iostream>

using namespace std;

#ifndef WEATHERDATA_H
#define WEATHERDATA_H

class WeatherData{

	public:

		WeatherData();

		void setTime(int tm);
		void setTemp(double tmp);
		void setWind(double wnd);
		
		int getTime();
		double getTemp();
		double getWind();
				
	private:

		int time;
		double temp;
		double wind;
		
};
#endif
