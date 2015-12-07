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
	cout << "����� " << number << " �������� ������" << endl;
	if (availability)
		cout << "����� �����" << endl;
	else
		cout << "����� ��������" << endl;
	cout << "���� ����������� : " << dateOfReg << endl;
	cout << "����� ������ ����� : " << numberOfRooms << endl;
	cout << "���������� ����������� : " << numberOfGuests << endl;
	cout << "����� ���� ���������� : " << numberOfDays << endl;
	cout << "�������� ����� ����� : " << rate << endl;;
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
		cout << "��������, ������������� ����� �����\n";
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
