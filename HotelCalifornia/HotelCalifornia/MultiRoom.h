#pragma once
#include "Room.h"
class MultiRoom : public Room
{
public:
	MultiRoom();
	MultiRoom(int rate);
	MultiRoom(int avai, int numberOfBeds, int numberOfBusy, string date[], int num[], int r);
	int getType(int number) override;
	int getNumberOfGuest(int number) override;
	int getNumberOfBeds(int number) override;
	void getInformation(int number) override;
	void takeRoom(string date, int number) override;
	void leaveRoom() override;
	//void leaveRoom(int i);
	virtual ~MultiRoom();
private:
	int numberOfBeds;
	int numberOfBusy;
	string dateOfReg[4];
	int numberOfDays[4];
};