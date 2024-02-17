/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "verticalLine.h"

// TODO: Define your VerticalLine methods here.
VerticalLine::VerticalLine(int x, int y, int length, char symbol){
  this->x = x;
  this->y = y;
  this->length = length;
  this->symbol = symbol;
}

void VerticalLine::draw(Grid* grid){
  for (int r = y; r<length+y; r++){
    grid->placeSymbol(x, r, symbol);
  }
}