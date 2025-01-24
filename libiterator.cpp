#include "liblist.hpp"

template <typename T>
class list_iterator
{
	Node<T>* entry;
	
	public:
	//using value_type = T;
	list_iterator(Node<T>* entry) : entry(entry) {}
	
	T operator*()
    {
		return entry->get_data();
    }

	const T operator*() const
    {
        return entry->get_data();
    }
	
	list_iterator<T> operator++()
	{
        entry = entry->get_next(); 
		return *this;
	}
	
	bool operator!=(const list_iterator<T>& other) const
	{
		return entry != other.entry;
	}
	
};