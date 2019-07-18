#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

class Node
{
    public:
        Node* next;
        int data;
};


class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

        void insert(int data);
        void remove(int data);
        void print();
        Node* search(int data);
        void reverse();

    private:
        Node *m_head;

};

#endif /* LINKEDLIST_H_ */
