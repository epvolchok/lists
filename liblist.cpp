#include "liblist.hpp"

template < typename T>
T my_list<T>::get_head()
{
    /*
    Gets data from the head node
     */
    return head->get_data();
}

template < typename T>
T my_list<T>::get_tail()
{
    /*
    Gets data from the tail node
     */
    return tail->get_data();
}

template < typename T>
Node<T>* my_list<T>::ptr_head() const
{
    /*
    Returns a pointer to the head
    */
    return head;
}

template < typename T>
void my_list<T>::push_back(const T& x)
{
    /*
    Adds a node with data x to the end of the list
    */
    Node<T> * node = new Node(x);
    if ( head )
    {
        tail->set_next(node);
        tail = node;
    }
    else
    {
        head = node;
        tail = node;
    }
}

template < typename T>
void my_list<T>::push_head(const T& x)
{
    /*
    Adds a node with data x to the begining of the list,
    with the new node starting to be a new head
    */
    Node<T> * node = new Node(x);
    if ( head )
    {
        node->set_next(head);
        head = node;
    }
    else
    {
        head = node;
        tail = node; }
}

template < typename T>
void my_list<T>::push_after(const T& x, const T& y) //вставить y после x
{
    /*
    Adds a new node with data y after the node with data x
    */
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

template < typename T>
void my_list<T>::pop_back()
{
    /*
    Extracts the last node of the list
    */
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

template < typename T>
void my_list<T>::pop_head()
{
    /*
    Extracts the head of the list
    */
    if (head)
    {
        Node<T> *tmp = head->get_next();
        delete head;
        head = tmp;
    }
}

template < typename T>
void my_list<T>::pop(const T& x) //удалить по значению
{
    /*
    Deletes the first (from the begining) node with data = x
    */
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
                elete entry->get_next();
                entry->set_next(tmp2);
                break;
            }
            else 
                entry = entry->get_next();
        }
        }
    }
}

template < typename T>
list_iterator<T> my_list<T>::begin()
{
    /*
    Returns the pointer to the head?
    */
    return list_iterator<T>(head);
}

template < typename T>
list_iterator<T> my_list<T>::end()
{
    /*
    Returns the pointer to the tail?
    */
    return list_iterator<T>(0);
}