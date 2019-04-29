#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename Tr>
class List {
public:
    typedef typename Tr::T T;
    typedef typename Tr::Operation Operation;

private:
    Node<T>* head;
    Operation cmp;
    int nodes;

public:
    List() : head(nullptr), nodes(0) {};

    bool find(T search, Node<T> **&pointer) {
        pointer = &head;
        while (*pointer != NULL && !cmp(search, (*pointer)->data))
            pointer = &((*pointer)->next);
        return *pointer != NULL && (*pointer)->data == search;
    }

    bool insert(T data) {
        Node<T> *newNode = new Node<T>(data);
        Node<T> **tempNode;
        if (find(data, tempNode)) return false;

        newNode->next = *tempNode;
        *tempNode = newNode;
        ++nodes;
        return true;
    }

    bool remove(T item) {
        Node<T> **tempNode;
        if (!find(item, tempNode)) return false;

        Node<T> *newNode = *tempNode;
        *tempNode = (*tempNode)->next;
        --nodes;
        delete newNode;
        return true;
    }

    int size() {
        return nodes;
    }

    T operator[](int index) {
        Node<T> *tempNode = head;
        for (int i = 0; i < index; i++)
            tempNode = tempNode->next;
        return tempNode->data ;
    }

    ~List() {
	// Falta controlar cuando head es null, si la lista está vacía
        head->killSelf();
    }
};

#endif
