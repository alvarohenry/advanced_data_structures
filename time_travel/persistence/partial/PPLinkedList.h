
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

		T searchVersion(int version, Node<T> *p);

		int getSize() { return size;}
		
		Node<T>* getNodeAt(int position);
		T readNode(T value, int version);// leer el dato value en la version v
		void updateNode(T value, T newvalue);
		//void deleteNode(int position)

		void print();
		void printLastV();
};

template<class T>
void PPLinkedList<T>::insertToTail(T val) {
	Node<T> *newNode = new Node<T>(val, 0);
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
	Node<T> *newNode = new Node<T>(val, 0);
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
	Node<T> *newNode = new Node<T>(val, 0);
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
void PPLinkedList<T>::printLastV() {
	Node<T> *current = head;
	while (current) {
		if (current->modData)
			cout << *(current->modData) << "," << current->version+1 << endl;
		else
			cout << current->data << "," << current->version << endl;	
		if (current->modPointer)
			current = current->modPointer;
		else
			current = current->next;	
	}
	cout << "NULL" << endl;
}	

template<class T>
T PPLinkedList<T>::readNode(T value, int version) {
    Node<T> *p = head;
    while (p) {
        if ((p->modData != 0 && *p->modData == value) || p->modData == NULL && p->data == value) // buscar la version
            return searchVersion(version, p);        
        else
            if (p->modPointer != NULL)
                p = p->modPointer;
            else
                p = p->next;
    }
}

template<class T>
T PPLinkedList<T>::searchVersion(int version, Node<T> *p) {
    int nOldNodes = p->version/2;
    int backSteps = nOldNodes - version%2;
    for (int i = 1; i <= backSteps; i++) {
		p = p->backpointer->next;
	}
	return version%2 == 0 ? p->modData : p->data;
}

template<class T>
void PPLinkedList<T>::updateNode(T value, T newValue) {	
	cout << "asdfadfadsfa";
    Node<T> *p = head;
    while (p) {
		cout << "asdfadfadsfa";
        if (p->modData == 0 && p->data == value) {
			p->modData = new T;
			*(p->modData) = newValue;
		} else {
			if (*p->modData == value) {
				Node<T> *newNode = new Node<T>(newValue,p->version+2);
				newNode->next = p->next;
				newNode->backpointer = p->backpointer;
				if (newNode->next != NULL)
					newNode->next->backpointer = newNode;
				if (newNode->backpointer != NULL)
					newNode->backpointer->modPointer = newNode;
			}
		}
	}	
}


