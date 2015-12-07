#pragma once
#include "Room.h"
#include "SingleRoom.h"

class Lux : public SingleRoom
{
public:
	Lux() {};
	Lux(int rate) : SingleRoom(rate) {};
	Lux(int avai, string date, int num, int r) : SingleRoom(avai, date, num, r) {};
	virtual Room * getType(int number);
	virtual int getNumberOfGuest(int number);
	virtual void getInformation(int number);
	virtual void takeRoom(string date, int number);
	virtual void leaveRoom();
	virtual ~Lux();
private:
	int numberOfRooms;
	int numberOfGuests;
};