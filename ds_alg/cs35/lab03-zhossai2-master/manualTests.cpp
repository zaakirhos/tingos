/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "grid.h"
#include "shape.h"
#include "point.h"
#include "horizontalLine.h"
#include "verticalLine.h"
#include "rectangle.h"
#include "picture.h"
#include <iostream>

using namespace std;

int main() {
    // You can put anything you like here.  This file exists so that
    // you can experiment with your code.  For instance, the following
    // might be a useful test after you've written your Point class.

    // Shape* point = new Point(0,0, 'x');
    // Grid* grid = new Grid();
    // point->draw(grid);
    // cout << grid->toString() << endl;
    // delete grid;
    // delete point;
    
    // Shape* hl = new HorizontalLine(1,1, 8, 'x');
    // Grid* grid = new Grid();
    // hl->draw(grid);
    // cout << grid->toString() << endl;
    // delete grid;
    // delete hl;
    
    // Shape* hl = new VerticalLine(1,1, 8, 'x');
    // Grid* grid = new Grid();
    // hl->draw(grid);
    // cout << grid->toString() << endl;
    // delete grid;
    // delete hl;

    Shape* rect = new Rectangle(1, 1, 3, 3, 'X');
    Shape* rect2 = new Rectangle(10, 10, 3, 3, 'X');
    Picture* p = new Picture();
    p->addShape(rect);
    p->addShape(rect2);
    p->print();
    // Grid* grid = new Grid();
    // rect->draw(grid);
    // cout << grid->toString() << endl;
    // delete grid;
    delete p;

    return 0;
}
