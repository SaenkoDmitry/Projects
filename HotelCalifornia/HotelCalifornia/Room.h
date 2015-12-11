#pragma once
#pragma once
#include <string>
#include <iostream>
using std::string;
class Room
{
public:
	virtual int getType(int number) = 0;
	virtual int getAvailability(int number);
	virtual int getNumberOfGuest(int number) = 0;
	virtual void getInformation(int number) = 0;
	virtual void takeRoom(std::basic_string<char> date, int number) = 0;
	virtual void leaveRoom() = 0;
	virtual ~Room();
protected:
	int availability;
	int rate;
};