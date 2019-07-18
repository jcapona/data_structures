#ifndef DLINKEDLIST_H_
#define DLINKEDLIST_H_

#include <iostream>

template <class T>
class DLNode {
    public:
        T data;
        DLNode<T> *next;
        DLNode<T> *prev;
};

template <class T>
class DoubleLinkedList {
    public:
        DoubleLinkedList();
        ~DoubleLinkedList();

        void insert_at_front(T data);
        void insert_at_back(T data);
        void insert_at_pos(int pos, T data);
        int remove(int pos);
        DLNode<T> search(T data);
        void print();
        void fullprint();
    private:
        DLNode<T> *m_head;
        DLNode<T>* create_node(T data);
};

#endif /* LINKEDLIST_H_ */
