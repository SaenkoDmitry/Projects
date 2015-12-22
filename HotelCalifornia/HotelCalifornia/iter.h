#pragma once
template <class node, class T>
class iter
{
private:

	node* node_ptr;

public:

	iter(node* n)
		: node_ptr(n)
	{
	}
	iter()
		: node_ptr(0)
	{
	}
	T operator * ()
	{
		return node_ptr->get();
	}

	T operator *= (T t)
	{
		node_ptr->set(t);
		return node_ptr->get();
	}

	T* operator -> ()
	{
		return node_ptr->get();
	}

	node* get_ptr()
	{
		return node_ptr;
	}
	void operator ++ ()
	{
		node_ptr = node_ptr->next();
	}

	iter operator ++ (int)
	{
		iter iter(*this);
		++(*this);
		return iter;
	}


	void operator -- ()
	{
		if (node_ptr)
			node_ptr = node_ptr->prev();
		else
		{

		}
	}

	iter operator -- (int)
	{
		iter iter(*this);
		--(*this);
		return iter;
	}

	bool operator == (iter const& i)
	{
		return node_ptr == i.node_ptr;

	}

	bool operator != (iter const& i)
	{
		if (i.node_ptr)
			return node_ptr != i.node_ptr;
		else
			return node_ptr != 0;
	}

	void  dell()
	{
		node_ptr->get().~T();
		delete(node_ptr);
	}
};