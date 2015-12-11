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
	Lux(int numR, int numG, int avai, string date, int num, int r) : SingleRoom(avai, date, num, r)
	{
		numberOfGuests = numG;
		numberOfRooms = numR;
	};
	int getType(int number) override;
	int getNumberOfGuest(int number) override;
	int getNumberOfBeds(int number) override;
	void getInformation(int number) override;
	void takeRoom(string date, int number) override;
	void leaveRoom() override;
	virtual ~Lux();
private:
	int numberOfRooms;
	int numberOfGuests;
};