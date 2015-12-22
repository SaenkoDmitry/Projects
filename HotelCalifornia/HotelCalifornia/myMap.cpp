#include "stdafx.h"
#include "myMap.h"
#include "Room.h"

//template <class T, class T1>
//myMap<T, T1>::myMap()
//{
//	size = 0;
//	i = nullptr;
//	j = nullptr;
//}
//template <class T, class T1>
//myMap<T, T1>::myMap(T a, T b)
//{
//	size = 0;
//	i = new T();
//	j = new T1();
//	i[0] = a;
//	j[0] = b;
//}

template<class T, class T1>
void myMap<T, T1>::insert(T a, T1 b)
{
	if(t == nullptr)
	{
		t = new Temp;
		t->key = a;
		t->value = b;
		t->next = nullptr;
	}
	else
	{
		Temp * node = t;
		while(node->next != nullptr && node->next->key < a)
		{
			node = node->next;
		}
		Temp k, m = new Temp;
		k = node->next;
		node->next = m;
		m->next = k;
	}
	/*size++;
	T ii = new T[size];
	T1 jj = new T1[size];
	for (int g = 0; g < size - 1; g++)
	{
		ii[g] = key[g];
		jj[g] = value[g];
	}
	key = ii;
	value = jj;
	if(size == 1)
	{
		key[0] = a;
		value[0] = b;
	}
	else
	{
		for (int k = 0; k < size; k++)
		{
			if(key[k] > a)
			{
				for (int h = size - 1; h > k; h--)
				{
					key[h] = key[h - 1];
					value[h] = value[h - 1];
				}
				key[k] = a;
				value[k] = b;
				break;
			}
		}
	}*/
}

template <class T, class T1>
T1 myMap<T, T1>::find(T a)
{
	if (t != nullptr)
	{
		Temp * node = t;
		while (node != nullptr && node->key != a)
		{
			node = node->next;
		}
		if(node != nullptr)
		{
			return node->value;
		}
	}
	/*for (int k = 0; k < size; k++)
	{
		if (key[k] == a)
		{
			return value[k];
		}
	}*/
}

template <class T, class T1>
void myMap<T, T1>::Delete(T a)
{

	Temp * node = t;
	while (node->next != nullptr && node->next->key != a)
	{
		node = node->next;
	}
	if (node->next != nullptr)
	{
		node->next = node->next->next;
		delete(node->next);
	}
	else if (node->key == a)
	{
		while (node->next != nullptr && node->next->next != nullptr)
		{
			node = node->next;
		}
		node->next = nullptr;
	}
	/*for (int k = 0; k < size; k++)
	{
		if (key[k] == a)
		{
			for (int h = 0; h < size - 1; h++)
			{
				key[h] = key[h + 1];
				value[h] = value[h + 1];
			}
			size--;
			break;
		}
	}*/
}

//template <class T, class T1>
//myMap<T, T1>::~myMap()
//{
//	delete[] i;
//	delete[] j;
//}
