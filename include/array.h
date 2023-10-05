// https://stackoverflow.com/questions/3246803/why-use-ifndef-class-h-and-define-class-h-in-h-file-but-not-in-cpp
#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
// template class declaration
template <class T>
class Array {
    public:
        // constructor
        Array();
        // deconstructor
        ~Array();

        //  method to add elements to the dynamic array
        void push(T value);

        // returns the value at the top of the array, and removes it from the array
        T pop();
        // inserts an element into the array at a given index, if they index is larger than the existing size of the array
        // array is extended and filled with zeros
        void set(size_t index, T value);
        //fetches the value in the array at a given index
        T get(size_t index);
        // returns the current size of the array
        size_t size();
        //returns the current capacity of they array
        size_t capacity();
        void print();
        int is_empty();

    private:
        // the current size of the array
        size_t m_size;
        // the current capacity of the array
        size_t m_capacity;
        // pointer to the data of the array
        T* m_data;
        // method to increase the size of the array
        void resize();
};

#endif /* ARRAY_H_ */
