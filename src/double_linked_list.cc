#include <double_linked_list.h>


template <class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    this->m_head = NULL;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    while (!this->remove(0)){
    }
}

template <class T>
int DoubleLinkedList<T>::remove(int pos) {
    DLNode<T> *n = this->m_head;
    for (int i = 0; i <= pos - 1 && n != NULL; i++)
        n = n->next;

    if (n == NULL)
        return 1;

    if (n->next) 
        n->next->prev = n->prev;
    
    if (n->prev == NULL)
        this->m_head = n->next;
    else
        n->prev->next = n->next;

    delete n;
    return 0;
}

template <class T>
DLNode<T> DoubleLinkedList<T>::search(T data) {
    DLNode<T> *n = this->m_head;
    while (n && n->data != data)
        n = n->next;
    return *n;
}

template <class T>
DLNode<T>* DoubleLinkedList<T>::create_node(T data) {
    DLNode<T> *n = new DLNode<T>();
    if (n == NULL)
        return NULL;

    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

template <class T>
void DoubleLinkedList<T>::insert_at_pos(int pos, T data) {
    DLNode<T> *n = this->create_node(data);

    DLNode<T> *aux = this->m_head;
    for (int i = 0; i <= pos - 1 && aux != NULL; i++)
        aux = aux->next;

    n->next = aux;
    n->prev = aux->prev;

    if (aux->prev == NULL) {
         this->m_head = n;
         return ;
    }

    aux->prev->next = n;
    aux->prev = n;
}

template <class T>
void DoubleLinkedList<T>::insert_at_front(T data) {
    DLNode<T> *n = this->create_node(data);

    DLNode<T> *aux = this->m_head;
    if (aux) {
        n->next = aux;
        aux->prev = n;
    }
    this->m_head = n;
}

template <class T>
void DoubleLinkedList<T>::insert_at_back(T data) {
    DLNode<T> *n = this->create_node(data);

    DLNode<T> *aux = this->m_head;
    if (aux == NULL) {
        this->m_head = n;
        return ;
    }

    while (aux->next)
        aux = aux->next;

    aux->next = n;
    n->prev = aux;
}

template <class T>
void DoubleLinkedList<T>::print() {
    DLNode<T> *n = this->m_head;
    while (n) {
        std::cout << n->data << " ";
        n = n->next;
    }
    std::cout << std::endl;
}

template class DoubleLinkedList<int>;
