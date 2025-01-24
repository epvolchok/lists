#include <iostream>
#include <memory>
#include <initializer_list>

#include "liblist.hpp"
#include "libfunctions.hpp"

int main()
{
	my_list<int> l;
	Node n(1);
	std::cout<<n.get_data()<<std::endl;
	l.push_back(10);
	l.push_back(2);
	l.push_back(3);
	//int data = l.get_head();
	std::cout<<l.get_tail()<<std::endl;
	l.push_after(3,5);
	std::cout<<l<<std::endl;
	my_list l2{1, 2, 3, 4, 5, 6};
	std::cout<<l2<<std::endl;
	l2.pop(6);
	std::cout<<l2<<std::endl;
	std::cout<<sum(l2)<<std::endl;
	std::cout<<accumulate(l2.begin(), l2.end(), 0)<<std::endl;
	std::cout<<accumulate(l2.begin(), l2.end(), 0, add{})<<std::endl;
	return 0;
}
