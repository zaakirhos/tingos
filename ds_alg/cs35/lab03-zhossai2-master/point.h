#pragma once

/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "shape.h"

// TODO: Declare your Point class here.
// using std::string;

class Point : public Shape {
  private:
    int x;
    int y;
    char symbol;

  public:
    Point(int x, int y, char symbol);
    void draw(Grid* grid);
};
