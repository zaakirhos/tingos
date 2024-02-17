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
#include <vector> 
#include "linkedBST.h"
#include "adts/stlList.h"

// TODO: put #includes here

using namespace std;

int main() {
  LinkedBST<int,int> test;
  vector<pair<int,int>> vec;
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int k;
    std::cin >> k;
    test.insert(k,k);
  }
  vec = test.traversePreOrder();
  for(int i = 0; i < n; i++){
    std::cout << vec[i].first << endl;
  }
}
