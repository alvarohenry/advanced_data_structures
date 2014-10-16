#include "PPLinkedList.h"

int main() {
	PPLinkedList<int> ll1(new Node<int>(7, 0));
	ll1.insertToHead(4);
	ll1.insertToTail(10);
	ll1.insertToTail(12);
	
	ll1.printLastV();
		
	ll1.updateNode(10, 1888);
	//ll1.updateNode(1888, 1234);

	ll1.printLastV();
	//ll1.updateNode(2, 82);

}
