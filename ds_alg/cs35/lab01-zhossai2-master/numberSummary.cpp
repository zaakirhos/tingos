#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms

  Student Name: Zakir Hossain
  Date: 09/05//2021

  This program reads a list of numbers from a file and computes certain summaries
*/

//Function signatures
void openInputFile(ifstream &inFile);
int findLargest(int arr[], int size);
double computeAverage(int arr[], int size);
int predecessorCount(int arr[], int size, int n);


/**function main
 * the entry point of the program
 */
int main()
{

  ifstream file;
  openInputFile(file);

  int size;
  int largest;
  int lessThanTenCount;
  double average;
  file >> size; //reads the first number
  int arr[size];
  int *ptr = arr;
  while (file >> *ptr)
  {
    ptr++;
  }
  cout << "The last number is: " << arr[size - 1] << endl;
  largest = findLargest(arr, size);
  lessThanTenCount = predecessorCount(arr, size, 10);
  average = computeAverage(arr, size);
  cout << "The largest number is: " << largest << endl;
  cout << "There are " << lessThanTenCount << " numbers that are less than 10" << endl;
  cout << "The average is: " << average << endl;
  file.close();
  return 0;
}

//Functions implementation
/**function openInputFile
 * Creates a file stream and opens a file with the given name
 * @param inFile is the file stream through which the file will be open
 * @param return none (void)
*/
void openInputFile(ifstream &inFile)
{
  string filename;
  cout << "Enter the name of your file? ";
  cin >> filename;
  inFile.open(filename);
  while (!inFile)
  {
    cout << "FILE FAILED TO OPEN" << endl;
    cout << "What filename? ";
    cin >> filename;

    inFile.clear(); //clears the failure flag set by fstream
    inFile.open(filename);
  }
}

/**function findLargest
 * A function signature to find the largest element from a given array
 * @param arr the array from which the largest element to be found
 * @param size thr length of the array
 * @param return the largest
*/
int findLargest(int arr[], int size)
{
  int largest = arr[0];
  if (size == 1)
  {
    return largest;
  }
  for (int i = 1; i < size; i++)
  {
    if (arr[i] > largest)
    {
      largest = arr[i];
    }
  }
  return largest;
}

/**function predecessorCount
 * This function implements the predecessor function
 * However, instead of returning a predecessor array, it returns the size of it
 * 
 * @param arr the array in which to look for predecessors
 * @param size the length of the array
 * @param n the pivot point
 * 
 * it counts how many elements are there in the @param arr that are less then @param n
*/
int predecessorCount(int arr[], int size, int n)
{
  int predecessorCount = 0;
  if (size == 1)
  {
    return predecessorCount;
  }
  for (int i = 0; i < size; i++)
  {
    if (arr[i] < n)
    {
      predecessorCount++;
    }
  }
  return predecessorCount;
}

/**
 * function computeAverage
 * 
 * this function computes the average of a given numbers of values
 * @param arr, an array containing a number of values
 * @param size, the number of values that are contained in the @param arr
 */

double computeAverage(int arr[], int size)
{
  double sum = 0;
  double average = 0;
  if (size == 1)
  {
    return arr[0];
  };
  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
  }

  average = sum / size;

  return average;
}