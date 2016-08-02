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
 * Okay, so Morpheus is really just a test project for an ATPESC
 * tutorial...but at least it has a cool name!
 *
 * \section gcov_section gcov tutorial
 * -# Please log in to vesta\n
 *    <tt>ssh \<username\>\@vesta.alcf.anl.gov</tt>
 * -# Clone the Morpheus repository\n
 *    <tt>git clone https://github.com/amklinv/morpheus.git</tt>
 * -# Build the tests\n
 *    <tt>cd morpheus</tt>\n
 *    <tt>make</tt>\n
 *    Note that the proper coverage flags have been added to your
 *    makefile.  Also note that this step generates a set of .gcno
 *    files for you.
 * -# Run the tests\n
 *    <tt>./runtests</tt>\n
 *    <tt>runtests</tt> is a perl script which runs the three tests
 *    for you.  This step generates the .gcda files.
 * -# Run gcov on the Morpheus source code\n
 *    <tt>gcov *.cpp</tt>\n
 *    Ignore the system files; we are not responsible for testing
 *    them.  This will generate our .gcov files
 * -# Examine Morpheus_Vector.cpp.gcov and Morpheus_Matrix.cpp.gcov\n
 *    These are regular text files, so you may use your text editor
 *    of choice (vim, emacs, eclipse...or you can just <tt>cat</tt>
 *    the file).  Lines that have been tested are marked by the number
 *    of times they were executed.  Lines that have NOT been tested
 *    are preceeded by <tt>#####</tt>.  Dashes denote lines that
 *    contain no instructions, such as blank lines or curly braces.\n
 *    Example:
 *    <tt>\n
 *    \verbatim
      5:   85:bool Matrix::isSymmetric() const
      -:   86:{
      5:   87:  if(nrows_ != ncols_)
  #####:   88:    return false;
      -:   89:
     30:   90:  for(int r=0; r<nrows_; r++)
      -:   91:  {
    150:   92:    for(int c=0; c<ncols_; c++)
      -:   93:    {
    125:   94:      if(data_[r][c] != data_[c][r])
  #####:   95:        return false;
      -:   96:    }
      -:   97:  }
      -:   98:
      5:   99:  return true;
      -:  100:}
   \endverbatim
   </tt>
 * \subsection food_sec Food for thought..
 * - What percentage of Morpheus_Vector.cpp and Morpheus_Matrix.cpp
 *   did gcov report was being tested?
 * - How much confidence do you have that my code is correct?
 * - If we had 100% code coverage, would that mean there were no bugs?
 *   Why?
 * - Which of the following Vector functions are tested?
 *   - Constructor
 *   - Destructor
 *   - Subscript operator
 *   - Const subscript operator
 *   - getNumElements
 *   - setValue
 *   - scale
 *   - add
 *   - dot
 *   - norm1
 *   - normInf
 *   - norm2
 * - Are the two tests that exist for the Vector class good?
 * - What types of data did I ignore?
 * - What kinds of errors could occur as a result of me ignoring
 *   those types of data?
 * - For which of the following vectors would the 1-norm function
 *   produce the correct result?  The infinity-norm?  The 2-norm?\n
 *   \f$\left[\begin{array}{r}1\\2\\3\end{array}\right]\f$
 *   \f$\left[\begin{array}{r}1\\0\\0\end{array}\right]\f$
 *   \f$\left[\begin{array}{r}-1\\0\\0\end{array}\right]\f$
 * - Which of the following Matrix functions are tested?
 *   - Constructor
 *   - Destructor
 *   - Subscript operator
 *   - getNumRows
 *   - getNumCols
 *   - getNumEntries
 *   - Matrix-vector multiply
 *   - Matrix-matrix multiply
 *   - isSymmetric
 *   - isUpperTriangular
 *   - approxEqual
 *   - norm1
 *   - normInf
 *   - print
 * - Is it sufficient to test the isUpperTriangular function with the
 *   identity matrix?  Why?
 * - If my tests failed, would it be easy to track down the source of
 *   the problem?  What could I do to make it easier?
 *
 * \section doxy_sec Doxygen
 * To create the html pages you're currently looking at, all you have
 * to do is type <tt>doxygen</tt> in the source directory.  (Doxygen
 * is already installed on Vesta.)  It reads <tt>Doxyfile</tt>, which
 * I generated with <tt>doxywizard</tt> on my workstation and checked
 * into the repository.  Alternatively, you can generate such files by
 * hand.
 *
 * \subsection latex_sec Didn't you say Doxygen can generate LaTeX manuals?
 * \htmlonly
 * Yes.  You can find the one for this site
 * <a href=refman.pdf>here</a>.
 * \endhtmlonly
 * \latexonly
 * Yes.  You're looking at it.
 * \endlatexonly
 *
 * \section gui_sec What about the beautiful GUIs you showed us?
 * <tt>lcov</tt> and <tt>doxywizard</tt> are great tools for a personal
 * workstation, but not-so-great tools for computing clusters.  I
 * personally prefer using the GUIs, but it's important to know how to
 * use <tt>gcov</tt> and <tt>doxygen</tt> too, since they're available
 * on more systems.  If you desperately need the HTML files generated
 * by <tt>lcov</tt>, they are available
 * <a href="lcovFiles/index.html">here</a>.
 *
 */
