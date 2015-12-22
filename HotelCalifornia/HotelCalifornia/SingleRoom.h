#pragma once
#include "Room.h"
class SingleRoom : public Room
{
public:
	SingleRoom();
	SingleRoom(int rate);
	SingleRoom(int avai, std::string date, int num, int r);
	int getType() override;
	int getNumberOfGuest() override;
	int getNumberOfBeds() override;
	void getInformation(int number) override;
	void printFile(FILE *file, int number) override;
	void takeRoom(string date, int number) override;
	void leaveRoom() override;
	virtual ~SingleRoom();
protected:
	string dateOfReg;
	int numberOfDays;
private:
};