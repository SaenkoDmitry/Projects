#include "stdafx.h"
#include <iostream>
#include "Lux.h"

using std::cout;
using std::cin;
using std::endl;

Lux::Lux()
{
	numberOfRooms = 0;
	numberOfGuests = 0;
}

int Lux::getType()
{
	return 3;
}

int Lux::getNumberOfGuest()
{
	return numberOfGuests;
}

int Lux::getNumberOfBeds()
{
	return 2;
}

void Lux::getInformation(int number)
{
	cout << "------------------------- " << number << " ----------------------\n";
	cout << "Номер ЛЮКС" << endl;
	if (availability)
	{
		cout << "Номер занят" << endl;
		cout << "Дата регистрации : " << dateOfReg << endl;
		cout << "Число комнат равно : " << numberOfRooms << endl;
		cout << "Количество проживающих : " << numberOfGuests << endl;
		cout << "Число дней проживания : " << numberOfDays << endl;
		cout << "Суточный тариф равен : " << rate << endl;
	}
	else
	{
		cout << "Номер свободен" << endl;
		cout << "Суточный тариф равен : " << rate << endl;
	}
}

void Lux::printFile(FILE* file, int number)
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
	_itoa_s(numberOfGuests, s, 10);
	fprintf(file, s);
	fprintf(file, "\n");
	_itoa_s(numberOfRooms, s, 10);
	fprintf(file, s);
	fprintf(file, "\n");
	_itoa_s(numberOfDays, s, 10);
	fprintf(file, s);
	fprintf(file, "\n");
	_itoa_s(rate, s, 10);
	fprintf(file, s);
}

void Lux::takeRoom(string date, int number)
{
	if (!availability)
	{
		availability = 1;
		dateOfReg = date;
		numberOfDays = number;
	}
	else
	{
		cout << "Извините, запрашиваемый номер занят\n";
	}
}

void Lux::leaveRoom()
{
	availability = 0;
	numberOfGuests = 0;
}

Lux::~Lux()
{
	delete this;
}