#include <iostream>
#include <double_linked_list.h>

int MAX = 10;

int main(void) {
	DoubleLinkedList<int> dll = DoubleLinkedList<int>();
	for (int i = 0; i <= MAX; i++) {
		dll.insert_at_front(i);
		dll.insert_at_back(MAX - i);
		std::cout << "Inserting " << i << " at the front and " << MAX - i << " at the back: "; dll.print();
	}

	std::cout << "\nList : "; dll.print();
	for (int i = 0; i <= MAX; i++) {
		dll.insert_at_pos(MAX - i, i*100);
		std::cout << "Inserting " << i*100 << " at pos " << MAX - i << " : "; dll.print();
	}

	std::cout << "\nList : "; dll.print();
	for (int i = 0; i <= MAX; i++) {
		dll.remove(i);
		std::cout << "Removing node from pos " << i << " : "; dll.print();
	}

	std::cout << "\nList : "; dll.print();
	for (int i = 0; i <= MAX; i++) {
		DLNode<int> n = dll.search(i);
		DLNode<int> *prev = NULL;
		DLNode<int> *next = NULL;

		if (n.prev)
		    prev = n.prev;
		if (n.next)
		    next = n.next;

		std::cout << "Searching node with data " << i << " : ";
		if (prev) std::cout << "(prev data) " << prev->data << " -- ";
		std::cout << n.data ;
		if (next) std::cout << " -- (next data) " << next->data;
		std::cout << std::endl; 
	}

	return 0;
}
