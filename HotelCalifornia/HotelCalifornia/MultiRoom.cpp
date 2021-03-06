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

int MultiRoom::getType()
{
	return 2;
}

int MultiRoom::getNumberOfGuest()
{
	return numberOfBusy;
}

int MultiRoom::getNumberOfBeds()
{
	return numberOfBeds;
}

void MultiRoom::getInformation(int number)
{
	cout << "------------------------- " << number << " ----------------------\n";
	cout << "������������ �����" << endl;
	if (availability)
		cout << "����� �����" << endl;
	else
		cout << "����� ��������" << endl;
	if (numberOfBusy != 0)
	{
		cout << "���������� ���� : " << numberOfBeds << endl;
		cout << "���������� ����������� : " << numberOfBusy << endl;
		cout << "���� ����������� : \t\t����� ���� ���������� : " << endl;
		for (int i = 0; i < numberOfBusy; i++)
		{
			cout << dateOfReg[i] << "\t\t\t" << numberOfDays[i] << endl;
		}
		cout << "�������� ����� ����� : " << rate << endl;
	}
	else
		cout << "�������� ����� ����� : " << rate << endl;
}

void MultiRoom::printFile(FILE* file, int number)
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
	for (int i = 0; i < numberOfBusy; i++)
	{
		fprintf(file, dateOfReg[i].c_str());
		_itoa_s(numberOfBusy, s, 10);
		fprintf(file, s);
		fprintf(file, "\n");
	}
	_itoa_s(rate, s, 10);
	fprintf(file, s);
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

//void MultiRoom::leaveRoom(int i)
//{
//	if (numberOfBusy)
//	{
//		for (int j = 0; j < numberOfBusy; j++)
//		{
//			if (j == i)
//			{
//				for (int h = j; h < numberOfBusy - 1; h++)
//				{
//					dateOfReg[h] = dateOfReg[h + 1];
//					numberOfDays[h] = numberOfDays[h + 1];
//				}
//			}
//		}
//		numberOfBusy--;
//	}
//}f

MultiRoom::~MultiRoom()
{
	delete this;
}