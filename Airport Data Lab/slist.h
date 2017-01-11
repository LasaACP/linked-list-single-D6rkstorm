#ifndef __SLIST_H_INCLUDED__
#define __SLIST_H_INCLUDED__
#include <iterator>

template <class T>
class List {
	// node structure
	struct Node {
		Node(T x, Node* y = 0): data(x), next(y) {}
		// data of this node
		T data;
		// node in next position
		Node* next;
	};
	// node at tail end of list
	Node* tail;

public:

	class iterator: public std::iterator<std::forward_iterator_tag, T> 
	{
		// node this iterator is referencing
		Node* ref;
	public:
		friend class List;
		friend class const_iterator;

		// type definitions
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef int difference_type;
		typedef std::forward_iterator_tag iterator_category;

		inline iterator(Node* x = 0): ref(x) {}
		inline iterator(const iterator& x): ref(x.ref) {}
		inline iterator& operator=(const iterator& it) { this->ref = it.ref; return *this; }
		inline iterator& operator++() { this->ref = this->ref->next; return *this; }
		inline iterator operator++(int) { iterator it(*this); this->ref = this->ref->next; return it; }
		inline typename List<T>::iterator::reference operator*() const { return this->ref->next->data; }
		inline typename List<T>::iterator::pointer operator->() const { return this->ref->next; }
		inline bool operator==(const iterator& x) const { return this->ref == x.ref; }
		inline bool operator!=(const iterator& x) const { return this->ref != x.ref; }
	};

List();
// isEmpty()				//Returns true if this list contains no elements.
inline bool empty() { return tail == tail->next; }
//insert(index, value)		//Inserts the element into this list before the specified index.
void insert(int*, const T&);
// get iterator at beginning
inline iterator begin() { return iterator(tail->next); }
// add(value)				//Adds a new value to the end of this list.
inline void add(const T& x) { insert(begin(), x); }

inline iterator end() { return iterator(tail); }
// clear()					//Removes all elements from this list.
void clear();
// equals(list)				//Returns true if the two lists contain the same elements in the same order.
inline List& operator==(const List& l) { return this->tail == l.tail;}
//get(index)				//Returns the element at the specified index in this list.
T get(int*);
//exchg(index1, index2)		//Switches the payload data of specified indexex.
void exchg(const T& x,const T& y);

// remove(index)			//Removes the element at the specified index from this list.
void erase(iterator it);
// set(index, value)		//Replaces the element at the specified index in this list with a new value.
void set(int index, const T& value);
// size()					//Returns the number of elements in this list.
int size();
// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
List subList(int start, int length);

};
#endif
