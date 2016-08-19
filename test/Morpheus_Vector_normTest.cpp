/*
 * Morpheus_Vector_normTest.cpp
 *
 *  Created on: Jul 28, 2016
 *      Author: amklinv
 */

#include "Morpheus_Vector.h"
#include <cmath>
#include <iostream>
#include "stdlib.h"

// Returns true if | a-b | < tol, false otherwise
bool approxEqual(double a, double b, double tol);

int main()
{
  bool testPassed = true;
  int numEntries = 5;

  // Create a vector with 10 entries
  Morpheus::Vector vec(numEntries);

  // Set the entries in this vector
  // Each entry is 1/sqrt(n)
  double rootN = std::sqrt(numEntries);
  double invRootN = 1./rootN;
  for(int i=0; i<numEntries; i++) {
    vec[i] = invRootN;
  }

  // 1-norm should be sqrt(n)
  // infinity-norm should be 1/sqrt(n)
  // 2-norm should be 1
  double norm1 = vec.norm1();
  double normInf = vec.normInf();
  double norm2 = vec.norm2();

  if(!approxEqual(norm1, sqrt(numEntries), 1e-10))
  {
    std::cout << "ERROR: The 1-norm is incorrect\n";
    testPassed = false;
  }
  if(!approxEqual(normInf, invRootN, 1e-10))
  {
    std::cout << "ERROR: The infinity-norm is incorrect\n";
    testPassed = false;
  }
  if(!approxEqual(norm2, 1, 1e-10))
  {
    std::cout << "ERROR: The 2-norm is incorrect\n";
    testPassed = false;
  }

  if(testPassed) {
    std::cout << "Norm test: PASSED!\n";
    return EXIT_SUCCESS;
  }
  else {
    std::cout << "Norm test: FAILED!\n";
    return EXIT_FAILURE;
  }
}


// Returns true if | a-b | < tol, false otherwise
bool approxEqual(double a, double b, double tol)
{
  if(std::abs(a-b) < tol)
    return true;
  return false;
}
