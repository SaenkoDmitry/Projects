#pragma once
#include "Room.h"
class SingleRoom : public Room
{
public:
	SingleRoom();
	SingleRoom(int rate);
	SingleRoom(int avai, string date, int num, int r);
	virtual Room * getType(int number);
	virtual int getNumberOfGuest(int number);
	virtual void getInformation(int number);
	virtual void takeRoom(string date, int number);
	virtual void leaveRoom();
	virtual ~SingleRoom();
protected:
	string dateOfReg;
	int numberOfDays;
private:
};