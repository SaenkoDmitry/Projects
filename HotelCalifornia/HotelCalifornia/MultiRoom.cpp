#include "stdafx.h"
#include <iostream>
#include "MultiRoom.h"

using std::cout;
using std::cin;
using std::endl;

MultiRoom::MultiRoom()
{
}

MultiRoom::MultiRoom(int rate)
{
	this->rate = rate;
	availability = 0;
}

MultiRoom::MultiRoom(int avai, int numberOfBeds, int numberOfBusy, string date[], int num[], int r)
{
	availability = avai;
	this->numberOfBusy = numberOfBusy;
	this->numberOfBeds = numberOfBeds;
	for (int i = 0; i < numberOfBusy; i++)
	{
		dateOfReg[i] = date[i];
		numberOfDays[i] = num[i];
	}
	rate = r;
}

int MultiRoom::getType(int number)
{
	return 2;
}

int MultiRoom::getNumberOfGuest(int number)
{
	return numberOfBusy;
}

void MultiRoom::getInformation(int number)
{
	cout << "Номер " << number << " является многоместным" << endl;
	if (availability)
		cout << "Номер занят" << endl;
	else
		cout << "Номер свободен" << endl;
	cout << "Количество мест : " << numberOfBeds << endl;
	cout << "Количество проживающих : " << numberOfBusy << endl;
	cout << "Дата регистрации : \t\tЧисло дней проживания : " << endl;
	for (int i = 0; i < numberOfBusy; i++)
	{
		cout << dateOfReg[i] << "\t\t\t" << numberOfDays[i] << endl;
	}
	cout << "Суточный тариф равен : " << rate << endl;;
}

void MultiRoom::takeRoom(string date, int number)
{
	if (numberOfBusy != 4)
	{
		dateOfReg[numberOfBusy] = date;
		numberOfDays[numberOfBusy] = number;
		numberOfBusy++;
	}
	else
	{
		cout << "Номер полностью занят\n";
	}
}

void MultiRoom::leaveRoom()
{
	if (numberOfBusy)
		numberOfBusy--;
}

MultiRoom::~MultiRoom()
{
	delete this;
}