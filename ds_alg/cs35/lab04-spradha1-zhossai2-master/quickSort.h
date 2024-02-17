#pragma once

/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

/**
 * Performs the main quick sort algorithm to sort the provided array.
 * @param array The array to sort.
 * @param startIndex The leftmost index (inclusive) of the part of the array
 *                   to sort.
 * @param endIndex The rightmost index (inclusive) of the part of the array
 *                 to sort.
 */
void quickSort(int* array, int startIndex, int endIndex);

/**
 * A function to swap 2 integer values. 
 * @param a, first pointer for swapping
 * @param b, the other pointer for swapping
 * @return void
 * At the end of the execution, the a is pointed to the value of b and b to the value of a
*/
void swapInt(int *a, int *b);

/**
 * Performs partition for quicksort. 
 * given an array, a pivot is chosen from the array (the value at endIndex in this case)
 * put pivot at its correct position in sorted array by putting all smaller elements 
 * (smaller than pivot) before pivot, and putting all greater elements (greater than pivot) 
 * after pivot.
 * 
 * @param arr, the array to be partitioned
 * @param startIndex, the index at which to begin the partition
 * @param endIndex, the index at which to end the partition
*/
int partition(int *arr, int startIndex, int endIndex); 

/**
 * Wrapper function around the main quickSort function.
 * This function should get called once, then call quickSort
 *   with indices 0, size-1.
 * @param array The array to sort.
 * @param size  The size of the array.
 */
void qSort(int *array, int size);
