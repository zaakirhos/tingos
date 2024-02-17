/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "linkedQueue.h"
#include "adts/stlList.h"

using namespace std;

template <typename T> LinkedQueue<T>::LinkedQueue() {
    this->queue = new STLList<T>;
}

template <typename T> LinkedQueue<T>::~LinkedQueue() {
    delete this->queue;
}

template <typename T> void LinkedQueue<T>::enqueue(T element) {
    this->queue->insertLast(element);
}

template <typename T> T LinkedQueue<T>::dequeue() {
    return this->queue->removeFirst();
}

template <typename T> void LinkedQueue<T>::insert(T element) {
    this->enqueue(element);
}

template <typename T> T LinkedQueue<T>::remove() {
    return this->dequeue();
}

template <typename T> int LinkedQueue<T>::getSize() {
    return this->queue->getSize();
}

template <typename T> bool LinkedQueue<T>::isEmpty() {
    return this->queue->isEmpty();
}

template <typename T> T LinkedQueue<T>::peek() {
    return this->queue->getFirst();
}
