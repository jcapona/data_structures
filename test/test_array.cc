#include <array.h>
#include <iostream>

int main () {
    Array<int> arr;
    for (int i=0; i<20; i++)
        arr.push(20-i);

    arr.print();
    std::cout << "Popping.. " << arr.pop() << "\n";
    std::cout << "Setting pos 2 to 99 ... \n";
    arr.push(123123);
    arr.set(2, 99999);
    arr.print();
    return 0;
}
