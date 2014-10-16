#include "PPLinkedList.h"

int main() {
	PPLinkedList<int> ll1(new Node<int>(7));
	ll1.print();
	cout << "tamanho da lista :" << ll1.getSize()<<endl;

	ll1.insertToHead(4);
	ll1.print();
	cout << "tamanho da lista :" << ll1.getSize()<<endl;

	ll1.insertToTail(10);
	ll1.print();
	cout << "tamanho da lista :" << ll1.getSize()<<endl;

	ll1.insertAt(1, 5);
	ll1.print();
	cout << "tamanho da lista :" << ll1.getSize()<<endl;

	ll1.insertAt(10, 1);
	ll1.print();
	cout << "tamanho da lista :" << ll1.getSize()<<endl;

	ll1.insertAt(3, 133);
	ll1.print();
	cout << "tamanho da lista :" << ll1.getSize()<<endl;

	ll1.insertAt(3, 15);
	ll1.print();
	cout << "tamanho da lista :" << ll1.getSize()<<endl;

}
