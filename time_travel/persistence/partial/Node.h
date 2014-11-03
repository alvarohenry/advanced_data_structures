#include <iostream>
#include <string>

using namespace std;

template<class T>
class Node {
	public:
		T data;
		int version;
		Node<T>* next;
		Node<T>* back_pointer;
		T* mod_data;
		Node<T>* mod_pointer;

		Node<T>(const T& d, int ver) : data(d), next(NULL), version(ver), mod_data(NULL), mod_pointer(NULL) {}

		bool addModValue(T value) ;
		bool addModPointer(Node<T>* pointer) ;
		T getDataAtVersion(int version);
		
};

template<class T>
bool Node<T>::addModValue(T value) {
	if (mod_data == NULL) {
		mod_data = new T;
		*mod_data = value;
		cout << value << " este es el valor de mod_data" << *mod_data << endl;
		return true;
	} 
	return false;
}

template<class T>
bool Node<T>::addModPointer(Node<T>* pointer) {
	if (mod_pointer == NULL) {
		mod_pointer = pointer;
		return true;
	} 
	return false;
}

template<class T>
T Node<T>::getDataAtVersion(int version) {
	return data;
}


