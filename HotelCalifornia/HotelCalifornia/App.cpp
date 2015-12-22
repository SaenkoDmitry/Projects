#include "stdafx.h"
#include "Room.h"
#include "App.h"
#include "map1.h"
#include "map_node.h"

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::string;
using std::getline;

App::App()
{
}


App::~App()
{
}

int App::getNum(int &a)
{
	cin >> a;
	if (!cin.good())
	{
		error();
	}
	return 0;
}

int App::getNum(double &a)
{
	cin >> a;
	if (!cin.good())
	{
		error();
	}
	return 0;
}
int App::getNum(char &a)
{
	cin >> a;
	if (!cin.good())
	{
		error();
	}
	return 0;
}

void App::error()
{
	cout << "Error!" << endl;
	system("pause");
	exit(1);
}

void App::readFile()
{
	char fileName[80] = "Hotel.txt";
	char result_string[100];
	errno_t err;
	FILE *file;
	err = fopen_s(&file, fileName, "r+");
	int i = 0;
	int size = 0;
	int k = 0;
	if (err)
		error();
	string res[100];
	string resmul[100];
	int mulnum[100];
	while (fgets(result_string, sizeof(result_string), file))
	{
		if (result_string[0] != '#')
		{
			res[i] = result_string;
			i++;
		}
		else
		{
			size = i;
			i = 0;
			k = 0;
			if (res[0][0] == '1')
			{
				insert(atoi(res[0].substr(2, res[0].size() - 2).c_str()), atoi(res[1].c_str()), res[2], atoi(res[3].c_str()), atoi(res[4].c_str()));
			}
			else if (res[0][0] == '2')
			{
				for (int h = 4; h < size - 2; h = h + 2)
				{
					resmul[k] = res[h].substr(0, res[h].size() - 1);
					mulnum[k] = atoi(res[h + 1].substr(0, res[h + 1].size() - 1).c_str());
					k++;
				}
				insert(atoi(res[0].substr(2, res[0].size() - 2).c_str()), atoi(res[1].c_str()), atoi(res[2].c_str()), atoi(res[3].c_str()), resmul, mulnum, atoi(res[size - 1].c_str()));
			}
			else if (res[0][0] == '3')
			{
				insert(atoi(res[0].substr(2, res[0].size() - 2).c_str()), atoi(res[1].c_str()), atoi(res[2].c_str()), atoi(res[3].c_str()), res[4], atoi(res[5].c_str()), atoi(res[6].c_str()));
			}
		}
	}
	fclose(file);
}

void App::writeFile()
{
	char fileName[80] = "Hotel.txt";
	errno_t err;
	//std::ofstream o(file);
	FILE *file;
	err = fopen_s(&file, fileName, "r");
	fprintf(file, "#");
	map < int, Room * > ::iterator it;
	for (it = table.begin(); it != table.end(); it++)
	{
		if((*it).second->getType() == 1)
		{
			(*it).second->printFile(file, it->first);
		}
		else if ((*it).second->getType() == 2)
		{
			fprintf(file, "#");
		}
		else if ((*it).second->getType() == 3)
		{
			fprintf(file, "#");
		}
		(*it).second->getInformation(it->first);
		cout << endl;
	}
	fprintf(file, "#");
	fclose(file);
}

void App::insert(int number, int avai, string date, int num, int r)
{
	table.insert({ number, new SingleRoom(avai, date, num, r) });
}

void App::insert(int number, int avai, int numBeds, int numBusy, string date[], int num[], int r)
{
	table.insert({ number, new MultiRoom(avai, numBeds, numBusy, date, num, r) });
}

void App::insert(int number, int numR, int numG, int avai, string date, int num, int r)
{
	table.insert({ number, new Lux(numR, numG, avai, date, num, r) });
}

//Table App::find(int number)
//{
//
//}

void App::deleteT(int number)
{

}

void App::printMenu()
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

int App::run()
{
	setlocale(LC_ALL, "Russian");
	map < int, Room * > ::iterator it;
	//myMap < int, Room * > mymap;
	//mymap.insert(528, new SingleRoom(1, "01.09.2014", 13, 500));
	//std::map<int, Room*>::iterator cur = room.stations.begin();
	/*table.insert({ 528, new SingleRoom(1, "01.09.2014", 13, 500) });
	table.insert({ 529, new Lux(5, 10, 1, "01.09.2014", 13, 50000) });
	table.insert({ 530, new Lux(5, 10, 1, "01.09.2014", 13, 50000) });
	table.insert({ 531, new Lux(50000) });*/
	readFile();
	int a[1];
	a[0] = 13;
	string s[1] = { "01.09.2014" };
	//table.insert({ 527, new MultiRoom(0, 4, 1, s, a, 500) });
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
			int b;
			getNum(b);
			while (b < 1 || b > 3)
			{
				cout << "Повторите ввод : " << endl;
				getNum(b);
			}
			map < int, Room * > ::iterator it;
			int avai = 0;
			for (it = table.begin(); it != table.end(); it++)
			{
				if ((*it).second->getType() == b && !(*it).second->getAvailability())
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
					if (b == 1)
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
					else if (b == 2)
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
					else if (b == 3)
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
						if ((*it).second->getType() == 1)
						{
						(*table.find(num)).second->leaveRoom();
						}
						else if ((*it).second->getType() == 2)
						{
						cout << "Введите индекс гостя, которого вы выселяете : " << endl;
						int b;
						getNum(b);
						while (b < 1)// || a >= (*table.find(num)).second->getNumberOfGuest)
						{
						cout << "Повторите ввод : " << endl;
						getNum(b);
						}
						(*table.find(num)).second->leaveRoom();
						}
						else if ((*it).second->getType() == 3)
						{
						(*table.find(num)).second->leaveRoom();
						}
						cout << endl;
					}
				}
			}
		} break;
		case 3:
		{
			map < int, Room * > ::iterator it;
			int avai = 0;
			cout << "Введите тип номера, который вам нужен : (SingleRoom-1, MultiRoom-2, Lux-3, 4-All)" << endl;
			int b;
			getNum(b);
			while (b < 1 || b > 4)
			{
				cout << "Повторите ввод : " << endl;
				getNum(b);
			}
			avai = 0;
			for (it = table.begin(); it != table.end(); it++)
			{
				if (b != 4)
				{
					if ((*it).second->getType() == b && !(*it).second->getAvailability())
					{
						(*it).second->getInformation(it->first);
						avai = 1;
						cout << endl;
					}
				}
				else
					(*it).second->getInformation(it->first);
			}
			if (!avai)
				cout << "Очень жаль, номеров нет\n";
			else
			{
				cout << "\nХотите добавить жильца?(y/n) : ";
				char s;
				getNum(s);
				if (s == 'n')
					continue;
				cout << "\nВведите номер комнаты : " << endl;
				int num;
				getNum(num);
				if (table.find(num) != table.end())
				{
					if (b == 1)
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
					else if (b == 2)
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
					else if (b == 3)
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
				if ((*it).second->getType() == 1)
				{
					numOfBeds++;
					if ((*it).second->getAvailability() == 0)
						numOfPeoples++;
				}
				else if ((*it).second->getType() == 2)
				{
					numOfBeds += (*it).second->getNumberOfBeds();
					numOfPeoples += (*it).second->getNumberOfGuest();
				}
				else if ((*it).second->getType() == 3)
				{
					numOfBeds += (*it).second->getNumberOfBeds();
					numOfPeoples += (*it).second->getNumberOfGuest();
				}
			}
			cout << "Занятость гостиницы равна : " << (double)numOfPeoples / numOfBeds << endl;
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