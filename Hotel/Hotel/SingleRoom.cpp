#include "stdafx.h"
#include <iostream>
#include "SingleRoom.h"

using std::cout;
using std::cin;
using std::endl;

SingleRoom::SingleRoom()
{
}

SingleRoom::SingleRoom(int rate)
{
	this->rate = rate;
	availability = 0;
}

SingleRoom::SingleRoom(int avai, string date, int num, int r)
{
	availability = avai;
	dateOfReg = date;
	numberOfDays = num;
	rate = r;
}

Room * SingleRoom::getType(int number)
{
	return this;
}

int SingleRoom::getNumberOfGuest(int number)
{
	return 1;
}

void SingleRoom::getInformation(int number)
{
	cout << "����� " << number << " �������� �����������" << endl;
	if (availability)
		cout << "����� �����" << endl;
	else
		cout << "����� ��������" << endl;
	cout << "���� ����������� : " << dateOfReg << endl;
	cout << "����� ���� ���������� : " << numberOfDays << endl;
	cout << "�������� ����� ����� : " << rate << endl;;
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
		cout << "��������, ������������� ����� �����\n";
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
