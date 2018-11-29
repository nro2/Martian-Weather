//Martian Weather
//Nick Robinson

#include "linkedList.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;

LinkedList::LinkedList()
{
	WeatherData data;
	headTime = NULL;
	headTemp = NULL;
	headWind = NULL;
	headDupe = NULL;
	count = 0;
	timeMin = 0;
	timeMax = 0;
	tempMin = 0;
	tempMax = 0;
	windMin = 0;
	windMax = 0;
}

LinkedList::~LinkedList()
{
	Node *current = NULL;
	while(headTime)
	{
		current = headTime;
		headTime = current->nextTime;
		delete current -> data;
		delete current;
	
	}

	
}


void LinkedList::addTime(int time, double temp, double wind)
{
	Node *newNode = new Node;
	newNode->data = new WeatherData();
	newNode->data->setTime(time);
	newNode->data->setTemp(temp);
	newNode->data->setWind(wind);
	newNode->nextTime = NULL;	
		 		
	if(!headTime)
	{
		headTime = newNode;
		headTemp = newNode;
		headWind = newNode;
	}
	
	else
	{
		Node *current = headTime;
		Node *previous = NULL;

		while(current)
		{
		
			int tempTime = current->data->getTime();
			if(time < tempTime)
			{
				newNode->nextTime = current;
				if(!previous)
				{
					headTime = newNode;
					orderTemp(newNode, temp);
					orderWind(newNode, wind);			
				}
				else
				{
					previous->nextTime = newNode;
					orderTemp(newNode, temp);
					orderWind(newNode, wind);
				}
				return;
			}
			previous = current;
			current = current->nextTime;
		}
		previous->nextTime = newNode;
		orderTemp(newNode, temp);
		orderWind(newNode, wind);
	}
}	

void LinkedList::orderTemp(Node *newNode, double temp)
{
	Node *current = headTemp;
	Node *previous = NULL;
	newNode->nextTemp = NULL;

	while(current)
	{
		double tempTemp = current->data->getTemp();
	
		if(temp <= tempTemp)
		{
			newNode->nextTemp = current;
			if(!previous)
			{
				headTemp = newNode;
			}
			else
			{
				previous->nextTemp = newNode;
			}
			return;
		}
		previous = current;
		current = current->nextTemp;
	}
	previous->nextTemp = newNode;
}

void LinkedList::orderWind(Node *newNode, double wind)
{
	Node *current = headWind;
	Node *previous = NULL;
	newNode->nextWind = NULL;

	while(current)
	{
		double tempWind = current->data->getWind();
	
		if(wind <= tempWind)
		{
			newNode->nextWind = current;
			if(!previous)
			{
				headWind = newNode;
			}
			else
			{
				previous->nextWind = newNode;
			}
			return;
		}
		previous = current;
		current = current->nextWind;
	}
	previous->nextWind= newNode;
}


void LinkedList::printAll()
{
timeRange();
tempRange();
windRange();
counter();
cout << "                                 -- Data Report --" << endl << endl;
cout << "Time range:           " << timeMin << " - " << timeMax << endl;
cout << "Number of entries:        " << count << endl;
cout << "----------------------------------------------------------------------" << endl;
cout << "TEMPERATURE" << endl;
cout << "Min temperature:         " << tempMin/10 << " C " << endl;
cout << "Max temperature:          " << tempMax/10 << " C " << endl << endl;
topTemp();
cout << endl;
botTemp();

cout << "----------------------------------------------------------------------" << endl;
cout << "WINDSPEED" << endl;
cout << "Min windspeed:               " << windMin/100 << " m/s" << endl;
cout << "Max windspeed:           "    << windMax/100 << " m/s" << endl << endl;

topWind();
cout << endl;
botWind();


}

bool LinkedList::checkMain(int time)
{
	Node *current = headTime;
	Node *previous = NULL;
	bool found = 0;
	
	while(current != NULL)
	{
		int temp = current->data->getTime();
		if(temp == time)
		{
			delWind(time);
			delTemp(time);
			if(previous)
			{
				previous->nextTime = current->nextTime;
			}
			else
			{
				headTime = headTime->nextTime;
			}
			delete current->data;
			found = 1;
			return found;
		}
		previous = current;
		current = current->nextTime;
	}
}
	


void LinkedList::delWind(int time)
{
	Node *current = headWind;
	Node *previous = NULL;
	
	while(current != NULL)
	{
		int temp = current->data->getTime();
		if(temp == time)
		{
			if(previous)
			{
				previous->nextWind = current->nextWind;
			}
			else
			{
				headWind = headWind->nextWind;
			}
			return;
		}
		previous = current;
		current = current->nextWind;
	}
}

void LinkedList::delTemp(int time)
{
	Node *current = headTemp;
	Node *previous = NULL;
	
	while(current != NULL)
	{
		int temp = current->data->getTime();
		if(temp == time)
		{
			if(previous)
			{
				previous->nextTemp = current->nextTemp;
			}
			else
			{
				headTemp = headTemp->nextTemp;
			}
			return;
		}
		previous = current;
		current = current->nextTemp;
	}
}


void LinkedList::addToDupe(int time)
{
	Node *newNode = new Node;
	newNode->data = new WeatherData();
	newNode->data->setTime(time);
	newNode->nextTime = NULL;	
	
	if(!headTime)
	{
		headTime = newNode;
	}
	
	else
	{
		Node *current = headTime;
		Node *previous = NULL;

		while(current)
		{
		
			int tempTime = current->data->getTime();
			if(time < tempTime)
			{
				newNode->nextTime = current;
				if(!previous)
				{
					headTime = newNode;
						
				}
				else
				{
					previous->nextTime = newNode;
				}
				return;
			}
			previous = current;
			current = current->nextTime;
		}
		previous->nextTime = newNode;
		
	}


}


bool LinkedList::checkDupe(int time)
{
	Node *current = headTime;
	bool found = 0;
	while(current != NULL)
	{
		while(current != NULL)
		{
			int temp = current->data->getTime();
			if(temp == time)
			{
				found = 1;
			}
		current = current->nextTime;
		}
	}
	return found;
}
			
void LinkedList::timeRange()
{
	Node *current = headTime;
	timeMin = current->data->getTime();
	
	while(current->nextTime != NULL)
	{
		current=current->nextTime;
	}
	timeMax = current->data->getTime();
}

void LinkedList::windRange()
{
	Node *current = headWind;
	windMin = current->data->getWind();
	
	while(current->nextWind != NULL)
	{
		current=current->nextWind;
	}
	windMax = current->data->getWind();
}

void LinkedList::tempRange()
{
	Node *current = headTemp;
	tempMin = current->data->getTemp();
	
	while(current->nextTemp != NULL)
	{
		current=current->nextTemp;
	}
	tempMax = current->data->getTemp();
}

void LinkedList::counter()
{
	Node *current = headTime;
	
	while(current != NULL)
	{
		count++;
		current = current->nextTime;
	}
	
	
}



void LinkedList::topTemp()
{
	Node *current = headTemp;
	double mx = tempMax;
	double mn = tempMin;
	double diff = 0;
	double perc = 0;
	double lowest = 0;
	double tmp = 0;
	diff = mx - mn;
	perc = diff*.01;
	lowest = mx - perc;
	cout << setprecision(2);
	cout << "Top 1% temperatures (>= " << (lowest/10) << "):" << endl;
	
	while(current)
	{
			tmp = current->data->getTemp();
			if(tmp >= (lowest))
			{	
				cout << "Timestamp: " << current->data->getTime() << endl;
				cout << setprecision(3) << "Temperature: " << (current->data->getTemp()/10) << " C" << endl;
				cout << setprecision(4) << "Windspeed: " << (current->data->getWind()/100) << " m/s" << endl << endl; 
			}
			current = current->nextTemp;
	}
}
void LinkedList::botTemp()
{
	Node*current = headTemp;
	double mx = tempMax;
	double mn = tempMin;
	double diff = 0;
	double perc = 0;
	double highest = 0;
	double tmp = 0;
	diff = mx - mn;
	perc = diff*.01;
	highest = mn + perc;
	cout << setprecision(3);
	cout << "Bottom 1% temperatures (<= " << (highest/10) << "):" <<endl;
	
	while(current)
	{
			tmp = current->data->getTemp();
			if(tmp <= (highest))
			{	
				cout << "Timestamp: " << current->data->getTime() << endl;
				cout << setprecision(3) << "Temperature: " << (current->data->getTemp()/10) << " C" << endl;
				cout << setprecision(4) << "Windspeed: " << (current->data->getWind()/100) << " m/s" << endl << endl; 
			}
			current = current->nextTemp;
	}

}	

	
void LinkedList::topWind()
{
	Node *current = headWind;
	double mx = windMax;
	double mn = windMin;
	double diff = 0;
	double perc = 0;
	double lowest = 0;
	double tmp = 0;
	diff = mx - mn;
	perc = diff*.01;
	lowest = mx - perc;
	
	cout << setprecision(4);	
	cout << "Top 1% windspeeds (>= " << (ceil(lowest)/100) << "):" << endl;
	
	while(current)
	{
			tmp = current->data->getWind();
			if(tmp >= (lowest))
			{	
				cout << "Timestamp: " << current->data->getTime() << endl;
				cout << setprecision(3) << "Temperature: " << (current->data->getTemp()/10) << " C" << endl;
				cout << setprecision(4) << "Windspeed: " << (current->data->getWind()/100) << " m/s" << endl << endl; 
			}
			current = current->nextWind;
	}

}


	
void LinkedList::botWind()
{
	Node* current = headWind;
	double mx = (windMax/100);
	double mn = (windMin/100);
	double diff = 0;
	double perc = 0;
	double highest = 0;
	double tmp = 0;
	diff = mx - mn;
	perc = diff*.01;
	highest = (mn + perc)*100;
		
	cout << "Bottom 1% windspeeds (<= " << (floor(highest)/100) << "):" << endl;

	while(current)
	{
			tmp = current->data->getWind();
			if(tmp <= (highest))
			{	
				cout << "Timestamp: " << current->data->getTime() << endl;
				cout << setprecision(3) << "Temperature: " << (current->data->getTemp()/10) << " C" << endl;
				cout << setprecision(4) << "Windspeed: " << (current->data->getWind()/100) << " m/s" << endl << endl; 
			}
			current = current->nextWind;
	}




}	



