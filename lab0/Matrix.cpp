/* Matrix.cpp defines non-trivial Matrix operations.
 * Author: Joel C. Adams, for C++ An Intro to Computing 3/e.
 * Copyright 2002, Joel C. Adams.  All rights reserved.
 */

#include "Matrix.h"
#include <cassert>
#include <fstream>
using namespace std;

/* --- utility to allocate space dynamically
 * Parameters: rows and columns, two unsigned ints.
 * Precondition: rows > 0 && columns > 0.
 * Postcondition: myMatrix points to a rows x columns matrix.
 */
 void Matrix::allocate(unsigned rows, unsigned columns) {
 	// avoid memory leak
 	if (myMatrix != NULL) {
 		deallocate();
 	}
 	// allocate 'row of rows'
 	myMatrix = new Item* [rows];
 	// allocate the individual rows
 	for (unsigned i = 0; i < rows; i++) {
 		myMatrix[i] = new Item[columns];
 	}
 }
 
 /* --- utility to deallocate my storage
  * Postcondition: my storage has been returned to the heap &&
  *                 myMatrix == NULL.
  */
 void Matrix::deallocate() {
 	// first delete the individual rows
 	for (unsigned i = 0; i < myRows; i++) {
 		delete [] myMatrix[i];
 	}
 	// then delete the 'row of rows'
 	delete [] myMatrix;
 	// clean up
 	myMatrix = NULL;
 }
 
/* --- output using *this
 * Parameter: out, an ostream.
 * Precondition: out is an open ostream
 * Postcondition: my values have been inserted into out,
 *                 with tab chars between each value.
 */
void Matrix::print(ostream& out) const {
   for (unsigned i = 0; i < myRows; i++) {
      for (unsigned j = 0; j < myColumns; j++) {
      	out << myMatrix[i][j] << '\t';
      }
      out << endl;
   }
}

/* Alterative version of print() using iterators
void Matrix::print(ostream& out) const
{
   TwoDimVector::iterator rowIt = begin();
   OneDimVector::iterator columnIt;

   while (rowIt != end())
   {
      columnIt = (*rowIt).begin();
      while (columnIt != (*rowIt).end())
      {
         out << *columnIt << '\t';
         columnIt++;
      }
      out << endl;
      rowIt++;
   }
}
*/

/* --- input using *this
 * Parameter: in, an ostream.
 * Precondition: in is an open istream
 *                containing myRows x myColumns values.
 * Post condition: I now contain a copy of the values from in.
 */
void Matrix::read(istream& in) {
   for (unsigned i = 0; i < myRows; i++) {
   	  for (unsigned j = 0; j < myColumns; j++) {
   	  	in >> myMatrix[i][j];
   	  }
   }
}

/* --- input from file
 * Parameter: fileName, a string.
 * Precondition: fileName is the name of (or path to) a file,
 *                 the first line of file is #rows #columns, 
 *                 and the remainder of which is rows x columns values.
 * Postcondition: myRows == rows && myColumns == columns &&
 *                 I contain the other values from fileName.
 */
void Matrix::fill(const string& fileName) {
	ifstream fin( fileName.c_str() );
	assert ( fin.is_open() );
	unsigned rows, columns;
	fin >> rows >> columns;
	assert (rows > 0 && columns > 0);
	myRows = rows; myColumns = columns;
	allocate(rows, columns);
	Item value;
	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < columns; j++) {
			fin >> value;
			assert( !fin.eof() );
			myMatrix[i][j] = value;
		}
	}
	fin.close();
}

/* --- boolean equality
 * Parameter: mat2, a Matrix.
 * Postcondition: true is returned, if and only if
 *                 myRows == mat2.rows() &&
 *                 myColumns == mat2.columns() &&
 *                 my values are the same as mat2's values.
 */
bool Matrix::operator ==(const Matrix& mat2) const {
	if (myColumns != mat2.getColumns() || myRows != mat2.getRows() ) {
		return false;
	}
	for (unsigned i = 0; i < mat2.getRows(); i++) {
		for (unsigned j = 0; j < mat2.getColumns(); j++) {
			if ( myMatrix[i][j] != mat2.get(i,j) ) {
				return false;
			}
		}
	}
	return true;
}


/* --- multiplication
 * Parameters: mat2, a Matrix.
 * Precondition: myColumns == mat2.rows().
 * Postcondition: a Matrix is returned containing the product of
 *                 my values and those of mat2.
 */
Matrix Matrix::operator*(const Matrix& mat2) const
{
  assert (myColumns == mat2.getRows());          // check dimensions

  Matrix mat3(myRows, mat2.getColumns());        // build result Matrix

  for (unsigned i = 0; i < myRows; i++)            // for each of my rows:
    for (unsigned j = 0; j < mat2.getColumns(); j++)  //  for each col in mat2:
    {
       double sum = 0;
       for (unsigned k = 0; k < myColumns; k++)    //   for each of my columns:
          sum += myMatrix[i][k] * mat2.get(k,j);  //     sum the products
       mat3.set(i, j, sum);                      //    put sum in result Matrix
    }
  return mat3;                                // return result matrix
}
