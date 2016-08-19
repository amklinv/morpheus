/*
 * Morpheus_Matrix_Tests.cpp
 *
 *  Created on: Jul 28, 2016
 *      Author: amklinv
 */

#include "Morpheus_Matrix.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

int main()
{
  bool testPassed = true;

  // Seed the random number generator
  srand(time(NULL));

  // Create a random matrix
  Morpheus::Matrix randMat(5,5);
  for(int r=0; r<5; r++)
  {
    for(int c=0; c<5; c++)
    {
      randMat(r,c) = rand();
    }
  }

  // Create an identity matrix
  Morpheus::Matrix eye(5,5);
  for(int r=0; r<5; r++)
  {
    for(int c=0; c<5; c++)
    {
      if(r == c)
        eye(r,c) = 1;
      else
        eye(r,c) = 0;
    }
  }

  // Multiply the two
  Morpheus::Matrix result(5,5);
  randMat.multiply(eye,result);

  // Assert that randMat is the same as the result
  if(!randMat.approxEqual(result,1e-10))
  {
    std::cout << "ERROR: The matrix product is incorrect\n";
    testPassed = false;
  }

  if(!eye.isSymmetric())
  {
    std::cout << "ERROR: The identity matrix should be symmetric\n";
    testPassed = false;
  }

  if(!eye.isUpperTriangular())
  {
    std::cout << "ERROR: The identity matrix should be upper triangular\n";
    testPassed = false;
  }

  if(testPassed) {
    std::cout << "Matrix test: PASSED!\n";
    return EXIT_SUCCESS;
  }
  else {
    std::cout << "Matrix test: FAILED!\n";
    return EXIT_FAILURE;
  }
}
