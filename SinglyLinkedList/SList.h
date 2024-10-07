#pragma once
#include "SListIterator.h"
template <class T>
class SList
{
public:
	SListNode<T> *head, *tail;
	SList();
	void append(T data);
	void prepend(T data);
	void removeHead();
	void removeTail();
	void remove(SListIterator<T> iter);
	SListIterator<T> getIterator();
	void insert(SListIterator<T> iter, T data);
	~SList();

};
template <class T>
void SList<T>::remove(SListIterator<T> iter)
{
	
}
template <class T>
void SList<T>::insert(SListIterator<T> iter, T data)
{
	

}

template <class T>
SListIterator<T> SList<T>::getIterator()
{
	return SListIterator<T>(this, head);
}
template <class T>
void SList<T>::removeHead()
{
	
}

template <class T>
void SList<T>::removeTail()
{

}
template <class T>
SList<T>::SList()
{
	head = tail = nullptr;
}

template <class T>
void SList<T>::append(T data)
{
	
}
template <class T>
void SList<T>::prepend(T data)
{
	
}

template <class T>
SList<T>::~SList()
{
	SListNode<T>* current = head;
	while (current != 0) {
		SListNode<T>* next = current->getNext();
		delete current;
		current = next;
	}
	head = 0;
}