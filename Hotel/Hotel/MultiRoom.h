#pragma once
#include "Room.h"
class MultiRoom : public Room
{
public:
	MultiRoom();
	MultiRoom(int rate);
	MultiRoom(int avai, int numberOfBeds, int numberOfBusy, string date[], int num[], int r);
	virtual Room * getType(int number);
	virtual int getNumberOfGuest(int number);
	virtual void getInformation(int number);
	virtual void takeRoom(string date, int number);
	virtual void leaveRoom();
	virtual ~MultiRoom();
private:
	int numberOfBeds;
	int numberOfBusy;
	string dateOfReg[4];
	int numberOfDays[4];
};