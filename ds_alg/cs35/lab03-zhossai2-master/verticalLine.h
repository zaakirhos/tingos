#pragma once

/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "shape.h"

// TODO: Declare your VerticalLine class here.
class VerticalLine : public Shape {
  private:
    int x;
    int y;
    int length;
    char symbol;

  public:
    VerticalLine(int x, int y, int length, char symbol);
        /**
     * Draws a vertical line on the provided grid.
     * @param grid The grid onto which to draw the vertical line.
     */
    void draw(Grid* grid);
};
