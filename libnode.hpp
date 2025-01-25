#pragma once
#include <iostream>
#include <memory>

template <typename T>
class Node;

template <typename T>
class Node
{
	private:
	T data;
	Node * next_n;
	
	public:
	Node() :data{0}, next_n{nullptr}
	{}
	Node(const T& data) : data(data), next_n(nullptr) {}

	
	T get_data();
		
	Node * get_next();
	
	void set_data(const T& d);

	void set_next(Node * n);
};

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

