#pragma once
#include <iostream>
#include "stdafx.h"
#include "Room.h"

using std::pair;

template < class T, class T1 >
class myMap
{
private:
	int size = 0;
	//pair< T, T1 > *map;
public:
	struct Temp
	{
		T key;
		T1 value;
		Temp *next;
	};
	Temp t = nullptr;
	void insert(T a, T1 b);
	T1 find(T a);
	void Delete(T a);
};