#include "stdafx.h"
#include <iostream>
#include "SingleRoom.h"

using std::cout;
using std::cin;
using std::endl;

SingleRoom::SingleRoom()
{
	numberOfDays = 0;
}

SingleRoom::SingleRoom(int rate)
{
	this->rate = rate;
	availability = 0;
	numberOfDays = 0;
}

SingleRoom::SingleRoom(int avai, string date, int num, int r)
{
	availability = avai;
	dateOfReg = date;
	numberOfDays = num;
	rate = r;
}

int SingleRoom::getType()
{
	return 1;
}

int SingleRoom::getNumberOfGuest()
{
	return 1;
}

int SingleRoom::getNumberOfBeds()
{
	return 1;
}

void SingleRoom::getInformation(int number)
{
	cout << "------------------------- " << number << " ----------------------\n";
	cout << "Одноместный номер" << endl;
	if (availability)
	{
		cout << "Номер занят" << endl;
		cout << "Дата регистрации : " << dateOfReg << endl;
		cout << "Число дней проживания : " << numberOfDays << endl;
		cout << "Суточный тариф равен : " << rate << endl;
	}
	else
	{
		cout << "Номер свободен" << endl;
		cout << "Суточный тариф равен : " << rate << endl;
	}
}

void SingleRoom::printFile(FILE *file, int number)
{
	char s[100];
	_itoa_s(getType(), s, 10);
	fprintf(file, s);
	fprintf(file, " ");
	_itoa_s(number, s, 10);
	fprintf(file, s);
	fprintf(file, "\n");
	_itoa_s(getAvailability(), s, 10);
	fprintf(file, s);
	fprintf(file, "\n");
	fprintf(file, dateOfReg.c_str());
	_itoa_s(numberOfDays, s, 10);
	fprintf(file, s);
	_itoa_s(rate, s, 10);
	fprintf(file, s);
}

void SingleRoom::takeRoom(string date, int number)
{
	if (!availability)
	{
		dateOfReg = date;
		numberOfDays = number;
	}
	else
	{
		cout << "Извините, запрашиваемый номер занят\n";
	}
}

void SingleRoom::leaveRoom()
{
	availability = 0;
}

SingleRoom::~SingleRoom()
{
	delete this;
}