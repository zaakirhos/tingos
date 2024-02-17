/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>


#include "hashFunctions.h"

using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> HashTable<K, V>::HashTable() {
    this->size = 0;
    this->capacity = 5;
    this->maxLoadFactor = 0.75;
    this->table = new LinearDictionary<K,V>[this->capacity];
    // for(int i = 0; i < this->capacity; i++){
    //     LinearDictionary<K,V> temp; 
    //     this->table[i] = temp; 
    // }
}

template <typename K, typename V>
HashTable<K, V>::HashTable(float maxLoadFactor) {
    this->size = 0;
    this->capacity = 5;
    this->maxLoadFactor = maxLoadFactor;
    this->table = new LinearDictionary<K,V>[this->capacity];
}

template <typename K, typename V> HashTable<K, V>::~HashTable() {
    delete[] this->table;
}

template <typename K, typename V> int HashTable<K, V>::getSize() {
    return this->size;
}

template <typename K, typename V> bool HashTable<K, V>::isEmpty() {
    return this->size == 0; 
}

template <typename K, typename V> void HashTable<K, V>::insert(K key, V value) {
    int index = hash(key,this->capacity);
    this->table[index].insert(key,value);
    this->size++;
    this->expandCapacity(); 
}

template <typename K, typename V> void HashTable<K, V>::update(K key, V value) {
    int index = hash(key,this->capacity);
    this->table[index].update(key,value);
}

template <typename K, typename V> V HashTable<K, V>::get(K key) {
    int index = hash(key,this->capacity);
    return this->table[index].get(key);
}

template <typename K, typename V> bool HashTable<K, V>::contains(K key) {
    int index = hash(key,this->capacity);
    return this->table[index].contains(key);
}

template <typename K, typename V> void HashTable<K, V>::remove(K key) {
    if(size == 0){
        throw runtime_error("HashTable::remove Cannot remove from empty hashTable");
    }
    int index = hash(key,this->capacity);
    return this->table[index].remove(key);
}

template <typename K, typename V> vector<K> HashTable<K, V>::getKeys() {
    vector<K> keys; 
    for(int i = 0; i < this->capacity; i++){
        if(!this->table[i].isEmpty()){
            vector<K> temp = this->table[i].getKeys();
            keys.insert(keys.end(), temp.begin(), temp.end());
        }
    }
    return keys;
}

template <typename K, typename V>
vector<pair<K, V>> HashTable<K, V>::getItems() {
    vector<pair<K,V>> items; 
    for(int i = 0; i < this->capacity; i++){
        if(!this->table[i].isEmpty()){
            vector<pair<K, V>> temp = this->table[i].getItems();
            items.insert(items.end(), temp.begin(), temp.end());
        }
    }
    return items;
}

template <typename K, typename V> void HashTable<K, V>::expandCapacity() {
    if(float(this->size) / this->capacity >= this->maxLoadFactor){
        vector<pair<K,V>> items = this->getItems(); 
        this->size = 0; 
        this->capacity *= 2;
        LinearDictionary<K,V>* newTable = new LinearDictionary<K,V>[this->capacity];
        delete[] this->table;
        this->table = newTable; 
        for(int i = 0; i < items.size(); i++){
            this->insert(items[i].first, items[i].second);
        }
    }
}


