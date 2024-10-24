template <class T> class SList;
template <class T> class SListIterator; 
template <class T> class SListNode;
#pragma once
#include "SList.h"

template <class T>
class SListIterator
{
public:
	SListNode<T>* currentNode;
	SList<T>* list;

	SListIterator<T> operator++();

	SListIterator<T> operator++(int i);

	

	SListIterator(SList<T> *l, SListNode<T> *n);
	void advance();
	void start();
	bool isValid();
	T& operator*();
	T& item();
};

template <class T> 
T& SListIterator<T>::operator*() {
    return currentNode->getData();
}

template <class T>
SListIterator<T> SListIterator<T>::operator++() {
	currentNode = currentNode->getNext();
	return *this;
}

template <class T>
SListIterator<T> SListIterator<T>::operator++(int i) {
	SListIterator<T> temp(*this);
	currentNode = currentNode->getNext();
	return temp;
}

template <class T>
SListIterator<T>::SListIterator(SList<T> *l, SListNode<T> *n)
{
	list = l;
	currentNode = n;
}
template <class T>
void SListIterator<T>::start()
{
	currentNode = list->head;
}
template <class T>
T& SListIterator<T>::item()
{
	return currentNode->getData();
}
template <class T>
bool SListIterator<T>::isValid()
{
	return currentNode != nullptr;
}
template <class T>
void SListIterator<T>::advance()
{
	if (currentNode == nullptr)
		return;
	currentNode = currentNode->getNext();
}
