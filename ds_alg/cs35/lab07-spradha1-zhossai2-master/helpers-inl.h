/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "helpers.h"

template <typename T> vector<T> dynamicListToStaticVector(List<T>* list) {
  //TODO: Possible Modification
  vector<T> vec; 
  while(!list->isEmpty()){
    vec.push_back(list->removeFirst());
  }
  return vec;
}
