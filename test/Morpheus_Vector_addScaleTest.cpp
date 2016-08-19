/*
 * Morpheus_Vector_addScaleTest.cpp
 *
 *  Created on: Jul 28, 2016
 *      Author: amklinv
 */

#include "Morpheus_Vector.h"
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
  bool testPassed = true;
  int numEntries = 10;

  // Seed the random number generator
  srand(time(NULL));

  // Create three vectors, all with 10 entries
  Morpheus::Vector vecA(numEntries);
  Morpheus::Vector vecB(numEntries);
  Morpheus::Vector vecC(numEntries);

  // Set the entries in vecA
  // Each entry is random
  for(int i=0; i<numEntries; i++) {
    vecA[i] = rand();
  }

  // Copy the entries of vecA to vecB
  for(int i=0; i<numEntries; i++) {
    vecB[i] = vecA[i];
  }

  // Scale vecB by -1
  vecB.scale(-1);

  // Compute vecC = vecA + vecB
  vecA.add(vecB, vecC);

  // vecC should be all 0s, so its norm should be too
  double norm2 = vecC.norm2();

  if(norm2 > 1e-10)
  {
    std::cout << "ERROR: C must be 0\n";
    testPassed = false;
  }

  if(testPassed) {
    std::cout << "Add/scale test: PASSED!\n";
    return EXIT_SUCCESS;
  }
  else {
    std::cout << "Add/scale test: FAILED!\n";
    return EXIT_FAILURE;
  }
}
