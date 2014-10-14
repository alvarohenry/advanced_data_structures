#include <iostream>
#include <string>

using namespace std;

template<class T>
class Mod {
	public:	
		int version;
		string field;
		T value;
		Mod(int ver, string f, T val) : version(ver), field(f), value(val) {}
};

template<class T>
class Node {
	private:
		T data;
		Node* next;
		Node* backpointer;	// p
		Mod mods[2];		// 2p
	public:
		Node<T>()		
}


