/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include <utility>
#include <algorithm> 

#include "adts/list.h"
#include "adts/stlList.h"

using std::runtime_error;

template <typename K, typename V>
V LinkedBST<K, V>::findInSubtree(LinkedBSTNode<K, V>* current, K key) {
    if(current == nullptr){
        throw runtime_error("No node in this BST with the given key value");
    }else if(current->getKey() == key){
        return current->getValue();
    }else if(key < current->getKey()){
        return findInSubtree(current->getLeft(), key);
    }else{
        return findInSubtree(current->getRight(), key);
    }
}

template <typename K, typename V>
bool LinkedBST<K, V>::containsInSubtree(LinkedBSTNode<K, V>* current, K key) {
    if(current == nullptr){
        return false;
    }else if(current->getKey() == key){
        return true;
    } else if(key < current->getKey()){
        return containsInSubtree(current->getLeft(), key);
    }else{
        return containsInSubtree(current->getRight(), key);
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::updateInSubtree(LinkedBSTNode<K, V>* current, K key, V value) {
    if(current == nullptr){
        throw runtime_error("No node in this BST with the given key value");
    }else if(current->getKey() == key){
        current->setValue(value);
    }else if(key < current->getKey()){
        updateInSubtree(current->getLeft(), key, value);
    }else{
        updateInSubtree(current->getRight(), key, value);
    }
}

template <typename K, typename V>
int LinkedBST<K, V>::getHeightInSubtree(LinkedBSTNode<K, V>* current) {
    if(current == nullptr) return -1;
    else if(current->getRight() == nullptr){
        return getHeightInSubtree(current->getLeft()) + 1;
    }else if(current->getLeft() == nullptr){
        return getHeightInSubtree(current->getRight()) + 1;
    }else{
        return std::max(getHeightInSubtree(current->getLeft()), getHeightInSubtree(current->getRight())) + 1; 
    }
}

template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMinInSubtree(LinkedBSTNode<K, V>* current) {
    pair<K, V> min;
    if(current == nullptr){
        throw runtime_error("Cannot find minimum node in empty BST");
    }else if(current->getLeft() == nullptr){
        min.first = current->getKey();
        min.second = current->getValue();
        return min; 
    }else{
        return getMinInSubtree(current->getLeft());
    }
}

template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMaxInSubtree(LinkedBSTNode<K, V>* current) {
    pair<K, V> max;
    if(current == nullptr){
        throw runtime_error("Cannot find maximum node in empty BST");
    }
    if (current->getRight() == nullptr){
        max.first = current->getKey();
        max.second = current->getValue();
        return max;
    }else{
        return getMaxInSubtree(current->getRight());
    }
}

template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::insertInSubtree(LinkedBSTNode<K, V>* current, K key, V value) {
   if(current == nullptr){
    //LinkedBSTNode<K, V> *node = new LinkedBSTNode<K, V>(key, value, current->getLeft(), current->getRight())
    current = new LinkedBSTNode<K, V>(key, value, nullptr, nullptr);
    return current;
   }else if(current->getKey() == key){
       throw runtime_error("Duplicate keys are not allowed in BST");
   }else if (key < current->getKey()){
       current->setLeft(insertInSubtree(current->getLeft(), key, value));
       return current;
   }else{
       current->setRight(insertInSubtree(current->getRight(), key, value));
       return current;
   }
}

template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::removeFromSubtree(LinkedBSTNode<K, V>* current, K key) {
    if (current == nullptr){
        throw runtime_error("Key not found in BST");
    }else if (key < current->getKey()){
        current->setLeft(removeFromSubtree(current->getLeft(), key));
        return current;
    }else if (key > current->getKey()){
        current->setRight(removeFromSubtree(current->getRight(), key));
         return current;
    }
    //Target node is found 
    else{
        //case 1: 0 children
        if (current->getRight() == nullptr && current->getLeft() == nullptr){
            delete current;
            current = nullptr;
            return current;
        }
        // case 2a: 1 child (right)
        else if (current->getLeft() == nullptr){
            LinkedBSTNode<K, V> *temp = current->getRight();
            delete current;
            return temp;
        }
        // case 2b: 1 child (left)
        else if (current->getRight() == nullptr){
            LinkedBSTNode<K, V>* temp = current->getLeft();
            delete current;
            return temp;
        }
        // case 3: 2 children 
        else{
            pair<K, V> temp = getMaxInSubtree(current->getLeft());
            current->setKey(temp.first);
            current->setValue(temp.second);
            current->setLeft(removeFromSubtree(current->getLeft(), temp.first));
            return current;
        }
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::deleteSubtree(LinkedBSTNode<K, V>* current) {
    if(current == nullptr){
        return;
    }
    deleteSubtree(current->getLeft());
    deleteSubtree(current->getRight());
    delete current; 
}

template <typename K, typename V>
void LinkedBST<K, V>::buildPreOrderTraversal(LinkedBSTNode<K, V>* current,
                                             List<pair<K, V>>* list) {
    //base case
    if (current == nullptr){
        return;
    }
    //recursive case
    list->insertLast({current->getKey(), current->getValue()});
    buildPreOrderTraversal(current->getLeft(), list);
    buildPreOrderTraversal(current->getRight(), list);
}

template <typename K, typename V>
void LinkedBST<K, V>::buildInOrderTraversal(LinkedBSTNode<K, V>* current,
                                            List<pair<K, V>>* list) {
    //base case
    if (current == nullptr){
        return;
    }
    //recursive case
    buildInOrderTraversal(current->getLeft(), list);
    list->insertLast({current->getKey(), current->getValue()});
    buildInOrderTraversal(current->getRight(), list);
}

template <typename K, typename V>
void LinkedBST<K, V>::buildPostOrderTraversal(LinkedBSTNode<K, V>* current,
                                              List<pair<K, V>>* list) {
    //base case
    if (current == nullptr){
        return;
    }
    //recursive case
    buildPostOrderTraversal(current->getLeft(), list);
    buildPostOrderTraversal(current->getRight(), list);
    list->insertLast({current->getKey(), current->getValue()});
}

template <typename K, typename V>
int LinkedBST<K, V>::countNodes(LinkedBSTNode<K, V>* current) {
    if (current == nullptr) {
        return 0;
    }
    return this->countNodes(current->getLeft()) + this->countNodes(current->getRight()) + 1;
}

template <typename K, typename V>
void LinkedBST<K, V>::verifyKeysBoundedBy(LinkedBSTNode<K, V>* current,
                                          bool minApplies, K minBound,
                                          bool maxApplies, K maxBound) {
    if (minApplies && current->getKey() < minBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a "
                            "right descendent with lesser key");
    }
    if (maxApplies && current->getKey() > maxBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a left "
                            "descendent with greater key");
    }
    if (current->getLeft() != nullptr) {
        verifyKeysBoundedBy(current->getLeft(), minApplies, minBound, true,
                            current->getKey());
    }
    if (current->getRight() != nullptr) {
        verifyKeysBoundedBy(current->getRight(), true, current->getKey(),
                            maxApplies, maxBound);
    }
}
