//Martian Weather
//Nick Robinson

#include <iostream>
#include "linkedList.h"
#include "weatherdata.h"

using namespace std;

#ifndef DATALOGGER_H
#define DATALOGGER_H

//linkedList dupe;
//linkedList main;

class datalogger {

	

	public:
		datalogger();
		~datalogger();
		void addData(int time, double temp, double wind);
		void printReport();
		
	private:
		LinkedList main;
		LinkedList dupe;
		
};

#endif
