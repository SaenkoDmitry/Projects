// Application.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "..\HotelCalifornia\Room.h"
#include "..\HotelCalifornia\SingleRoom.h"
#include "..\HotelCalifornia\MultiRoom.h"
#include "..\HotelCalifornia\Lux.h"

#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::map;

int getNum(int &a);
int getNum(double &a);
int getNum(char &a);
void error();
void Dialog();

int getNum(int &a)
{
	cin >> a;
	if (!cin.good())
	{
		error();
	}
	return 0;
}

int getNum(double &a)
{
	cin >> a;
	if (!cin.good())
	{
		error();
	}
	return 0;
}
int getNum(char &a)
{
	cin >> a;
	if (!cin.good())
	{
		error();
	}
	return 0;
}

void error()
{
	cout << "Error!" << endl;
	system("pause");
	exit(1);
}

struct Node
{
	int key;
	struct Item *info;
};
struct Table
{
	struct Node *buffer;
};

void printMenu()
{
	system("cls");
	cout << "\t*********************************";
	cout << "\n\t*\t Гостиница\t\t*\n";
	cout << "\t*********************************\n";
	cout << " - Оформить нового гостя \t\t\t(1)\n";
	cout << " - Освободить номер \t\t\t\t(2)\n";
	cout << " - Вывести информацию о свободных номерах \t(3)\n";
	cout << " - Вывести информацию о всех номерах \t\t(4)\n";
	cout << " - Определить занятость гостиницы \t\t(5)\n";
	cout << " - Выйти\t\t\t\t\t(0)\n\n";
}


int main()
{
	setlocale(LC_ALL, "Russian");
	map < int, Room * > table;
	map < int, Room * > ::iterator it;
	table.insert({528, new SingleRoom(1, "01.09.2014", 715, 500) });
	table.insert({ 50644, new Lux(5, 10, 1, "01.09.2014", 715, 50000) });
	int a[1];
	a[0] = 715;
	string s[1] = { "01.09.2014" };
	table.insert({ 5145, new MultiRoom(0, 4, 1, s, a, 500) });
	for (it = table.begin(); it != table.end(); it++)
	{

	}
	while (true)
	{
		printMenu();
		int a;
		getNum(a);
		switch (a)
		{
		case 0:
		{
			exit(1);
		} break;
		case 1:
		{
			cout << "Введите тип номера, который вам нужен : (SingleRoom-1, MultiRoom-2, Lux-3)" << endl;
				int a;
				getNum(a);
				while(a < 1 || a > 3)
				{
					cout << "Повторите ввод : " << endl;
					getNum(a);
				}
				map < int, Room * > ::iterator it;
				int avai = 0;
				for (it = table.begin(); it != table.end(); it++)
				{
					if ((*it).second->getType(it->first) == a && !(*it).second->getAvailability(it->first))
					{
						(*it).second->getInformation(it->first);
						avai = 1;
						cout << endl;
					}
				}
				if (!avai)
					cout << "Очень жаль, номеров нет\n";
				else
				{
					cout << "\nВведите номер комнаты : " << endl;
					int num;
					getNum(num);
					if (table.find(num) != table.end())
					{
						if (a == 1)
						{
							string s;
							int days;
							cout << "\nВведите дату регистрации : " << endl;
							cin >> s;
							cout << "\nВведите число дней проживания : " << endl;
							getNum(days);
							for (it = table.begin(); it != table.end(); it++)
							{
								if (it->first == num)
								{
									(*it).second->takeRoom(s, days);
									//(*it).second->getInformation(it->first);
								}
							}
						}
						else if (a == 2)
						{
							string s;
							int days;
							cout << "\nВведите дату регистрации : " << endl;
							cin >> s;
							cout << "\nВведите число дней проживания : " << endl;
							getNum(days);
							for (it = table.begin(); it != table.end(); it++)
							{
								if (it->first == num)
								{
									(*it).second->takeRoom(s, days);
									//(*it).second->getInformation(it->first);
								}
							}
						}
						else if (a == 3)
						{
							string s;
							int days;
							cout << "\nВведите дату регистрации : " << endl;
							cin >> s;
							cout << "\nВведите число дней проживания : " << endl;
							getNum(days);
							for (it = table.begin(); it != table.end(); it++)
							{
								if (it->first == num)
								{
									(*it).second->takeRoom(s, days);
									//(*it).second->getInformation(it->first);
								}
							}
						}
					}
					else
						cout << "Такой комнаты нет" << endl;
				}
		} break;
		case 2:
		{
			cout << "\nВведите номер комнаты : " << endl;
			int num;
			getNum(num);
			if (table.find(num) != table.end())
			{
				for (it = table.begin(); it != table.end(); it++)
				{
					if (it->first == num)
					{
						(*it).second->leaveRoom();
						(*it).second->getInformation(it->first);
						/*if ((*it).second->getType(it->first) == 1)
						{
							(*table.find(num)).second->leaveRoom();
						}
						else if ((*it).second->getType(it->first) == 2)
						{
							cout << "Введите индекс гостя, которого вы выселяете : " << endl;
							int a;
							getNum(a);
							while (a < 1 || a >= (*table.find(num)).second->getNumberOfGuest(it->first))
							{
								cout << "Повторите ввод : " << endl;
								getNum(a);
							}
							(*table.find(num)).second->leaveRoom(a);
						}
						else if ((*it).second->getType(it->first) == 3)
						{
							(*table.find(num)).second->leaveRoom();
						}*/
						cout << endl;
					}
				}
			}
		} break;
		case 3:
		{
			map < int, Room * > ::iterator it;
			int avai = 0;
			for (it = table.begin(); it != table.end(); it++)
			{
				if (!(*it).second->getAvailability(it->first))
				{
					(*it).second->getInformation(it->first);
					avai = 1;
					cout << endl;
				}
			}
			if (!avai)
				cout << "Очень жаль, номеров нет\n";
		} break;
		case 4:
		{
			map < int, Room * > ::iterator it;
			int avai = 0;
			for (it = table.begin(); it != table.end(); it++)
			{
				(*it).second->getInformation(it->first);
				avai = 1;
				cout << endl;
			}
			if (!avai)
				cout << "Очень жаль, номеров нет\n";
		} break;
		case 5:
		{
			int numOfBeds = 0, numOfPeoples = 0;
			map < int, Room * > ::iterator it;
			for (it = table.begin(); it != table.end(); it++)
			{
				if((*it).second->getType(it->first) == 1)
				{
					numOfBeds++;
					if((*it).second->getAvailability(it->first) == 0)
						numOfPeoples++;
				}
				else if ((*it).second->getType(it->first) == 2)
				{
					numOfBeds += (*it).second->getNumberOfBeds(it->first);
					numOfPeoples += (*it).second->getNumberOfGuest(it->first);
				}
				else if ((*it).second->getType(it->first) == 3)
				{
					numOfBeds += (*it).second->getNumberOfBeds(it->first);
					numOfPeoples += (*it).second->getNumberOfGuest(it->first);
				}
			}
			cout << "Занятость гостиницы равна : " << numOfPeoples / numOfBeds << endl;
		} break;
		default:
			error();
			break;
		}
		cin.clear();
		cout << "\nХотите продолжить(y/n) : ";
		char s;
		getNum(s);
		if (s == 'n')
			break;
		else if (s == 'y')
			continue;
		else
			error();
	}
	return 0;
}