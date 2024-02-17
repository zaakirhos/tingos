/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "quickSort.h"

// TODO: you will need to write an appropriate "partition" function here
// It does not need to be in your header file because no one else will call it.

void swapInt(int *a, int *b)
{
  int temp = *a;

  *a = *b;
  *b = temp;
}

int partition(int *arr, int startIndex, int endIndex)
{

  int pivot = arr[endIndex];
  int i = startIndex - 1; // index of the smaller element

  for (int j = startIndex; j < endIndex; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swapInt(&arr[i], &arr[j]);
      // arr[i], arr[j] = arr[j], arr[i]
    }
  }
  swapInt(&arr[i + 1], &arr[endIndex]);
  // arr[i+1], arr[high] = arr[high], arr[i+1]
  return i + 1;
}

void quickSort(int *array, int startIndex, int endIndex)
{

  if (startIndex < endIndex)
  {
    //parIndex is partitioning index, arr[parIndex] is now at right place
    int parIndex = partition(array, startIndex, endIndex);

    //Recursively sort elements before and after partition
    quickSort(array, startIndex, parIndex - 1);
    quickSort(array, parIndex + 1, endIndex);
  }
}

// You should not need to modify this function.
// qSort is a wrapper around the main quickSort function.
void qSort(int *array, int size)
{
  quickSort(array, 0, size - 1);
}
