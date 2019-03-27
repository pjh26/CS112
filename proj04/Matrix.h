/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: Peter Haagsma & Samuel Poortenga
 * Date: March 05, 2018
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 *
 * operator!=()			written by: Samuel Poortenga
 * readFrom(istream)	written by: Samuel Poortenga
 * writeTo(ostream)		written by: Peter Haagsma
 * readFrom(string)		written by: Peter Haagsma
 * writeTo(string)		written by: Samuel Poortenga
 * operator+()			written by: Samuel Poortenga
 * operator-()			written by: Peter Haagsma
 * getTranspose()		written by: Peter Haagsma
 *
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"
#include <stdexcept>
#include <fstream>
#include <cassert>

template<class Item>
class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	const unsigned getRows() const;
	const unsigned getColumns() const;

	const Vec<Item>& operator[](unsigned row) const;
	Vec<Item>& operator[](unsigned row);
	bool operator==(const Matrix<Item>& m2) const;
	bool operator!=(const Matrix<Item>& m2) const;
	const Matrix<Item> operator-(const Matrix<Item>& m2) const;
	Matrix<Item> operator+(const Matrix<Item>& m2);
	const Matrix<Item> getTranspose() const;

	void readFrom(istream& fin);
	void readFrom(const string& fileName);
	void writeTo(ostream& fout);
	void writeTo(const char* fileName);
private:
	unsigned myRows;
	unsigned myColumns;
	Vec<Vec<Item> > myVec;

	friend class MatrixTester;
};

// Default Constructor
template<class Item>
Matrix<Item>::Matrix() {
	myRows = myColumns = 0;
}

/* Explicit Constructor
 * @param: unsigned rows, and unsigned columns of a matrix object
 */
template<class Item>
Matrix<Item>::Matrix(unsigned rows, unsigned columns) {
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
template<class Item>
const unsigned Matrix<Item>::getRows() const {
	return myRows;
}

/* Getter for columns of Matrix object
 * Returns: myColumns; number of columns in object
 */
template<class Item>
const unsigned Matrix<Item>::getColumns() const {
	return myColumns;
}

/* Overrides subscript operator for Matrix object
 * @param:  unsigned row (index)
 * Returns: A const Vec object stored at the index value
 */
template<class Item>
const Vec<Item>& Matrix<Item>::operator[](unsigned row) const {
	if (myRows == 0) {
		throw range_error("No values in empty Matrix.");
	} else if (row >= 0 && row <= myRows - 1) {
		return myVec[row];
	} else {
		throw range_error("Index outside matrix range.");
	}
}

/* Overrides subscript operator for Matrix object
 * @param:  unsigned row (index)
 * Returns: A changeable Vec object stored at the index value
 */
template<class Item>
Vec<Item>& Matrix<Item>::operator[](unsigned row) {
	if (myRows == 0) {
		throw range_error("No values in empty Matrix.");
	} else if (row >= 0 && row <= myRows - 1) {
		return myVec[row];
	} else {
		throw range_error("Index outside matrix range.");
	}
}

/* Overrides the == operator for Matrix objects
 * @param: a matrix object to be compared to myMatrix
 * Returns: true if the Matrixes are equal in size and values and false otherwise
 */
template<class Item>
bool Matrix<Item>::operator==(const Matrix<Item>& m2) const {
	if (myRows != m2.getRows() || myColumns != m2.getColumns()) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}


/* Overrides the - operator for Matrix objects
 * Author: Peter Haagsma
 * @param: read only reference Matrix object
 * Returns: a matrix holding the values of myVec - m2
 */
template<class Item>
const Matrix<Item> Matrix<Item>::operator-(const Matrix<Item>& m2) const {
	if (myRows != m2.getRows() || myColumns != m2.getColumns()) {
		throw invalid_argument("Matrices must be equal in size.");
	} else {
		Matrix<Item> tempMatrix(myRows, myColumns);
		for (unsigned i = 0; i < myRows; ++i) {
			for (unsigned j = 0; j < myColumns; ++j) {
				tempMatrix[i][j] = myVec[i][j] - m2[i][j];
			}
		}
		return tempMatrix;
	}
}


/* Transposes the Matrix, this transforms the rows into columns and columns into rows
 * Author: Peter Haagsma
 * Returns: Transposed copy of myVec
 */
template<class Item>
const Matrix<Item> Matrix<Item>::getTranspose() const {
	Matrix<Item> tempMatrix(myColumns, myRows);

	for (unsigned i = 0; i < myColumns; i++) {
		for (unsigned j = 0; j < myRows; j++) {
			tempMatrix[i][j] = myVec[j][i];
		}
	}
	return tempMatrix;
}


/* Outputs the rows and columns to an ostream and outputs matrix values out the ostream
 * Author: Peter Haagsma
 * @param: osgream fout
 * Precondition : Matrix object and an empty ostream
 * Postcondition: ostream object matching the Matrix object
 */
template<class Item>
void Matrix<Item>::writeTo(ostream& fout) {
	for (unsigned i = 0; i < myRows; ++i) {
		for (unsigned j = 0; j < myColumns; j++) {
			fout << myVec[i][j] << "\t";
		}
		fout << "\n";
	}
}


/* project04 Samuel Poortenga
 * != returns true if the matrices are unequal in size, false if otherwise.
 * @param two matrices
 * Return: bool
 */
template<class Item>
bool Matrix<Item>::operator!=(const Matrix& m2) const {
	if (myRows != m2.getRows() || myColumns != m2.getColumns()) {
		return true;
	} else {
		return myVec != m2.myVec;
	}
}
/* project04 Samuel Poortenga
 * readFrom() reads a matrix from istream
 * @param istream& in
 * Postcondition: reads a matrix from input
 */
template<class Item>
void Matrix<Item>::readFrom(istream& in) {

	for (unsigned row = 0; row < getRows(); row++) {
		for (unsigned column = 0; column < getColumns(); column++) {
			in >> myVec[row][column];
//put cin into [row][column]
		}
	}
}

/* project04 Samuel Poortenga
 * readFrom() reads a matrix from a file
 * @param const string& fileName
 * Postcondition: matrix from file
 */
template<class Item>
void Matrix<Item>::readFrom(const string& fileName) {
	ifstream fin(fileName.c_str());
	fin >> myRows >> myColumns;
//cout<<myRows<<"and"<<myColumns;
	myVec.setSize(myRows);
	for (unsigned i = 0; i < myRows; ++i) {
		myVec[i].setSize(myColumns);
	}

	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			fin >> myVec[i][j];
		}
	}
	fin.close();
}


/* project04 Samuel Poortenga
 * writeTo()
 * @param const char* fileName
 * Postcondition: matrix written to file
 */
template<class Item>
void Matrix<Item>::writeTo(const char* fileName) {
	ofstream fout(fileName);
	assert(fout.is_open());
//can never remember how to do this.

	Matrix temp;

	fout << myRows << " " << myColumns << endl;

	for (unsigned row = 0; row < getRows(); row++) {
		for (unsigned column = 0; column < getColumns(); column++) {

			fout << myVec[row][column] << " ";

		}
		fout << endl;
	}

}


/* project04 Samuel Poortenga
 * + adds two matrices of equal size
 * @param const Matrix<Item>& m2
 * Return: matrix
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator+(const Matrix<Item>& m2) {
	Matrix<Item> tempMatrix(myRows, myColumns);

	if ((myRows == m2.myRows) and (myColumns == m2.myColumns)) {
		for (unsigned row = 0; row < getRows(); row++) {
			for (unsigned column = 0; column < getColumns(); column++) {
				tempMatrix[row][column] = myVec[row][column] + m2[row][column];
			}
		}
		return tempMatrix;
	} else {
		throw invalid_argument("Matrices of different sizes.");
	}
}

#endif
