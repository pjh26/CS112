/* Matrix.cpp defines Matrix class methods.
 * Student Name: Peter Haagsma
 * Date: February 27, 2018
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "Matrix.h"

// Default Constructor
Matrix::Matrix() {
	myRows = myColumns = 0;
}


/* Explicit Constructor
 * @param: unsigned rows, and unsigned columns of a matrix object
 */
Matrix::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

/* Getter for rows of Matrix object
 * Returns: myRows; number of rows in object
 */
const unsigned Matrix::getRows() const {
	return myRows;
}


/* Getter for columns of Matrix object
 * Returns: myColumns; number of columns in object
 */
const unsigned Matrix::getColumns() const {
	return myColumns;
}


/* Overrides subscript operator for Matrix object
 * @param:  unsigned row (index)
 * Returns: A const Vec object stored at the index value
 */
const Vec<Item>& Matrix::operator[](unsigned row) const {
	if (myRows == 0) {
		throw range_error("No values in empty Matrix.");
	} else if (row >= 0 && row <= myRows -1) {
		return myVec[row];
	}
	else {
		throw range_error("Index outside matrix range.");
	}
}


/* Overrides subscript operator for Matrix object
 * @param:  unsigned row (index)
 * Returns: A changeable Vec object stored at the index value
 */
Vec<Item>& Matrix::operator[](unsigned row) {
	if (myRows == 0) {
		throw range_error("No values in empty Matrix.");
	} else if (row >= 0 && row <= myRows -1) {
		return myVec[row];
	}
	else {
		throw range_error("Index outside matrix range.");
	}
}


/* Overrides the == operator for Matrix objects
 * @param: a matrix object to be compared to myMatrix
 * Returns: true if the Matrixes are equal in size and values and false otherwise
 */
bool Matrix::operator==(const Matrix& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}

