#pragma once
#include "Room.h"
class MultiRoom : public Room
{
public:
	MultiRoom();
	MultiRoom(int rate);
	MultiRoom(int avai, int numberOfBeds, int numberOfBusy, string date[], int num[], int r);
	virtual int getType(int number) override;
	virtual int getNumberOfGuest(int number) override;
	virtual void getInformation(int number) override;
	virtual void takeRoom(string date, int number) override;
	virtual void leaveRoom() override;
	virtual ~MultiRoom();
private:
	int numberOfBeds;
	int numberOfBusy;
	string dateOfReg[4];
	int numberOfDays[4];
};