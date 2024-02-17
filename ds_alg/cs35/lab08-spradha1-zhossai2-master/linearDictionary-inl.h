/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include <vector>
#include "linearDictionary.h"
using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> LinearDictionary<K, V>::LinearDictionary() {
    this->chain = new vector<pair<K,V>>; 
}

template <typename K, typename V> LinearDictionary<K, V>::~LinearDictionary() {
    delete this->chain;
}

template <typename K, typename V> int LinearDictionary<K, V>::getSize() {
    return this->chain->size();
}

template <typename K, typename V> bool LinearDictionary<K, V>::isEmpty() {
   return this->chain->empty();
}

template <typename K, typename V>
void LinearDictionary<K, V>::insert(K key, V value) {
    if(this->contains(key)){
        throw runtime_error("LinearDictionary<K,V>::insert   the key already exists");
    }
    this->chain->push_back({key, value});
}

template <typename K, typename V>
void LinearDictionary<K, V>::update(K key, V value) {
    //Searches through chain for key to update
    for(int i = 0; i<this->chain->size(); i++){
        if(this->chain->at(i).first == key){
            this->chain->at(i).second = value;
            return;
        }
    }
    //If key not found, throw error
    throw runtime_error("LinearDictionary<K,V>::update   the key does not exist");
}

template <typename K, typename V> 
V LinearDictionary<K, V>::get(K key) {
    for(int i = 0; i<this->chain->size(); i++){
        if(this->chain->at(i).first == key){
            return this->chain->at(i).second;
        }
    }
    throw runtime_error("LinearDictionary<K,V>::get   the key does not exist");
}

template <typename K, typename V> bool LinearDictionary<K, V>::contains(K key) {
    for(int i = 0; i<this->chain->size(); i++){
        if(this->chain->at(i).first == key){
            return true;
        }
    }
    return false;
}

template <typename K, typename V> void LinearDictionary<K, V>::remove(K key) {
    for(int i = 0; i<this->chain->size(); i++){
        if(this->chain->at(i).first == key){
            removeFromVector(*this->chain, i);
            return;
        }
    }
    throw runtime_error("LinearDictionary<K,V>::remove   the key does not exist");
}

template <typename K, typename V> vector<K> LinearDictionary<K, V>::getKeys() {
    vector<K> keys;
    for(int i = 0; i<this->chain->size(); i++){
        keys.push_back(this->chain->at(i).first);
    }
    return keys;
    
}

template <typename K, typename V>
vector<pair<K, V>> LinearDictionary<K, V>::getItems() {
//    return &this->chain;
    vector<pair<K, V>> items;
    for (int i = 0; i < this->chain->size(); i++){
        items.push_back({chain->at(i).first, chain->at(i).second});
    }
    return items;
}

template <typename T> void removeFromVector(vector<T> &list, int index){
  if(index < 0 || index >= list.size()){
    throw runtime_error("index out of range in removeFromVector");
  }
  list.erase(list.begin()+index, list.begin()+index+1);
}
