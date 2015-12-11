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

int Lux::getType(int number)
{
	return 3;
}

int Lux::getNumberOfGuest(int number)
{
	return numberOfGuests;
}

int Lux::getNumberOfBeds(int number)
{
	return 2;
}

void Lux::getInformation(int number)
{
	cout << "------------------------- " << number << " ----------------------\n";
	cout << "����� ����" << endl;
	if (availability)
	{
		cout << "����� �����" << endl;
		cout << "���� ����������� : " << dateOfReg << endl;
		cout << "����� ������ ����� : " << numberOfRooms << endl;
		cout << "���������� ����������� : " << numberOfGuests << endl;
		cout << "����� ���� ���������� : " << numberOfDays << endl;
		cout << "�������� ����� ����� : " << rate << endl;
	}
	else
	{
		cout << "����� ��������" << endl;
		cout << "�������� ����� ����� : " << rate << endl;
	}
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
		cout << "��������, ������������� ����� �����\n";
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