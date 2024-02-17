/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include<string.h>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

int main(int argc, char** argv) {
    // TODO: write your program here
    if (argc < 2 || argc>3)
    {
      throw runtime_error("Expected numbers of arguments are 2 or 3.");
    }
    if (argc > 2 && strcmp(argv[2],"--reverse") == 0){
	cout << "Unknown flag: " << argv[2] << endl;
      throw runtime_error("The only valid flag is --reverse");
    }
    string fileName = argv[argc - 1];
    List<pair<int, string>>* ASCIIArtFrameList;
    ASCIIArtFrameList = loadMovie(fileName);
    if(argc > 2){
      ASCIIArtFrameList->reverse();
    }
    playMovie(ASCIIArtFrameList);
    //de allocate the list
    delete ASCIIArtFrameList;
    return 0;
}
