#include <iostream>
#include <string>

using namespace std;

template<class T>
class Node {
	public:
		T data;
		int version;
		Node<T>* next;
		Node<T>* backpointer;	// p
		T* modData;
		Node<T> *modPointer;	// 2p
		
		Node<T>(const T& d, int ver) : data(d), next(0), version(ver), modData(0), modPointer(0) {}

		bool addModValue(T* value) ;
		bool addModPointer(Node<T> *pointer) ;
		T getDataAtVersion(int version);
};

template<class T>
bool Node<T>::addModValue(T* value) {
	if (modData == NULL) {
		modData = value;
		return true;
	} 
	return false;
}

template<class T>
bool Node<T>::addModPointer(Node<T>* pointer) {
	if (modPointer == NULL) {
		modPointer = pointer;
		return true;
	} 
	return false;
}

template<class T>
T Node<T>::getDataAtVersion(int version) {
	return data;
}


