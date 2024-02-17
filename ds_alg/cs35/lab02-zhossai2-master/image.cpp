/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "image.h"
#include <string>
#include <iostream>
using namespace std;


int pixelToIndex(int width, int rIndex, int cIndex)
{
  if (cIndex > width)
  {
    printf("The colum is invalid");
    return -1;
  }
  return 3 * (width * rIndex + cIndex);
}

void swapColorValue(int *colorWeight1, int *colorWeight2)
{
  int temp = *colorWeight1;

  *colorWeight1 = *colorWeight2;
  *colorWeight2 = temp;
}

void drainColor(int width, int height, int *ppm, char c)
{
  int colorIndex = 0;
  if (c == 'g')
  {
    colorIndex = 1;
  }
  if (c == 'b')
  {
    colorIndex = 2;
  }

  for (int r = 0; r < height; r++)
  {
    for (int c = 0; c < width; c++)
    {
      int pixelFirstIndex = pixelToIndex(width, r, c);
      ppm[pixelFirstIndex + colorIndex] = 0;
    }
  }
}

void noRed(int width, int height, int *ppm)
{
  drainColor(width, height, ppm, 'r');
}
void noGreen(int width, int height, int *ppm)
{
  drainColor(width, height, ppm, 'g');
}

void noBlue(int width, int height, int *ppm)
{
  drainColor(width, height, ppm, 'b');
}

void invert(int width, int height, int *ppm)
{

  for (int r = 0; r < height; r++)
  {
    for (int c = 0; c < width; c++)
    {
      int pixelFirstIndex = pixelToIndex(width, r, c);
      ppm[pixelFirstIndex] = 255 - ppm[pixelFirstIndex];
      ppm[pixelFirstIndex + 1] = 255 - ppm[pixelFirstIndex + 1];
      ppm[pixelFirstIndex + 2] = 255 - ppm[pixelFirstIndex + 2];
    }
  }
}

void grayscale(int width, int height, int *ppm)
{

  for (int r = 0; r < height; r++)
  {
    for (int c = 0; c < width; c++)
    {
      int pixelFirstIndex = pixelToIndex(width, r, c);
      float sum = ppm[pixelFirstIndex] + ppm[pixelFirstIndex + 1] + ppm[pixelFirstIndex + 2];
      float average = sum / 3;
      ppm[pixelFirstIndex] = (int)(average + 0.5);
      ppm[pixelFirstIndex + 1] = (int)(average + 0.5);
      ppm[pixelFirstIndex + 2] = (int)(average + 0.5);
    }
  }
}

void flipHorizontally(int width, int height, int *ppm)
{
  int length = ((width / 2.0)) - 0.5;
  for (int r = 0; r < height; r++)
  {
    for (int c = 0; c < length; c++)
    {
      int leftIndex = pixelToIndex(width, r, c);
      int rightIndex = pixelToIndex(width, r, width - c - 1);
      swapColorValue(&ppm[leftIndex], &ppm[rightIndex]);
      swapColorValue(&ppm[leftIndex + 1], &ppm[rightIndex + 1]);
      swapColorValue(&ppm[leftIndex + 2], &ppm[rightIndex + 2]);
    }
  }
}

void flipVertically(int width, int height, int *ppm)
{
  int length = ((height / 2.0)) - 0.5;
  for (int r = 0; r < length; r++)
  {
    for (int c = 0; c < width; c++)
    {
      int topIndex = pixelToIndex(width, r, c);
      int bottomIndex = pixelToIndex(width, height - r - 1, c);
      swapColorValue(&ppm[topIndex], &ppm[bottomIndex]);
      swapColorValue(&ppm[topIndex + 1], &ppm[bottomIndex + 1]);
      swapColorValue(&ppm[topIndex + 2], &ppm[bottomIndex + 2]);
    }
  }
}

void spin2_by_2(int width, int height, int *ppm)
{
  for (int r = 0; r < height;)
  {
    for (int c = 0; c < width;)
    {
      int topLeft = pixelToIndex(width, r, c);
      int topRight = pixelToIndex(width, r, c + 1);
      int bottomLeft = pixelToIndex(width, r + 1, c);
      int bottomRight = pixelToIndex(width, r + 1, c + 1);
      swapColorValue(&ppm[topLeft], &ppm[bottomRight]);
      swapColorValue(&ppm[topLeft + 1], &ppm[bottomRight + 1]);
      swapColorValue(&ppm[topLeft + 2], &ppm[bottomRight + 2]);

      swapColorValue(&ppm[topRight], &ppm[bottomLeft]);
      swapColorValue(&ppm[topRight + 1], &ppm[bottomLeft + 1]);
      swapColorValue(&ppm[topRight + 2], &ppm[bottomLeft + 2]);
      c += 2;
    }
    r += 2;
  }
}

void faderight(int width, int height, int *ppm)
{
  int k = 0;

  for (int r = 0; r < height; r++)
  {
    for (int c = 0; c < width; c++)
    {
      int pixelFirstIndex = pixelToIndex(width, r, c);
      if (c == width - 1)
      {
        k = 1;
      }
      float gradientPercent = (float)(width - c - k) / width;
      ppm[pixelFirstIndex] = (int)(gradientPercent * ppm[pixelFirstIndex] + 0.5);
    }
  }
}

void blur(int width, int height, int *ppm)
{

  int tempArray[width * height * 3];

  for (int i = 0; i < height * width * 3; i++)
  {
    tempArray[i] = ppm[i];
  }

  for (int r = 0; r < height; r++)
  {
    for (int c = 0; c < width; c++)
    {
      int center = pixelToIndex(width, r, c);
      int top = pixelToIndex(width, r - 1, c);
      int bottom = pixelToIndex(width, r + 1, c);
      int left = pixelToIndex(width, r, c - 1);
      int right = pixelToIndex(width, r, c + 1);
      if (r != 0 && r + 1 != height && c != 0 && c + 1 != width)
      {

        int redValues = tempArray[center] + tempArray[top] + tempArray[bottom] +
                        tempArray[left] + tempArray[right];

        int greenValues = tempArray[center+1] + tempArray[top+1] + tempArray[bottom+1] +
                        tempArray[left+1] + tempArray[right+1];
        int blueValues = tempArray[center+2] + tempArray[top+2] + tempArray[bottom+2] +
                        tempArray[left+2] + tempArray[right+2];

        ppm[center] = (int)(redValues/5 + 0.5);
        ppm[center+1] = (int)(greenValues/5 + 0.5);
        ppm[center+2] = (int)(blueValues/5 + 0.5);
      }
    }
  }
}
bool transformImage(int width, int height, int *ppm, string action)
{

  if (action == "noRed")
  {
    noRed(width, height, ppm);
  }
  else if (action == "noGreen")
  {
    noGreen(width, height, ppm);
  }
  else if (action == "noBlue")
  {
    noBlue(width, height, ppm);
  }
  else if (action == "invert")
  {
    invert(width, height, ppm);
  }
  else if (action == "grayscale")
  {
    grayscale(width, height, ppm);
  }
  else if (action == "flipHorizontally")
  {
    flipHorizontally(width, height, ppm);
  }
  else if (action == "flipVertically")
  {
    flipVertically(width, height, ppm);
  }
  else if (action == "spin2_by_2")
  {
    spin2_by_2(width, height, ppm);
  }
  else if (action == "faderight")
  {
    faderight(width, height, ppm);
  }
  else if (action == "blur")
  {
    blur(width, height, ppm);
  }
  else
  {
    return false;
  }

  return true;
}