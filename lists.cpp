#include <iostream>
#include <memory>
#include <initializer_list>
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
	
	T get_data()
	{
		return data;
	}
	
	Node * get_next()
	{
		return next_n;
	}
	
	void set_data(const T& d)
	{
		data = d;
	}
	void set_next(Node * n)
	{
		next_n = n;
	}
};

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
	T get_head()
	{
		return head->get_data();
	}
	T get_tail()
	{
		
		return tail->get_data();
	}
	Node<T>* ptr_head() const
	{
		return head;
	}
	void push_back(const T& x)
	{
		Node<T> * node = new Node(x);
		if ( head )
		 {
			 tail->set_next(node);
			 tail = node;
		 }
		else
		{	head = node;
			tail = node;
		}
	}
	void push_head(const T& x)
	{
		Node<T> * node = new Node(x);
		if ( head )
		 {
			 node->set_next(head);
			 head = node;
		 }
		 else
			{ head = node;
			  tail = node; }
	}
	void push_after(const T& x, const T& y) //вставить y после x
	{
		if (head)
		{
			Node<T> * entry = head;
			while (entry)
			{
				if (entry->get_data() == x)
				{
					Node<T> * tmp = new Node(y);
					tmp->set_next(entry->get_next());
					entry->set_next(tmp);
					if (entry == tail)
						tail = tmp;
					break;
				}
				entry = entry->get_next();
			}
		}
	}
	void pop_back()
	{
		if ( head )
		 {
			Node<T> * next = head->get_next();
			 while(next->get_next() != tail)
			 {next = next->get_next();}
			 delete tail;
			 tail = next;
			 tail->set_next(nullptr);
		 }
	}
	void pop_head()
	{
		if (head)
		{
			Node<T> *tmp = head->get_next();
			delete head;
			head = tmp;
		}
	}
	void pop(const T& x) //удалить по значению
	{
		if (head)
		{
			if (head->get_data() == x) 
			{ 
				pop_head();
			}
			else if (tail->get_data() == x)
			{
				pop_back();
			}
			else {
				Node<T> * entry = head;
				Node<T> * tmp1=new Node<T>, * tmp2=new Node<T>;
				while ( entry->get_next() != tail )
				{
					tmp1 = entry->get_next();
					tmp2 = tmp1->get_next();
					if  (tmp1->get_data() == x )
					{
						delete entry->get_next();
						entry->set_next(tmp2);
						break;
					}
					else 
					entry = entry->get_next();
				}
			}
		}
	}
	
	list_iterator<T> begin() { return list_iterator<T>(head); }
	list_iterator<T> end() { return list_iterator<T>(0); }
	
	friend 	std::ostream& operator<<<T>(std::ostream& os, my_list& l);
	
	
	
	
};

template <typename T>
class list_iterator
{
	Node<T>* entry;
	
	public:
	//using value_type = T;
	list_iterator(Node<T>* entry) : entry(entry) {}
	
	T operator*() {
		return entry->get_data(); }
	const T operator*() const {return entry->get_data(); }
	
	list_iterator<T> operator++()
	{ entry = entry->get_next(); 
		return *this;
	}
	
	bool operator!=(const list_iterator<T>& other) const
	{
		return entry != other.entry;
	}
	
};

struct add
{
	template <typename T>
	T operator () (const T& x, const T& y)
	{
		return x+y;
	}
};

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
