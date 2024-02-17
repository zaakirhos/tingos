#pragma once

#include <string>

/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

/**
 * A function to determine the location of a pixel in a PPM image array.
 * Writing this routine makes it easier to write your other image
 * transformation functions.
 * @param width The width of the PPM image.
 * @param rIndex The row index of the pixel .
 * @param cIndex The column coordinate of the pixel .
 * @return The index of the first integer in the specified pixel.
 * For example:
 *         if x==1 and y==0, this function returns 3.
 */
int pixelToIndex(int width, int rIndex, int cIndex);

/**
 * A function to swap two integers representing weights of the RGB value
 * @param colorWeight1 A value from 0-255
 * @param colorWeight2 A value from 0-255
*/
void swapColorValue(int* colorWeight1, int* colorWeight2);
/**
 * A function which removes a given color (red, green, blue)
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 * @param c indicates which color to be removed (r -> red, g -> green, b -> blue)
 */

void drainColor(int width, int height, int* ppm, char c);

/**
 * A function which removes the red from an image.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void noRed(int width, int height, int* ppm);

/**
 * A function which removes the green from an image.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void noGreen(int width, int height, int *ppm);

/**
 * A function which removes the blue from an image.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void noBlue(int width, int height, int *ppm);

/**
 * A function which inverts the image.
 *  All channels are subtracted from 255. For instance, 255 128 0 would become 0 127 255.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void invert(int width, int height, int *ppm);

/**
 * A function which transforms the image into a grayscale version
 *  The channels of each pixel are averaged. 
 * For instance, the pixel 255 128 0 would become 127 127 127 
 * (since (255+128+0)/3 is approximately 127).
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void grayscale(int width, int height, int *ppm);

/**
 * A function which flips the image horizontally.
 *  The first pixel in each row becomes the last pixel in that row, 
 * the second pixel in each row becomes the second-to-last pixel in that row, 
 * and so on. The result is a mirror image of the original picture.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void flipHorizontally(int width, int height, int *ppm);

/**
 * A function which flips the image vertically.
 * The first pixel in each column becomes the last pixel in that column, 
 * the second pixel in each column becomes the second-to-last pixel in that column,
 * and so on. As a result, the image should appear upside-down.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void flipVertically(int width, int height, int *ppm);

/**
 * A function which rotates each 2x2 block of pixels in the image by 180 degrees. 
 * That is, we swap (0,0) with (1,1), (1,0) with (0,1), (2,0) with (3,1), (3,0) with (2,1), etc.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void spin2_by_2(int width, int height, int *ppm);

/**
 * A function which brighten each pixel by an amount determined by how far to the 
 * left or right it is in the image. The leftmost pixels will be their original color; 
 * the rightmost pixels will be bright white.
 * That is, we swap (0,0) with (1,1), (1,0) with (0,1), (2,0) with (3,1), (3,0) with (2,1), etc.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void faderight(int width, int height, int *ppm);


/**
 * For each pixel, this function set its values to the average of itself and those pixels adjacent to it. 
 * That is, the new red value of (1,1) is the average of the old red values of (1,1), (0,1), 
 * (1,0), (2,1), and (1,2).
 * That is, we swap (0,0) with (1,1), (1,0) with (0,1), (2,0) with (3,1), (3,0) with (2,1), etc.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void blur(int width, int height, int *ppm);

/**
 * A function to transform an image with the appropriate action
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 * @param action the action to be performed
 * 
 * @return true if it was able to transform, false if transformation failed
*/
bool transformImage(int width, int height, int *ppm, std::string action);
    // TODO: write your other image transformation headers here
