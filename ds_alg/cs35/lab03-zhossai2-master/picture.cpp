/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <stdexcept>

#include "picture.h"
#include "grid.h"

using namespace std;

Picture::Picture() {
    // TODO: implement Picture::Picture
    this->numberOfShapes = 0;
    this->shapes = new Shape *[50];
    // throw runtime_error("Not yet implemented: Picture::Picture");
}

Picture::~Picture() {
    for (int i = 0; i<50; i++){
        delete shapes[i];
    }
    delete[] shapes;
    delete this->grid;
}


string Picture::toString() {
    // TODO: implement Picture::toString
    this->grid = new Grid();

    for(int i = 0; i<numberOfShapes; i++){
        shapes[i]->draw(this->grid);
    }

    return grid->toString();

    // throw runtime_error("Not yet implemented: Picture::print");
}

void Picture::print() {
    cout << this->toString() << endl;
}

void Picture::addShape(Shape* shape) {
    // TODO: implement Picture::addShape
    shapes[this->numberOfShapes] = shape;
    this->numberOfShapes++;

    // throw runtime_error("Not yet implemented: Picture::addShape");
}
