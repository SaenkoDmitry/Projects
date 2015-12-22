#pragma once
#pragma once
#include <string>
#include <iostream>
#include "stdafx.h"
#include <memory>
using std::string;
class Room
{
public:
	virtual int getType() = 0;
	int getAvailability() const;
	virtual int getNumberOfGuest() = 0;
	virtual int getNumberOfBeds() = 0;
	virtual void getInformation(int number) = 0;
	virtual void printFile(FILE *file, int number) = 0;
	virtual void takeRoom(std::basic_string<char> date, int number) = 0;
	virtual void leaveRoom() = 0;
	virtual ~Room();	
protected:
	int availability;
	int rate;
};