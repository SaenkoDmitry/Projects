#pragma once
#include "Room.h"
#include "SingleRoom.h"

class Lux : public SingleRoom
{
public:
	Lux();

	explicit Lux(int rate) : SingleRoom(rate)
	{
		numberOfGuests = 0;
		numberOfRooms = 0;
	};
	Lux(int avai, string date, int num, int r) : SingleRoom(avai, date, num, r)
	{
		numberOfGuests = 0;
		numberOfRooms = 0;
	};
	virtual int getType(int number) override;
	virtual int getNumberOfGuest(int number) override;
	virtual void getInformation(int number) override;
	virtual void takeRoom(string date, int number) override;
	virtual void leaveRoom() override;
	virtual ~Lux();
private:
	int numberOfRooms;
	int numberOfGuests;
};