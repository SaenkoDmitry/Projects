// Application.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\Hotel\Room.h"
#include "..\Hotel\SingleRoom.h"
#include "..\Hotel\MultiRoom.h"
#include "..\Hotel\Lux.h"
#include <iostream>
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
	cout << " - Определить занятость гостиницы \t\t(4)\n";
	cout << " - Выйти\t\t\t\t\t\t(0)\n\n";
}


int main()
{
	setlocale(LC_ALL, "Russian");
	map < int, Room * > table;
	map < int, Room * > ::iterator it;
	//SingleRoom s = SingleRoom(1, "01.09.2014", 712, 500);
	//Room r;
	SingleRoom rdfs = SingleRoom(1, (string)"01.09.2014", 712, 500);
	//Room *rdfs = new Lux(1, "01.09.2014", 712, 500);
	table.insert({528, new SingleRoom(1, "01.09.2014", 712, 500) });
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
			bool b = true;
			while (b)
			{
				int a;
				getNum(a);
				switch (a)
				{
					case 1:
					{
						map < int, Room * > ::iterator it;
						for (it = table.begin(); it != table.end(); it++)
						{
							//it->second.getInformation(it->first);
							cout << endl;
						}
						b = false;
					} break;
					case 2:
					{
						b = false;
					} break;
					case 3:
					{
						b = false;
					} break;
					default :
						error();
						break;
				}
			}
			cout << "Введите номер комнаты : " << endl;
			int num;
			getNum(num);
		} break;
		case 2:
		{
		} break;
		case 3:
		{
		} break;
		case 4:
		{
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