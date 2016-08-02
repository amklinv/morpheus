/**
 * @file
 * \brief Defines a Matrix class
 *
 * @author Alicia Klinvex
 */

#ifndef MORPHEUS_MATRIX_H_
#define MORPHEUS_MATRIX_H_

#include "Morpheus_Vector.h"

namespace Morpheus {

/** \class Matrix
 * \brief Stores a dense matrix
 *
 * \todo Add a function for computing the Frobenius norm
 * \todo Add a function for computing the 2-norm
 * \todo Add a function for reading a matrix from a file
 *
 * \example Morpheus_Matrix_Tests.cpp
 * Demonstrates the usage of the matrix class
 */
class Matrix {
public:
  //! \name Constructors and destructors
  ///@{
  /** \brief Constructor
   *
   * Allocates memory for a dense matrix.
   * If either nrows or ncols is not positive, the program terminates.
   * \param[in] nrows Number of rows
   * \param[in] ncols Number of columns
   */
  Matrix(const int nrows, const int ncols);

  /** \brief Destructor
   *
   * Deallocates memory allocated in the constructor
   */
  ~Matrix();
  ///@}

  //! \name Accessor functions
  ///@{
  /** \brief Accesses a single entry of the matrix
   *
   * \param[in] row Row
   * \param[out] col Column
   *
   * \note This is 0-based, not 1-based indexing
   *
   * Usage:
   * \code
   * Matrix m(4,3);
   * m(0,0) = 1; m(0,1) = 0; m(0,2) = 0;
   * m(1,0) = 0; m(1,1) = 1; m(1,2) = 0;
   * m(2,0) = 0; m(2,1) = 0; m(2,2) = 1;
   * m(3,0) = 0; m(3,1) = 0; m(3,2) = 0;
   * \endcode
   * creates the matrix\n
   * \f$\left[\begin{array}{rrr}
   * 1&0&0\\0&1&0\\0&0&1\\0&0&0
   * \end{array}\right]\f$
   */
  double& operator()(const int row, const int col);

  //! Returns the number of rows
  int getNumRows() const;

  //! Returns the number of columns
  int getNumCols() const;

  //! Returns the number of entries
  int getNumEntries() const;
  ///@}

  //! \name Multiplication routines
  ///@{
  /** \brief Computes a matrix-vector multiplication
   *
   * \param[in] X vector to be multiplied
   * \param[out] Y result of multiplication
   *
   * \note This function does not allocate memory for \a Y; it only
   * fills in the values.  The number of rows of the matrix
   * must equal the number of entries in \a Y.  The number of columns
   * of the matrix must equal the number of entries in \a X.  Otherwise,
   * the program will terminate.
   *
   * \todo Write a test for this function
   */
  void multiply(const Vector& X, Vector& Y) const;

  /** \brief Computes a matrix-matrix multiplication
   *
   * \param[in] X matrix to be multiplied
   * \param[out] Y result of multiplication
   *
   * \note This function does not allocate memory for \a Y; it only fills
   * in the values.  The number of rows of the calling
   * matrix must equal the number of rows of \a Y.  The number of columns
   * of the calling matrix must equal the number of rows of \a X.  \a X
   * and \a Y must have the same number of columns.  Otherwise,
   * the program will terminate.
   */
  void multiply(const Matrix& X, Matrix& Y) const;
  ///@}

  //! \name Matrix property query methods
  ///@{
  /** \brief Determines whether the matrix is symmetric
   *
   * \note The symmetry is not stored as a property of the
   * matrix.  Every time this function is called, it will
   * perform the O(n^2) comparison of entries.
   */
  bool isSymmetric() const;

  /** \brief Determines whether the matrix is upper triangular
   *
   * \note This is not stored as a property of the matrix.
   * Every time this function is called, it will perform the
   * O(n^2) comparison of entries.
   */
  bool isUpperTriangular() const;

  /** \brief Determines whether this matrix is approximately equal
   * to another matrix
   *
   * Returns true if
   * - \a this and \a m are the same size
   * - \a this(r,c) == \a m(r,c) for all \a r, \a c
   *
   * \param[in] m The matrix to be compared
   * \param[in] tol The tolerance of the comparison
   */
  bool approxEqual(const Matrix& m, const double tol) const;
  ///@}

  //! \name Norms
  ///@{

  //! Maximum absolute column sum
  double norm1() const;

  //! Maximum absolute row sum
  double normInf() const;
  ///@}

  //! \name I/O functions
  ///@{
  /** \brief Prints matrix to console
   *
   * Example:
   * <tt>\n
   * 4x3 %Matrix\n
   * 1 0 0\n
   * 0 1 0\n
   * 0 0 1\n
   * 0 0 0\n
   * </tt>
   */
  void print() const;
  ///@}

private:
  //! Number of rows
  int nrows_;
  //! Number of columns
  int ncols_;
  //! Pointer to raw data
  double** data_;
};

} /* namespace Morpheus */
#endif /* MORPHEUS_MATRIX_H_ */
