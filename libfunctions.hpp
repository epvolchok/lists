#pragma once
#include <iostream>
#include <memory>

#include "liblist.hpp"

struct add;

template <typename T>
T sum(const my_list<T>& l);

template <typename Iter, typename T>
T accumulate( Iter it, Iter end,  T init );

template <typename Iter, typename T, typename BinaryFunc>
T accumulate( Iter it, Iter end,  T init, BinaryFunc op );

template <typename T>
std::ostream& operator<<(std::ostream& os, my_list<T>& l);