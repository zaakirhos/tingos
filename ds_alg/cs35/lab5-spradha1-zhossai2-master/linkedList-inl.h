/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

using std::runtime_error;

// This file defines the methods for two classes: LinkedListNode and LinkedList.
// The LinkedListNode methods have been defined for you.  You are responsible
// for defining the LinkedList methods.

// //////// LinkedListNode /////////////////////////////////////////////////////

template <typename T>
LinkedListNode<T>::LinkedListNode(T val, LinkedListNode<T>* next) {
    this->value = val;
    this->next = next;
}

// //////// LinkedList /////////////////////////////////////////////////////////

template <typename T> 
LinkedList<T>::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <typename T> 
LinkedList<T>::~LinkedList() {
    LinkedListNode<T>* currentNode;
    LinkedListNode<T>* nextNode = this->head;
    for(int i = 0; i < this->size; i++){
        currentNode = nextNode;
        nextNode = nextNode->next;
        delete currentNode;
    }
}

template <typename T>
void LinkedList<T>::checkInvariants() {
    int listSize = 0;
    LinkedListNode<T>* currentNode = this->head;
    //Counts number of nodes in LinkedList
    while(currentNode != NULL){
        listSize++;
        currentNode = currentNode->next;
    
    }
    //Checks if number of nodes matches with size
    if(listSize != this->size){
        std::cout<<listSize<<std::endl;
        std::cout<<this->size<<std::endl;
        throw runtime_error("LinkedList<T>::checkInveriants(); Size data member does not equal number of nodes in LinkedList");
    }
}


template <typename T>
int LinkedList<T>::getSize() {
    return this->size;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    return this->size == 0;
}

template <typename T>
T LinkedList<T>::getFirst() {
    if(this->size == 0){
        throw runtime_error("LinkedList<T>::getFirst(); Trying to access while LinkList is empty");
    }
    return this->head->value;
}

template <typename T>
T LinkedList<T>::getLast() {
    if(this->size == 0){
        throw runtime_error("LinkedList<T>::getLast(); Trying to access while LinkList is empty");
    }
    return this->tail->value;
}

template <typename T>
T LinkedList<T>::get(int index) {
    if(index >= this->size || index < 0){
        throw runtime_error("LinkedList<T>::get(); Invalid index");
    }
    if(this->isEmpty()){
        throw runtime_error("LinkedList<T>::get(); Trying to access element while LinkedList is empty");
    }
    LinkedListNode<T>* currentNode = this->head;
    //Iterate across LinkedList until reaching the target node 
    for(int i = 0; i<index; i++){
        currentNode = currentNode->next;
    }
    return currentNode->value;
}

template <typename T> 
void LinkedList<T>::insertFirst(T value) {
    if(this->isEmpty()){
        //If LinkedList is empty, then the first inserted element will be both the head and tail
        LinkedListNode<T>* newNode = new LinkedListNode<T>(value, nullptr);
        this->head = newNode;
        this->tail = newNode;
        // this->tail->next = nullptr;
    }else{
        //The newNode inserted at the front will point next to the oldHead
        LinkedListNode<T>* oldHead = this->head;
        LinkedListNode<T>* newNode = new LinkedListNode<T>(value, oldHead);
        this->head = newNode;
    }
    this->size++;
}

template <typename T> 
void LinkedList<T>::insertLast(T value) {
    if(isEmpty()){
        //If LinkedList is empty, then the first inserted element will be both the head and tail
        LinkedListNode<T>* currentNode = new LinkedListNode<T>(value, nullptr);
        this->head = currentNode;
        this->tail = currentNode;
    }else{
        //The oldTail will point next to the newNode inserted at the back 
        LinkedListNode<T>* oldTail = this->tail;
        LinkedListNode<T>* newNode = new LinkedListNode<T>(value, nullptr);
        this->tail = newNode;
        oldTail->next = newNode;
    }
    this->size++;
}

template <typename T>
T LinkedList<T>::removeFirst() {
    if(this->size == 0){
        throw runtime_error("LinkedList<T>::removeFirst(); Cannot be used on an empty LinkedList");
    }
    //Save value of head node before it is deleted 
    T removedValue = this->head->value;
    LinkedListNode<T>* newHead = this->head->next;
    delete this->head;
    //Setting the head as the second from the front node 
    this->head = newHead;
    this->size--;
    return removedValue;
}

template <typename T>
T LinkedList<T>::removeLast() {
    if(this->size == 0){
        throw runtime_error("LinkedList<T>::removeLast(); Cannot be used on an empty LinkedList");
    }
    T removedValue;
    //If there is only one node in LinkedList, delete it and set the head/tail to nullptr
    if(this->head->next == nullptr){  
        removedValue = this->head->value;
        delete this->head;
	    this->head = nullptr;
    }else{
        LinkedListNode<T>* currentNode = this->head;
        //Iterate across the LinkedList until reaching the second to last node
        for(int i = 0; i<this->size-2; i++){
            currentNode = currentNode->next;
        }
        removedValue = this->tail->value;
        //Set tail to the second to last node 
        this->tail = currentNode;
        delete currentNode->next;
        currentNode->next = nullptr;
    }
    this->size--;
    return removedValue;
}

template <typename T>
void LinkedList<T>::reverse(){
    if(this->size == 0){
        throw runtime_error("LinkedList<T>::reverse(); Cannot be used on an empty LinkedList");
    }
    LinkedListNode<T>* current = this->head;
    LinkedListNode<T>* prev = nullptr;
    LinkedListNode<T>* next = nullptr;

    while(current !=nullptr){
        //Store the current's next first
        next = current->next;
        //Reversing by having each node point next to the previous node 
        current->next = prev;
        prev = current;
        current = next;
    }
    //Since LinkedList is reversed, the original head and tail should be swapped 
    this->tail = this->head;
    this->head = prev; //prev is already pointing to the new front of the list 
}
