/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

List<pair<int, string>>* loadMovie(string filename) {
  //Create a LinkedList of a pair of frame times and frame images on the heap
  LinkedList<pair<int, string>>* frameList = new LinkedList<pair<int, string>>;
  //Create an pair to store time and images for a specific frame 
  pair<int, string> currentFrame;
  currentFrame.second = "";
  //Create string to get data from file 
  string frameText; 
  //Open ifstream
  ifstream movieFile; 
  movieFile.open(filename);
  //Check if filename is valid
  if(!movieFile.is_open()){
    throw runtime_error("file " + filename + "failed to open ");
  }
  //Store time onto currentFrame;
  movieFile >> currentFrame.first; //The stream is still in the current line, >> operator does not go to next line
  //The getline after getting the number will retrieve nothing (rest of line is empty)
  getline(movieFile, frameText);
  while(!movieFile.eof()){
    //get each 13 line for currentFrame
    for(int i = 0; i < 13; i++){
      getline(movieFile, frameText);
      currentFrame.second += frameText + '\n';
    }
    //insert currentFrame into the frameList
    frameList->insertLast(currentFrame);
    //Store time for the next frame
    movieFile >> currentFrame.first;
    //Reset image string for the next frame
    currentFrame.second = "";
    getline(movieFile, frameText);
  }
  return frameList;
}

void playMovie(List<pair<int, string>>* list) {
  for(int i = 0; i < list->getSize(); i++){
    //Clears console 
    system("clear");
    //Prints frame onto console
    std::cout << list->get(i).second;
    //Number of seconds on each image = seconds per frame * number of frames for image 
    usleep(1000000/15 * list->get(i).first);
  }
}
