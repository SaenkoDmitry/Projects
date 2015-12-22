#pragma once
#include "iter.h"
template <class T, class T1>
class map_node
{
private:

	T object;
	T1 object1;

public:
	map_node* next_node;
	map_node* prev_node;

	map_node(T const& t, T1 const & t1)
		: object(t), object1(t1)
		, next_node(0)
	{
		next_node = 0;
		prev_node = 0;
	}
	~map_node()
	{
		//delete next_node;
		if (prev_node)
			prev_node->next_node = next_node;
		if (next_node)
			next_node->prev_node = prev_node;
	}

	void push(T const& t)
	{
		if (next_node)
		{
			next_node->push_back(t);
		}
		else
		{
			next_node = new map_node(t);
		}
	}

	map_node* next()
	{
		return next_node;
	}
	map_node* prev()
	{
		return prev_node;
	}

	T get()
	{
		return object1;
	}
	void set(T t, T1 t1)
	{
		object = t;
		object1 = t1;
	}

};