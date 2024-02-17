/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string.h>
#include <utility>

#include "maze.h"
#include "mazeUtils.h"

using namespace std;

int main(int argc, char **argv)
{

// If the number of arguments given is not exactly three, including the program itself, then the program will exit. 
  if (argc > 3 || argc < 3)
  {
    cout << "Invalid number of arguments" << endl;
    cout << "3 args are expected, you provided " << argc << endl;
    return 1;
  }
//If the search method given is not breadth or depth, the program will exit.
  if (strcmp(argv[2], "breadth") !=0 && strcmp(argv[2], "depth") != 0)
  {
    cout << "The only valid search types are 'breadth' and 'depth'" << endl;
    cout << "You gave: " << argv[2] << endl;
    return 1;
  }

  string fn = argv[1];
  Maze *maze;
  List<Position *> *solution;
  string output;

  try
  {
    maze = loadMap(fn);
  }
  catch (runtime_error &e)
  {
    cout << e.what() << endl;
    return 1;
  }

  if (strcmp(argv[2], "breadth")== 0)
  {
    solution = maze->solveBreadthFirst();
  }
  if (strcmp(argv[2], "depth")==0)
  {
    solution = maze->solveDepthFirst();
  }

  try
  {
    output = renderAnswer(maze, solution);
    cout << output << endl;
  }
  catch (runtime_error &e)
  {
    cout << e.what() << endl;
    return 1;
  }
   delete solution;
  delete maze;
  return 0;
}
