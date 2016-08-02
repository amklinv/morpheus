/**
 * @file
 * \brief Defines a Matrix class
 *
 * @author Alicia Klinvex
 */

#include "Morpheus_Matrix.h"
#include <cassert>
#include <cmath>
#include <iostream>

namespace Morpheus {

Matrix::Matrix(const int nrows, const int ncols)
{
  nrows_ = nrows;
  ncols_ = ncols;

  // Make sure the dimensions make sense
  assert(nrows_ > 0);
  assert(ncols_ > 0);

  // Allocate memory for the data
  data_ = new double*[nrows_];
  for(int r=0; r<nrows_; r++)
    data_[r] = new double[ncols_];
}


Matrix::~Matrix()
{
  // Free all the memory we allocated
  for(int r=0; r<nrows_; r++)
    delete[] data_[r];

  delete[] data_;
}


double& Matrix::operator()(const int row, const int col)
{
  return data_[row][col];
}


void Matrix::multiply(const Vector& X, Vector& Y) const
{
  // Make sure the dimensions are consistent
  assert(X.getNumElements() == ncols_);
  assert(Y.getNumElements() == nrows_);

  for(int r=0; r<nrows_; r++)
  {
    Y[r] = 0;
    for(int c=0; c<ncols_; c++)
    {
      Y[r] = Y[r] + data_[r][c]*X[c];
    }
  }
}


void Matrix::multiply(const Matrix& X, Matrix& Y) const
{
  // Make sure the dimensions are consistent
  assert(nrows_ == Y.nrows_);
  assert(ncols_ == X.nrows_);
  assert(X.ncols_ == Y.ncols_);

  for(int r=0; r<Y.nrows_; r++)
  {
    for(int c=0; c<Y.ncols_; c++)
    {
      Y(r,c) = 0;
      for(int k=0; k<ncols_; k++)
      {
        Y(r,c) = Y(r,c) + data_[r][k] * X.data_[k][c];
      }
    }
  }
}


bool Matrix::isSymmetric() const
{
  if(nrows_ != ncols_)
    return false;

  for(int r=0; r<nrows_; r++)
  {
    for(int c=0; c<ncols_; c++)
    {
      if(data_[r][c] != data_[c][r])
        return false;
    }
  }

  return true;
}


bool Matrix::isUpperTriangular() const
{
  if(nrows_ != ncols_)
    return false;

  for(int r=0; r<nrows_; r++)
  {
    for(int c=r+1; c<ncols_; c++)
    {
      if(data_[r][c] != 0)
        return false;
    }
  }

  return true;
}


// Maximum absolute column sum
double Matrix::norm1() const
{
  double curColSum;
  double maxColSum = 0;
  for(int c=0; c<ncols_; c++)
  {
    curColSum = 0;
    for(int r=0; r<nrows_; r++)
    {
      curColSum = curColSum + data_[r][c];
    }
    if(curColSum > maxColSum)
      maxColSum = curColSum;
  }
  return maxColSum;
}


// Maximum absolute row sum
double Matrix::normInf() const
{
  double curRowSum;
  double maxRowSum = 0;
  for(int r=0; r<nrows_; r++)
  {
    curRowSum = 0;
    for(int c=0; c<ncols_; c++)
    {
      curRowSum = curRowSum + data_[r][c];
    }
    if(curRowSum > maxRowSum)
      maxRowSum = curRowSum;
  }
  return maxRowSum;
}


int Matrix::getNumRows() const
{
  return nrows_;
}


int Matrix::getNumCols() const
{
  return ncols_;
}


int Matrix::getNumEntries() const
{
  return (nrows_*ncols_);
}


bool Matrix::approxEqual(const Matrix& m, const double tol) const
{
  if(nrows_ != m.nrows_ || ncols_ != m.ncols_)
    return false;

  for(int r=0; r<nrows_; r++)
  {
    for(int c=0; c<ncols_; c++)
    {
      if(std::abs(data_[r][c] - m.data_[r][c]) > tol)
        return false;
    }
  }
  return true;
}


void Matrix::print() const
{
  std::cout << nrows_ << "x" << ncols_ << " Matrix\n";
  for(int r=0; r<nrows_; r++)
  {
    for(int c=0; c<ncols_; c++)
    {
      std::cout << data_[r][c] << " ";
    }
    std::cout << std::endl;
  }
}

} /* namespace Morpheus */
