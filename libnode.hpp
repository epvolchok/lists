#pragma once
#include <iostream>

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

