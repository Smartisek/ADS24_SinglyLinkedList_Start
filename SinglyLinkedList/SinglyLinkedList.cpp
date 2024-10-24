// SinglyLinkedList.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "SList.h"
using namespace std;


int main()
{
	srand(time(0));

	SList<int> lst;
	for (int i = 0; i < 15; i++) {
		int randomValue = (std::rand() % 10) + 1;
		lst.append(i + randomValue);
	}


	SListIterator<int> it = lst.getIterator();
	while (it.isValid()) {
		cout << *it << " ";
		it++;
	}

	
	return 0;
}

