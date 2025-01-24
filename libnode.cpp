#include <iostream>
#include "libnode.hpp"

template < typename T>
T Node<T>::get_data()
{
    return data;
}

template < typename T>
Node<T> * Node<T>::get_next()
{
    return next_n;
}

template < typename T>
void Node<T>::set_data(const T& d)
{
    data = d;
}

template < typename T>
void Node<T>::set_next(Node<T> * n)
{
    next_n = n;
}

/*
int main()
{
    Node n(1);
	std::cout<<n.get_data()<<std::endl;

    return 0;
}
*/