CC=g++

all: prog

prog: weatherlog.o linkedList.o dataLogger.o weatherData.o
	$(CC) weatherlog.o linkedList.o dataLogger.o weatherData.o -g -o prog

weatherlog.o: weatherlog.cpp
	$(CC) -c weatherlog.cpp

linkedList.o: linkedList.cpp
	$(CC) -c linkedList.cpp

dataLogger.o: dataLogger.cpp
	$(CC) -c dataLogger.cpp

weataherData.o: weatherData.cpp
	$(CC) -c weatherData.cpp

clean:
	rm *.o prog
