#pragma once
#include "..\HotelCalifornia\Room.h"
#include "..\HotelCalifornia\SingleRoom.h"
#include "..\HotelCalifornia\MultiRoom.h"
#include "..\HotelCalifornia\Lux.h"
#include <map>

class App
{
private:
	std::map < int, Room * > table;
	int getNum(int &a);
	int getNum(double &a);
	int getNum(char &a);
	static void error();
	void readFile();
	void writeFile();
	void insert(int number, int avai, string date, int num, int r);
	void insert(int number, int avai, int numBeds, int numBusy, string date[], int num[], int r);
	void insert(int number, int numR, int numG, int avai, string date, int num, int r);
	//myMap find(int number);
	void deleteT(int number);
	static void printMenu();
public:
	App();
	~App();
	int run();
};