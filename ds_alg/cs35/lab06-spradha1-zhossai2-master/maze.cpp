/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

/* ADTs */
#include "adts/list.h"
#include "adts/orderedCollection.h"
#include "adts/queue.h"
#include "adts/stack.h"

/* Implementations of above ADTs */
#include "adts/stlList.h"
#include "linkedQueue.h"
#include "linkedStack.h"
#include "position.h"

#include "maze.h"

using namespace std;

Maze::Maze(int width, int height) {

	//Allocated positions to an array, with size width, of arrays of
	//Position pointers  
   this->positions = new Position**[width];
    for(int i = 0; i < width; i++){
	    //Allocates an array, with size height, of Position pointers 
        Position** temp = new Position*[height];
        for(int j = 0; j < height; j++){
		//Allocate a Position for each of the Position pointers in temp
            temp[j] = new Position(i, j);
        }
	//Places each array of Position pointers (temp) into the positions	
        this->positions[i] = temp;
    }
    this->width = width;
    this->height = height;
}

Maze::~Maze() {
    for(int i = 0; i < this->width; i++){
        for(int j = 0; j < this->height; j++){
            delete this->positions[i][j];
        }
        delete[] this->positions[i]; 
    }
    delete[] this->positions; 
}

int Maze::getWidth() {
    return this->width;
}

int Maze::getHeight() {
    return this->height;
}

bool Maze::isWall(int x, int y) {
    return this->positions[x][y]->isWall();
}

void Maze::setWall(int x, int y) {
    this->positions[x][y]->setWall();
}

List<Position*>* Maze::solveBreadthFirst() {
    OrderedCollection<Position*>* queue = new LinkedQueue<Position*>;
    return this->solve(queue);
}

List<Position*>* Maze::solveDepthFirst() {
    OrderedCollection<Position*>* stack = new LinkedStack<Position*>;
    return this->solve(stack);
}

List<Position*>* Maze::solve(OrderedCollection<Position*>* exploration) {
    //sets currentNode to starting position (0,0), add it to exploration, and set it as visited
    Position* currentNode = this->positions[0][0];
    exploration->insert(this->positions[0][0]);
    this->positions[0][0]->setVisited();
    //Iterates through all maze paths until either all reachable nodes are explored or the end is reached.
    while(exploration->getSize() != 0 && currentNode != this->positions[this->getWidth()-1][this->getHeight()-1]){
        currentNode = exploration->peek();
        exploration->remove();
        //get all valid neighbors of currentNode 
        List<Position*>* nodeNeighbors = this->getNeighbors(currentNode);
        for(int i = 0; i < nodeNeighbors->getSize(); i++){
            //For every unvisited neighbor node, set them to visited, add them to exploration, and set their previous to currentNode
            if(!nodeNeighbors->get(i)->isVisited()){
                nodeNeighbors->get(i)->setVisited();
                nodeNeighbors->get(i)->setPrevious(currentNode);
                exploration->insert(nodeNeighbors->get(i));   
            }
        }
        //remove nodeNeighbors from heap 
        delete nodeNeighbors;
    }
    //remove exploration from heap 
    delete exploration;
    //if end was reached, backtrace through previous nodes to find path
    if(this->positions[this->width-1][this->height-1]->isVisited()){
        List<Position*>* path = new STLList<Position*>;
        while(currentNode != this->positions[0][0]){
            path->insertFirst(currentNode);
            currentNode = currentNode->getPrevious();
        }
        path->insertFirst(this->positions[0][0]);
        return path;
    }
    //if end was not reached, return nullptr
    return nullptr;
}

List<Position*>* Maze::getNeighbors(Position* position) {
    //for (x,y), check (x+1, y), (x, y+1), (x-1, y), (x, y-1). If valid position (not wall or out of bounds), add to List
    List<Position*>* validNeighbors = new STLList<Position*>; 
    int x = position->getX();
    int y = position->getY();
    if(x + 1 < width && y < height && !this->positions[x+1][y]->isWall()){
        validNeighbors->insertLast(this->positions[x+1][y]);
    }
    if(x - 1 < width && x > 0 && y < height && !this->positions[x-1][y]->isWall()){
        validNeighbors->insertLast(this->positions[x-1][y]);
    }   
    if(x < width && y + 1 < height && !this->positions[x][y + 1]->isWall()){
        validNeighbors->insertLast(this->positions[x][y + 1]);
    }   
    if(x < width && y - 1 < height && y > 0 && !this->positions[x][y - 1]->isWall()){
        validNeighbors->insertLast(this->positions[x][y - 1]);
    }      
    return validNeighbors;
}
