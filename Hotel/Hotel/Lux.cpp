#include "stdafx.h"
#include <iostream>
#include "Lux.h"

using std::cout;
using std::cin;
using std::endl;

Room * Lux::getType(int number)
{
	return this;
}

int Lux::getNumberOfGuest(int number)
{
	return numberOfGuests;
}

void Lux::getInformation(int number)
{
	cout << "Номер " << number << " является люксом" << endl;
	if (availability)
		cout << "Номер занят" << endl;
	else
		cout << "Номер свободен" << endl;
	cout << "Дата регистрации : " << dateOfReg << endl;
	cout << "Число комнат равно : " << numberOfRooms << endl;
	cout << "Количество проживающих : " << numberOfGuests << endl;
	cout << "Число дней проживания : " << numberOfDays << endl;
	cout << "Суточный тариф равен : " << rate << endl;;
}

void Lux::takeRoom(string date, int number)
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

void Lux::leaveRoom()
{
	availability = 0;
}

Lux::~Lux()
{
	delete this;
}
