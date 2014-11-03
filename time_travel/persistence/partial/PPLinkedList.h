#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class PPLinkedList {
	public:
		Node<T>* head;
		Node<T>* tail;

		PPLinkedList(): head(NULL), tail(NULL) {}
		PPLinkedList(Node<T>* newNode) : head(newNode), tail(newNode) {}

		void insertToTail(T val);
		void printLastV();
		T readNode(T value, int version);
		T searchVersion(int version, Node<T>* temp);
		void updateNode(T value, T newValue);

};

template<class T>
void PPLinkedList<T>::insertToTail(T val) {
	Node<T>* newNode = new Node<T>(val, 0);
	if (tail == NULL) {
		tail = newNode;
		head = newNode;
	}
	newNode->back_pointer = tail;
	tail->next = newNode;
	tail = newNode;
}

template<class T>
void PPLinkedList<T>::printLastV() {
	Node<T>* current = head;
	while (current) {
		if (current->mod_data)
			cout << *(current->mod_data) << " , " << current->version+1 << endl;
		else
			cout << current->data << " , " << current->version << endl;	
		if (current->mod_pointer)
			current = current->mod_pointer;
		else
			current = current->next;	
	}
	cout << "NULL" << endl << endl;
}	

template<class T>
T PPLinkedList<T>::readNode(T value, int version) {
	Node<T>* temp = head;
	while(temp) {
		if((temp->mod_data != NULL && *(temp->mod_data) == value) || 
						(temp->mod_data == NULL && temp->data == value)) {
			// estoy en el nodo, ahora busco la version
			return searchVersion(version, temp);
		} else {
			// busco el valor VALUE en otros nodos hasta encontrarlo
			if (temp->mod_pointer != NULL) {
				temp = temp->mod_pointer;
			} else {
				temp = temp->next;
			}
		}
	}
}

template<class T>
void PPLinkedList<T>::updateNode(T value, T newValue) {
	Node<T>* temp = head;
	while (temp) {
		//cout << "en el while" << value << " , newValue " << newValue << endl;
		if((temp->mod_data != NULL && *(temp->mod_data) == value) || 
						(temp->mod_data == NULL && temp->data == value)) {
			// estoy en el nodo, adiciono la modificacion o creo un nuevo nodo version
			//cout << "EN EL NODO " << temp->data << " , " << newValue << endl;
			if (temp->mod_data == NULL && temp->data == value) {
				temp->addModValue(newValue);
				break;
			} else {
				cout << "EL CASO MAS FODAAAA" << endl;
				Node<T>* newNode = new Node<T>(newValue, temp->version+2);
				newNode->next = temp->next;
				newNode->back_pointer = temp->back_pointer;
				if (newNode->next != NULL)
					newNode->next->back_pointer = newNode;
				if (newNode->back_pointer != NULL)
					newNode->back_pointer->mod_pointer = newNode;
				break;
			}

		} else {
			// busco el valor VALUE en otros nodos hasta encontrarlo
			if (temp->mod_pointer != NULL) {
				temp = temp->mod_pointer;
			} else {
				temp = temp->next;
			}
		}
	}
}

template<class T>
T PPLinkedList<T>::searchVersion(int version, Node<T>* temp) {
	if (version > temp->version)
		return temp->mod_data == NULL ? temp->data : *(temp->mod_data);
	int nOldNodes = temp->version / 2;
	int backSteps = nOldNodes - version/2;
	cout << "nOldNodes : " << nOldNodes << " backSteps : " << backSteps << endl; 
	for (int i = 0; i < backSteps; i++) {
		cout << "datos del temp : " << temp->data << endl;
		temp = temp->back_pointer->next;
	}
	if (version%2 == 0) {
		return temp->data;
	}
	return *(temp->mod_data);
}

