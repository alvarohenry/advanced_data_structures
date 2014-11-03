#include "PPLinkedList.h"

int main() {
	PPLinkedList<int> list;

	list.insertToTail(10);
	list.insertToTail(20);
	list.insertToTail(30);

	list.printLastV();

	list.updateNode(20, 80);
	cout << "nodo en la version 0 : " << list.readNode(80, 0) << endl ;
	cout << "nodo en la version 1 : " << list.readNode(80, 1) << endl ;
	list.updateNode(80, 100);

	cout << "nodo en la version 0 : " << list.readNode(100, 0) << endl ;
	cout << "nodo en la version 1 : " << list.readNode(100, 1) << endl ;
	cout << "nodo en la version 2 : " << list.readNode(100, 2) << endl ;

	list.updateNode(100, 99);
	cout << "nodo en la version 3 : " << list.readNode(100, 3) << endl ;


	list.printLastV();
}

