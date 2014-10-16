#include <iostream>
#include <string>

using namespace std;

template<class T>
class Mod {
	public:	
		int version;
		string field;
		T value;
		Mod() {}
		Mod(int ver, string f, T val) : version(ver), field(f), value(val) {}
};

template<class T>
class Node {
	public:
		T data;
		Node<T>* next;
		Node<T>* backpointer;	// p
		Mod<T> mods[2];		// 2p
		Node<T>(const T& d) : data(d), next() {}

		void addMod(T value);
		void isNodeFull();
};

template<class T>
void Node<T>::isNodeFull() {
	return mods[0] != NULL && mods[1] != NULL;
}

template<class T>
void Node<T>::addMod(T value) {
	if (mods[0] == NULL) {
		mods[0] = new Mod<T>(version++, data, value);
	} else {
		mods[1] = new Mod<T>(version++, data, value);
	}
}




