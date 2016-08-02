/**
 * @file
 * \brief Defines a Vector class
 *
 * @author Alicia Klinvex
 */

#include <iostream>
#include <cassert>
#include <cmath>
#include "Morpheus_Vector.h"

namespace Morpheus {

Vector::Vector(const int numElements)
{
  assert(numElements > 0);

  numElements_ = numElements;

  // Allocate memory for the data
  data_ = new double[numElements_];
}


Vector::~Vector()
{
  // Release the memory
  delete[] data_;
}


double& Vector::operator[](const int subscript)
{
  // Make sure the subscript is valid
  // Terminate the program if it's not
  assert(subscript >= 0 && subscript < numElements_);

  return data_[subscript];
}


const double& Vector::operator[](const int subscript) const
{
  // Make sure the subscript is valid
  // Terminate the program if it's not
  assert(subscript >= 0 && subscript < numElements_);

  return data_[subscript];
}


int Vector::getNumElements() const
{
  return numElements_;
}


void Vector::setValue(const double alpha)
{
  for(int i=0; i<numElements_; i++)
  {
    data_[i] = alpha;
  }
}


void Vector::scale(const double alpha)
{
  for(int i=0; i<numElements_; i++)
  {
    data_[i] = alpha * data_[i];
  }
}


void Vector::add(const Vector& b, Vector& sum) const
{
  // Make sure all three vectors are the same size
  assert(this->numElements_ == b.numElements_);
  assert(this->numElements_ == sum.numElements_);

  // Compute the sum of each entry
  for(int i=0; i<this->numElements_; i++)
  {
    sum.data_[i] = this->data_[i] + b.data_[i];
  }
}


double Vector::dot(const Vector& b) const
{
  // Make sure the vectors are the same size
  assert(this->numElements_ == b.numElements_);

  double sum;

  // Compute the sum of all the products
  for(int i=0; i<this->numElements_; i++)
  {
    sum = sum + (this->data_[i] * b.data_[i]);
  }

  return sum;
}


double Vector::norm1() const
{
  double sum = 0;

  // Compute the sum of all the entries magnitudes
  for(int i=0; i<numElements_; i++)
  {
    sum = sum + data_[i];
  }

  return sum;
}


double Vector::normInf() const
{
  double maxVal = 0;

  // Find the biggest entry
  for(int i=0; i<numElements_; i++)
  {
    double absVal = data_[i];
    if(absVal > maxVal)
    {
      maxVal = absVal;
    }
  }

  return maxVal;
}


double Vector::norm2() const
{
  double sum = 0;

  // Compute the sum of squares
  for(int i=0; i<numElements_; i++)
  {
    sum = sum + (data_[i]*data_[i]);
  }

  return sum;
}


void Vector::print() const
{
  std::cout << "Vector with " << numElements_ << " entries\n";
  for(int i=0; i<numElements_; i++)
  {
    std::cout << "data[" << i << "] = " << data_[i] << std::endl;
  }
}

} /* namespace Morpheus */
