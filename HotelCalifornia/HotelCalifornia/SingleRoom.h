#pragma once
#include "Room.h"
class SingleRoom : public Room
{
public:
	SingleRoom();
	SingleRoom(int rate);
	SingleRoom(int avai, std::string date, int num, int r);
	virtual int getType(int number) override;
	virtual int getNumberOfGuest(int number) override;
	virtual void getInformation(int number) override;
	virtual void takeRoom(string date, int number) override;
	virtual void leaveRoom() override;
	virtual ~SingleRoom();
protected:
	string dateOfReg;
	int numberOfDays;
private:
};