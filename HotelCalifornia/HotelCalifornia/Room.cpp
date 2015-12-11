#include "stdafx.h"
#include <iostream>
#include "Room.h"

using std::cout;
using std::cin;
using std::endl;

int Room::getAvailability(int number) const
{
	return availability;
}

Room::~Room()
{
	delete this;
}