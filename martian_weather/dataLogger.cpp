//martian_weather
//Nick Robinson

#include "linkedList.h"
#include "weatherdata.h"
#include <iostream>
#include <cstring>
#include "datalogger.h"

using namespace std;

datalogger::datalogger()
{
}

datalogger::~datalogger()
{
}

void datalogger::addData(int time, double temp, double wind)
{
		
        bool check = dupe.checkDupe(time);
	bool check2 = main.checkMain(time);

	
	if(check == 0)
	{
		if(check2 == 0)
		{
		main.addTime(time, temp, wind);
		}
		else
		{
		dupe.addToDupe(time);
		}
	}
}	



void datalogger::printReport()
{
	main.printAll();
}


