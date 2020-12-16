//
// Created by 朱星宇 on 2020/7/21.
//

#ifndef P3_DLIST_IMPL_H
#define P3_DLIST_IMPL_H

#include "dlist.h"

//returns true if list is empty, false otherwise
template<class T>
bool Dlist<T>::isEmpty() const {
    return !first;
}

// inserts o at the front of the list
template<class T>
void Dlist<T>::insertFront(T *op) {
    node* np = new node;
    np->op = op;
    np->next = first;
    np->prev = nullptr;
    if (isEmpty()) {
        first = np;
        last = np;
    } else {
        first->prev = np;
        first = np;
    }
}

// inserts o at the back of the list
template<class T>
void Dlist<T>::insertBack(T *op) {
    node* np = new node;
    np->op = op;
    np->next = nullptr;
    np->prev = last;
    if (isEmpty()) {
        first = np;
        last = np;
    } else {
        last->next = np;
        last = np;
    }
}

// removes and returns first object from non-empty list
template<class T>
T *Dlist<T>::removeFront() {
    if (isEmpty()) {
        emptyList e;
        throw e;
    }
    T* result = first->op;
    node* victim = first;
    first = first->next;
    if (first) // the list has more than one nodes
        first->prev = nullptr;
    else // the list has only one node
        last = nullptr;
    delete victim;
    return result;
}

// removes and returns last object from non-empty list
template<class T>
T *Dlist<T>::removeBack() {
    if (isEmpty()) {
        emptyList e;
        throw e;
    }
    T* result = last->op;
    node* victim = last;
    last = last->prev;
    if (last)
        last->next = nullptr;
    else
        first = nullptr;
    delete victim;
    return result;
}

// removes and returns this object from the list
// returns NULL pointer if no such node exists
template<class T>
T *Dlist<T>::remove(bool (*cmp)(const T *, const T *), T *ref) {
    node* current = first;
    while (current) {
        if (cmp(current->op, ref)) {
            T* result = current->op;
            if (current->prev)
                (current->prev)->next = current->next;
            else // current == first
                first = current->next;
            if (current->next)
                (current->next)->prev = current->prev;
            else // current == last
                last = current->prev;
            delete current;
            return result;
        }
        current = current->next;
    }
    return nullptr;
}

// constructor
template<class T>
Dlist<T>::Dlist(): first(nullptr), last(nullptr) {
}

// copy constructor
template<class T>
Dlist<T>::Dlist(const Dlist &l): first(nullptr), last(nullptr) {
    copyAll(l);
}

// assignment operator
template<class T>
Dlist<T> &Dlist<T>::operator=(const Dlist &l) {
    if (!isEmpty())
        removeAll();
    copyAll(l);
    return *this;
}

// destructor
template<class T>
Dlist<T>::~Dlist() {
    removeAll();
}

// remove and destroy all list elements
template<class T>
void Dlist<T>::removeAll() {
    while (!isEmpty())
        delete removeFront();
}


template<class T>
void Dlist<T>::copyAll(const Dlist &l) {
    node* current = l.first;
    while (current) {
        T* tp = new T(*(current->op));
        insertBack(tp);
        current = current->next;
    }
}


#endif //P3_DLIST_IMPL_H
