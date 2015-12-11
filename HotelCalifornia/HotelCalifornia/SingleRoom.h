#pragma once
#include "Room.h"
class SingleRoom : public Room
{
public:
	SingleRoom();
	SingleRoom(int rate);
	SingleRoom(int avai, std::string date, int num, int r);
	int getType(int number) override;
	int getNumberOfGuest(int number) override;
	int getNumberOfBeds(int number) override;
	void getInformation(int number) override;
	void takeRoom(string date, int number) override;
	void leaveRoom() override;
	virtual ~SingleRoom();
protected:
	string dateOfReg;
	int numberOfDays;
private:
};