#pragma once
#include <string>
#include <iostream>
using std::string;
class Room
{
public:
	Room() {};
	virtual Room * getType(int number) = 0;
	int getAvailability(int number);
	virtual int getNumberOfGuest(int number) = 0;
	virtual void getInformation(int number) = 0;
	virtual void takeRoom(string date, int number) = 0;
	virtual void leaveRoom() = 0;
	virtual ~Room() { delete this; };
protected:
	int availability;
	int rate;
};