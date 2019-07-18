#include <iostream>
#include <linked_list.h>

int main() {
	LinkedList ll;
	for (int i = 0; i <= 20; i++)
		ll.insert(i);

	std::cout << "List: "; ll.print();

	for (int i = 0; i <= 20; i += 2) {
		ll.remove(i);
		std::cout << "Removing " << i << " : "; ll.print();
	}


	ll.reverse();
	std::cout << "Reversed : "; ll.print();

	return 0;
}
