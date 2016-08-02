/**
 * @file
 * \brief Defines a Vector class
 *
 * @author Alicia Klinvex
 */

#ifndef MORPHEUS_VECTOR_H_
#define MORPHEUS_VECTOR_H_

/** \namespace Morpheus
 * \brief Contains linear algebra classes
 *
 * \todo Add a sparse matrix class
 */
namespace Morpheus {

/** \class Vector
 * \brief Stores a dense vector
 *
 * \todo Consider whether Vector should be a subclass of Matrix
 *
 * \example Morpheus_Vector_addScaleTest.cpp
 * Demonstrates the use of the vector addition and
 * vector scale functions
 *
 * \example Morpheus_Vector_normTest.cpp
 * Demonstrates the use of the vector norm functions
 */
class Vector {
public:

  /// \name Constructors and destructors
  ///@{
  /** \brief Constructor
   *
   * Allocates memory for a Vector.  If \a numElements is not
   * positive, the program terminates.
   * \param[in] numElements The number of entries in the vector
   *
   * \warning This function only allocates the memory; it does not
   * initialize the memory.
   */
  Vector(const int numElements);

  /** \brief Destructor
   *
   * Deallocates memory for a Vector
   */
  ~Vector();
  ///@}

  //! \name Accessor functions
  ///@{
  /** \brief Subscript operator
   *
   * Returns a reference to the entry at the location
   * denoted by \a subscript.
   * Example usage:
   * \code
   * Vector v(3);
   * v[0] = 1;
   * v[1] = 0;
   * v[2] = 0;
   * \endcode
   * \param[in] subscript The subscript of interest
   */
  double& operator[](const int subscript);

  /** \brief Const subscript operator
   *
   * Returns a const reference to the entry at the location
   * denoted by \a subscript.
   * Example usage:
   * \code
   * Vector v(3);
   * v.setValue();
   * double entry = v[0];
   * \endcode
   * \param[in] subscript The subscript of interest
   */
  const double& operator[](const int subscript) const;

  //! Returns the total number of entries
  int getNumElements() const;
  ///@}

  //! \name Linear algebra functions
  ///@{
  /** \brief Initializes all entries to \a alpha
   *
   * \param[in] alpha The number all entries are set
   * equal to.  Default: 0
   */
  void setValue(const double alpha=0);

  /** \brief Scales the vector
   *
   * Every entry in the vector is multiplied by \a alpha
   * \param[in] alpha The number to scale by
   */
  void scale(const double alpha);

  /** \brief %Vector addition
   *
   * Replaces \a sum by \a this + \a b.
   * \param[in] b Vector to add
   * \param[out] sum Sum vector
   * \note This function does not allocate memory;
   * it fills in the existing values of \a sum.  If \a this,
   * \a b, and \a sum are not the same size, the
   * function will abort.
   */
  void add(const Vector& b, Vector& sum) const;

  /** \brief Dot product
   *
   * If \a this and \a b are not the same size, this
   * function will abort
   * \param[in] b Vector to use in dot-product
   */
  double dot(const Vector& b) const;
  ///@}

  //! \name Norms
  ///@{

  //! Sum of all entries
  double norm1() const;

  //! Maximum magnitude entry
  double normInf() const;

  //! Length of vector
  double norm2() const;
  ///@}

  //! \name I/O functions
  ///@{
  /** \brief Prints vector to console
   *
   * Example:
   * <tt>\n
   * %Vector with 3 entries\n
   * data[0] = 0\n
   * data[1] = 0\n
   * data[2] = 7\n
   * </tt>
   */
  void print() const;
  ///@}

private:
  /** \brief Number of elements in the vector
   *
   * Cannot be changed after construction
   */
  int numElements_;
  /** \brief Pointer to raw data
   *
   * Allocated in the constructor and deallocated in the destructor.
   */
  double* data_;
};

} /* namespace Morpheus */
#endif /* MORPHEUS_VECTOR_H_ */

/** \mainpage Welcome to Morpheus!
 *
 * Morpheus is an exciting new linear algebra package.  It currently
 * contains a dense matrix and dense vector class, but we hope to
 * expand its features as it grows in popularity.
 *
 * \section other_sec How does Morpheus compare to other linear algebra packages?
 * It has way fewer features, but what we lack in features, we make up
 * for in bugs.
 *
 * \section cool_sec Is Morpheus greater than sliced bread?
 * That's not even a fair question.  Morpheus is the best thing that's
 * ever happened to math since the discovery of 0.  Speaking of which,
 * the history of the number 0 is super-cool and can be found here:
 * https://en.wikipedia.org/wiki/0_%28number%29#History
 *
 * \section point_sec Is this entire project just a Doxygen exercise?
 * No.  It is also an exercise on using code coverage tools such as gcov.
 */
