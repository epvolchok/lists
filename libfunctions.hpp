#pragma once
#include <iostream>
#include <memory>

#include "liblist.hpp"

struct add
{
	template <typename T>
	T operator () (const T& x, const T& y)
	{
		return x+y;
	}
};

template <typename T>
T sum(const my_list<T>& l);

template <typename Iter, typename T>
T accumulate( Iter it, Iter end,  T init );

template <typename Iter, typename T, typename BinaryFunc>
T accumulate( Iter it, Iter end,  T init, BinaryFunc op );

template <typename T>
std::ostream& operator<<(std::ostream& os, my_list<T>& l);

template <typename T>
T sum(const my_list<T>& l)
{
	T sum = 0;
	for (Node<T> * entry = l.ptr_head(); entry; entry = entry->get_next())
	{
		sum = sum + entry->get_data();
	}
	return sum;
}

template <typename Iter, typename T>
T accumulate( Iter it, Iter end,  T init )
{
	for (; it!=end; ++it)
		init += *it;
	return init;
}

template <typename Iter, typename T, typename BinaryFunc>
T accumulate( Iter it, Iter end,  T init, BinaryFunc op )
{
	for (; it!=end; ++it)
		init = op(init, *it);
		//init += *it;
	return init;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, my_list<T>& l)
{
	if (l.head)
	{
		for (Node<T> *entry=l.head; entry; entry=entry->get_next())
		os << entry->get_data() << " ";
	}
	else
		os << "Empty list";
	return os;
}