#pragma once
#include <iostream>
#include <memory>
#include <initializer_list>

#include "libnode.hpp"

template <typename T>
class my_list;

template <typename T>
class list_iterator;

template < typename T>
std::ostream& operator<<(std::ostream& os, my_list<T>& v);


template <typename T>
class my_list
{
	private:
	Node<T> *head, * tail;
	
	public:
	my_list() : head{nullptr}, tail{nullptr} {}
	my_list(const std::initializer_list<T> &values) : head(), tail()
	{
		Node<T> * tmp = new Node<T>;
		head = tmp;
		for (auto it : values)
		{
			tmp->set_data(it);
			Node<T>  *tmp2 = new Node<T>;
			tmp->set_next(tmp2);
		
			if (it == *(values.end()-1))
			{	tmp->set_next(nullptr);
				 tail = tmp; 
			}
			else
			tmp = tmp->get_next();
		}
		
		
	}

	~my_list()
	{
		while(head)
		{
			Node<T> *tmp=head->get_next();
			delete head;
			head = tmp;
		}
	}

    T get_head();
    T get_tail();
    Node<T>* ptr_head() const;
    void push_back(const T& x);
    void push_head(const T& x);
    void push_after(const T& x, const T& y);
    void pop_back();
    void pop_head();
    void pop(const T& x);

    list_iterator<T> begin();
    list_iterator<T> end();
};

