/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>
#include <utility>
#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;


int main() {

  LinkedList<int> list;
  list.insertLast(2); // [2]
  list.insertLast(6); // [2,6]
  list.insertLast(3); // [2,6,3]
  list.reverse();
  for(int i = 0; i<list.getSize(); i++){
    cout << list.get(i)<<endl;
  }


  return 0;
}
