
#include <iostream>
#include "Node.h"

using namespace std;

// PP means partial persistence
template<class T>
class PPLinkedList {
	public:
		Node<T> *head;
		Node<T> *tail;
		long size;

		PPLinkedList(): head(NULL), tail(NULL), size(0) {}
		PPLinkedList(Node<T>* newNode) : head(newNode), tail(newNode), size(1) {}
		void insertToHead(T val);
		void insertToTail(T val);
		void insertAt(int position, T val);

		int getSize() { return size;}

		T readNode(int position, int version);
		void updateNode(int position, T value);
		//void deleteNode(int position)

		void print();
};

template<class T>
void PPLinkedList<T>::insertToTail(T val) {
	Node<T> *newNode = new Node<T>(val);
	if (tail == NULL) {
		newNode->next = tail;
		tail = newNode;
		head = newNode;
	}
	tail->next = newNode;
	tail = tail->next;
	size++;
}


template<class T>
void PPLinkedList<T>::insertToHead(T val) {
	Node<T> *newNode = new Node<T>(val);
	newNode->next = head;
	head = newNode;
	if (head->next == NULL) {
		tail = newNode;
	}
	size++;
}

template<class T>
void PPLinkedList<T>::insertAt(int position, T val) {
	if (position >= size) {
		return;
	}
	if (position == 0) {
		insertToHead(val);
		return;
	}
	if (position == size - 1) {	
		insertToTail(val);
		return;
	}
	Node<T> *temp = head;
	while (position != 1) {
		temp = temp->next;
		position--;
	}
	Node<T> *newNode = new Node<T>(val);
	newNode->next = temp->next;
	temp->next = newNode;
	size++;
}

template<class T>
void PPLinkedList<T>::print() {
	Node<T> *current = head;
	while (current) {
		cout << current->data << " --> ";
		current = current->next;
	}
	cout << "NULL" << endl;
}	

template<class T>
T PPLinkedList<T>::readNode(int position, int version) {
	//Node<T> *temp;
	/*if (position <= size/2) {
		temp = head;
		while (temp->next != NULL) {
			
		}
	} else {
		temp tail;
	}*/
}

