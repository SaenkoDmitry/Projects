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
	for (int i = 0; i < numberOfBeds; i++)
	{
		dateOfReg[i] = date[i];
		numberOfDays[i] = num[i];
	}
	rate = r;
}

Room * MultiRoom::getType(int number)
{
	return this;
}

int MultiRoom::getNumberOfGuest(int number)
{
	return numberOfBusy;
}

void MultiRoom::getInformation(int number)
{
	cout << "����� " << number << " �������� ������������" << endl;
	if (availability)
		cout << "����� �����" << endl;
	else
		cout << "����� ��������" << endl;
	cout << "���������� ���� : " << numberOfBeds << endl;
	cout << "���������� ����������� : " << numberOfBusy << endl;
	cout << "\t���� ����������� : \t����� ���� ����������" << endl << endl;
	for (int i = 0; i < numberOfBusy; i++)
	{
		cout << "\t" << dateOfReg[i] << "\t" << numberOfDays[i] << endl;
	}
	cout << "�������� ����� ����� : " << rate << endl;;
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
		cout << "����� ��������� �����\n";
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
