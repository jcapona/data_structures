#include <array.h>

#include <stdexcept>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MIN_CAPACITY 10
#define GROWTH_FACTOR 2

// constructor of our dynamic array
template <class T>
Array<T>::Array() {
    // the dynamic array can stores at least 10 elements in the beginning
    m_capacity = MIN_CAPACITY;
    // initial size is 0, i.e the the pointer after initialization of they array is at 0th index
    m_size = 0;
    // equivalent to T m_data[m_capacity]; (allocates memory block on heap)
    m_data = (T*)malloc(m_capacity * sizeof(*m_data));
    // ensuring nothing goes wrong during malloc
    if (!m_data)
        throw std::bad_alloc();
}
// deconstrcutor of our dynamic array (de-allocates memory block on heap)
template <class T>
Array<T>::~Array() {
    free(m_data);
}

// given a value to be inserted, inserts it the top of the array
template <class T>
void Array<T>::push(T value) {
    // if current size of the array is greater or equal to maximum capacity, therefore it is time to expand the array
    if (m_size >= m_capacity)
        resize();
    *(m_data + m_size++) = value;
}

// deletes and returns the top element of the array
template <class T>
T Array<T>::pop() {
    return *(m_data + --m_size);
}

// insert element in the array at a given index, if index is beyond the current size, expand the array, and then insert
// fill the indices leading upto the index with zeros.
template <class T>
void Array<T>::set(size_t index, T value) {
    while (index >= m_size)
        this->push(0);
    *(m_data + index) = value;
}

// returns the element stored a given index
template <class T>
T Array<T>::get(size_t index) {
    return *(m_data + index);
}

//returns the current size of the array
template <class T>
size_t Array<T>::size() {
    return m_size;
}
// returns the current capacity of the array
template <class T>
size_t Array<T>::capacity() {
    return m_capacity;
}

// expands the array by growth factor, i.e if GROWTH_FACTOR = 2, each time we expand, we double the capacity.
template <class T>
void Array<T>::resize() {
    size_t capacity = m_capacity*GROWTH_FACTOR;
    // realloc is slightly different than malloc, it takes current stored data, copies it into new location with bigger chunk of contiguos memory.
    // https://www.geeksforgeeks.org/g-fact-66/
    T *tmp = (T*)realloc(m_data, capacity * sizeof(*m_data));
    // call to realloc or malloc can lead to them returning null (error), so we must check for that
    if (!tmp) //if null
        throw std::bad_alloc();
    // reassign m_data to new pointed location, where the expanded array is stored
    m_data = tmp;
    // new increased capacity of array
    m_capacity = capacity;
}

template <class T>
void Array<T>::print() {
    size_t i = 0;
    // print all the elements of the array
    while (i < m_size) {
        std::cout << "Array[" << i << "] = " << this->get(i) << "\n";
        i++;
    }
}

//returns true or false about whether the array is empty
template <class T>
int Array<T>::is_empty() {
    return m_size == 0;
}

template class Array<int>;
template class Array<float>;
template class Array<std::string>;
