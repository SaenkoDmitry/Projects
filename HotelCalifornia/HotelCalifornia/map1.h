#pragma once
#include "iter.h"
#include "map_node.h"
template <class T, class T1>
class map1
{
private:
	typedef map_node<T, T1> node;
	node* root;

public:

	friend class iter<node, T>;
	typedef iter<node, T>  iter;

	map1()
		: root(0)
	{
	}

	~map1()
	{
		while (root->next_node)
		{
			//cout<<" * "<<(int)(root->next_node->get()->val) << "  "<<endl; 
			delete root->next_node;
		}
		//cout<<"// "<<(int)(root->get()->val) << "  "<<endl; 
		if (root)
			delete root;
	}

	void push(T const& t)
	{
		node* tmp;
		if (root)
		{
			tmp = root;
			while (tmp->next_node)
			{
				tmp = tmp->next_node;
			}

			tmp->next_node = new node(t);
			tmp->next_node->prev_node = tmp;
		}
		else
		{
			root = new node(t);
		}
		sort();
	}

	iter begin()
	{
		return iter(root);
	}

	iter end()
	{
		return iter(0);
	}

	void  erease(iter a)
	{
		node* tmp;
		tmp = a.get_ptr();
		if (tmp == root)
			root = tmp->next_node;
		a.dell();
	}

	T1 map1<T, T1>::find(T a)
	{
		if (root != nullptr)
		{
			node * node1 = t;
			while (node1 != nullptr && node1->key != a)
			{
				node1 = node1->next_node;
			}
			if (node1 != nullptr)
			{
				return node1->object;
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

	int count() {
		iter i;
		int c = 0;
		i = begin();
		while (i != end()) {
			c++;
			i++;
		}
		return c;
	};
	void  swap(iter a, iter b)
	{
		node* a_ptr;
		node* b_ptr;
		node* tmp1;
		node* tmp2;
		node* tmp3;
		node* tmp4;
		a_ptr = a.get_ptr();
		b_ptr = b.get_ptr();
		if (a_ptr == root)
		{
			root = b_ptr;
		}
		else
			if (b_ptr == root)
			{
				root = a_ptr;
			}

		if (a != b)
		{
			tmp1 = a_ptr->prev_node;
			tmp2 = a_ptr->next_node;
			tmp3 = b_ptr->prev_node;
			tmp4 = b_ptr->next_node;

			//cout<<(int)tmp1<<"  "<<(int)a_ptr<<"  "<<(int)tmp2<<"  |  "<<(int)tmp3<<"  "<<(int)b_ptr<<" "<<(int)tmp4<<endl;
			//cout<<(int)(a_ptr->get()->val) << "  " <<(int)(b_ptr->get()->val)<<"  root "<<(int)(root)<<endl;

			if (a_ptr == tmp3)
			{
				//cout<<" a_ptr==tmp3 1 "<<endl;
				if (tmp1)
					tmp1->next_node = b_ptr;
				if (b_ptr)
					b_ptr->prev_node = tmp1;
				if (a_ptr)
					a_ptr->prev_node = b_ptr;
				if (b_ptr)
					b_ptr->next_node = a_ptr;
				if (a_ptr)
					a_ptr->next_node = tmp4;
				if (tmp4)
					tmp4->prev_node = a_ptr;
			}
			else
			{
				if (b_ptr == tmp1)
				{
					//cout<<" b_ptr==tmp1 2 "<<endl;
					if (tmp3)
						tmp3->next_node = a_ptr;
					if (a_ptr)
						a_ptr->prev_node = tmp3;
					if (b_ptr)
						b_ptr->prev_node = a_ptr;
					if (a_ptr)
						a_ptr->next_node = b_ptr;
					if (b_ptr)
						b_ptr->next_node = tmp2;
					if (tmp2)
						tmp2->prev_node = b_ptr;


				}
				else
				{
					//cout<<" 33333 "<<endl;
					if (tmp1)
						tmp1->next_node = b_ptr;
					if (b_ptr)
						b_ptr->prev_node = tmp1;
					if (a_ptr)
						a_ptr->prev_node = tmp3;
					if (a_ptr)
						a_ptr->next_node = tmp4;
					if (b_ptr)
						b_ptr->next_node = tmp2;
					if (tmp3)
						tmp3->next_node = a_ptr;
					if (tmp4)
						tmp4->prev_node = a_ptr;
					if (tmp2)
						tmp2->prev_node = b_ptr;
				}
			}
			//cout<<(int)a_ptr->prev_node<<"  "<<(int)a_ptr<<"  "<<(int)a_ptr->next_node<<"  |  "<<(int)b_ptr->prev_node<<"  "<<(int)b_ptr<<" "<<(int)b_ptr->next_node<<endl;
			//cout<<(int)(a_ptr->get()->val) << "  " <<(int)(b_ptr->get()->val)<<"  root "<<(int)(root)<<endl;        
		}
	}


	void sort(bool(*comp)(iter a, iter b))
	{
		iter i, j, k;
		int c = 0;
		i = begin();
		//cout << " count  "<<count() <<endl;
		while (c < count())
		{
			j = i;
			k = j++;
			while (j != end())
			{
				k = j;
				k--;
				//cout<<"j "<<(int)(j.get_ptr()->get()->val)<<"    k  "<<(int)(k.get_ptr()->get()->val)<<endl;
				if (k == end())
					break;
				if (comp(j, k))
					swap(j, k);
				j++;
			}
			//cout<<"!---------"<<(int)(i.get_ptr()->get()->val)<<"  "<<endl;
			c++;
			i = begin();
		}
	};
};