/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>

#include "image.h"
#include "ppmio.h"
using namespace std;

/**
 * author: Zakir Hossain
 * Date: 09/09/2021
 * 
 * This program performs pixel transformation to a given image. Many of the interfaces and their implementations are separated
 * See the header files to see the detail
*/

int main(int argc, char **argv)
{

  if (argc != 4)
  {
    std::cout << "4 arguments can be given (including the executable), however" << std::endl;
    std::cout << "you have entered! Program is terminated" << argc << std::endl;
    std::cout << "Usage: ./executable <readingfile>.ppm <action> <writingfile>.ppm" << std::endl;
    return 1;
  }

  int width = 0;
  int height = 0;
  int isTransformed = false;
  int size = 0;

  string infile = argv[1]; //assuming the user puts the file name as 2nd argument
  string action = argv[2];
  string outfile = argv[3];

  width = ppm_width(infile);
  height = ppm_height(infile);
  size = width * height *3;
  int *ppm = new int[size];
  ppm = read_ppm(infile);
  
  isTransformed = transformImage(width, height, ppm, action);

  if (isTransformed)
  {
    write_ppm(outfile, width, height, ppm);
  }
  else
  {
    std::cout << "The " << action << "command is not supported" << std::endl;
  }

  delete[] ppm;
  return 0;
}
