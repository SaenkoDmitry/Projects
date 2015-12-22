#pragma once
#include "Room.h"
class MultiRoom : public Room
{
public:
	MultiRoom();
	MultiRoom(int rate);
	MultiRoom(int avai, int numberOfBeds, int numberOfBusy, string date[], int num[], int r);
	int getType() override;
	int getNumberOfGuest() override;
	int getNumberOfBeds() override;
	void getInformation(int number) override;
	void printFile(FILE *file, int number) override;
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