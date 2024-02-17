/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "horizontalLine.h"

// TODO: Define your HorizontalLine methods here.
HorizontalLine::HorizontalLine(int x, int y, int length, char symbol){
  this->x = x;
  this->y = y;
  this->length = length;
  this->symbol = symbol;
}

void HorizontalLine::draw(Grid* grid){
  for (int c = x; c<length+x; c++){
    grid->placeSymbol(c, y, symbol);
  }
}