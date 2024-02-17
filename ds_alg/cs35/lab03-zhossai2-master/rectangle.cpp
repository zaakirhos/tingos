/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "rectangle.h"

// TODO: Define your Rectangle methods here.
Rectangle::Rectangle(int x, int y, int width, int height, char symbol){
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->symbol = symbol;
}

void Rectangle::draw(Grid* grid){
  for(int r = y; r<height+y; r++){

     for (int c = x; c<width+x; c++){
    grid->placeSymbol(c, r, symbol);
  }
  }
 
}
