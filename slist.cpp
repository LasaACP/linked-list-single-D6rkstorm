#include "slist.h"

/*

Class Library File

*/


// Constructor
template <class T>
List<T>::List(): tail(new Node(T())) { tail->next = tail; }

// Destructor

//add
//Uses Inline so defined in header

// clear()					//Removes all elements from this list.
template <class T>
void List<T>::clear() 
{ 
	iterator it = new iterator;
	while(!empty())
	{
		if (it==end()) return;
		if (it.ref->next == tail) tail = it.ref;
		Node* temp = it.ref->next;
		it.ref->next = it.ref->next->next;
		delete temp;
	} 
}

// equals(list)				//Returns true if the two lists contain the same elements in the same order.
	//Operator Overload in Header

//get(index)				//Returns the element at the specified index in this list.
template <class T>
T List<T>::get(int* index)
{
	iterator it = begin();
	int count = index;
	while (count > 0) 
	{
		count--;
		it++;
	}
	return *it;
}

//insert(index, value)		//Inserts the element into this list before the specified index.
template <class T>
void List<T>::insert(int* index, const T& value)
{
	iterator it = begin();
	int count = index-1;
	int i = -1;
	while(i < count)
	{
		it++;
		i++;
	}
	Node* temporary = new Node(value, it.ref->next);
	if(it.ref == tail)
		tail = temporary;
	it.ref->next = temporary;
}

//exchg(index1, index2)		//Switches the payload data of specified indexex.
template <class T>
void List<T>::exchg(const T& x,const T& y)
{
	iterator it = begin();
	int count = x;
	int i = -1;
	while(i < count)
	{
		it++;
		i++;
	}
	T temp = this->data;
	this->data = it.ref->next->data;
	it.ref->next->data = temp;
}

// isEmpty()				//Returns true if this list contains no elements.


// remove(index)			//Removes the element at the specified index from this list.
template <class T>
void List<T>::erase(iterator it) 
{
	if (it==end()) return;
	if (it.ref->next == tail) tail = it.ref;
	Node* temp = it.ref->next;
	it.ref->next = it.ref->next->next;
	delete temp;
}

// set(index, value)		//Replaces the element at the specified index in this list with a new value.
template <class T>
void List<T>::set(int index, const T& value)
{
	iterator it = begin();
	int count = index;
	int i = -1;
	while(i < count)
		{
		i++;
		it++;
		}
	this->data = value;
}

// size()					//Returns the number of elements in this list.
template <class T>
int List<T>::size()
{
	int count;
	Node* p = this.tail->next;
	while(p != this.tail)
	{		
		++count;
		p = p->next;
	}		
	return count;
}

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
template <class T> 
List<T> List<T>::subList(int start, int length)
{
	iterator it = begin();
	List link1 = new List;
	int count = start;
	int i = -1;
	int j = start;
	while(i < count)
		{i++;
			it++;}
	while(j < start + length)
	{
	link1.push_front(it.ref->data);
	j++;
	}
}