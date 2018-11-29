//Martian Weather
//Nick Robinson

#include <iostream>
#include "weatherdata.h"

using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node
{

	WeatherData *data;
	Node *nextTime;
	Node *nextTemp;
	Node *nextWind;
	Node *nextDupe;
};

class LinkedList
{

	private:
		Node *headTime;
		Node *headTemp;
		Node *headWind;
		Node *headDupe;
		int count;
		int size;
		int timeMin;
		int timeMax;
		double tempMin;
		double tempMax;
		double windMin;
		double windMax;
		
						
	public:

		LinkedList();
		~LinkedList();

		void addTime(int time, double temp, double wind);
		void orderTemp(Node *newNode, double temp);
		void orderWind(Node *newNode, double wind);
		bool checkMain(int time);
		void addToDupe(int time);
		bool checkDupe(int time);
		void timeRange();
		void windRange();
		void tempRange();
		void counter();
		void topTemp();
		void botTemp();
		void topWind();
		void botWind();
		void printAll();
		void delWind(int time);
		void delTemp(int temp);
		void delDupe();
};

#endif
