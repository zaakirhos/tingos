/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <UnitTest++/UnitTest++.h>
#include <iostream>

#include "quickSort.h"

using namespace std;

TEST(threeElements)
{
  // Create a static array containing the numbers 4, 8, 6.
  int array[3] = {4, 8, 6};
  quickSort(array, 0, 2);
  CHECK_EQUAL(4, array[0]);
  CHECK_EQUAL(6, array[1]);
  CHECK_EQUAL(8, array[2]);
}

TEST(reverseSorted)
{
  int size = 20;
  // Create a dynamically-allocated array
  int *array = new int[size];
  for (int i = 0; i < size; i++)
  {
    array[i] = size - 1 - i;
  }
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size; i++)
  {
    CHECK_EQUAL(i, array[i]);
  }
  // de-allocate array
  delete[] array;
  array = nullptr;
}

// TODO: put your other tests here
/**
 * Test a single-element array with the quickSort method to check it's correctness
 * */
TEST(singleElement)
{
  //create  a static array containing one element
  int array[1] = {11};
  quickSort(array, 0, 0);
  CHECK_EQUAL(11, array[0]);
}

// /**
//  * Test an already-sorted array with the quickSort method to check it's correctness
//  * */
TEST(alreadySorted)
{
  //create a static array containing 7 elementes that are in order

  int array[7] = {1, 2, 3, 4, 5, 6, 7};
  quickSort(array, 0, 6);

  for (int i = 0; i < 7; i++)
  {
    CHECK_EQUAL(i + 1, array[i]);
  }
}

// /**
//  * Test an array containing duplicates with the quickSort method to check it's correctness
//  * */
TEST(duplicates)
{
  //create a static array containing 4 elements with 2 duplicates

  int array[4] = {1, 1, 4, 4};
  quickSort(array, 0, 3);

  CHECK_EQUAL(1, array[0]);
  CHECK_EQUAL(1, array[1]);
  CHECK_EQUAL(4, array[2]);
  CHECK_EQUAL(4, array[3]);
}

// /**
//  * Test a large array of numbers that approach a midpoint from opposite directions (e.g. [0,999,..,1,998,2,997,..])
//  * This is to test the quickSort method to check it's correctness
//  * */
TEST(midpoint)
{

  int size = 1000;
  // Create a dynamically-allocated array
  int small = 0;
  int *array = new int[size];
  for (int i = 0; i < size - 1;)
  {
    array[i] = small;
    small++;
    array[i + 1] = size - small;
    i += 2;
  }

  quickSort(array, 0, size - 1);

  for (int i = 0; i < size; i++)
  {
    CHECK_EQUAL(i, array[i]);
  }
  // de-allocate array
  delete[] array;
  array = nullptr;
}

/* no need to modify main */
int main()
{
  return UnitTest::RunAllTests();
}
