/* Matrix.h contains a simple class Matrix.
 * Author: Joel C. Adams, for C++ An Intro to Computing 3/e.
 * Copyright 2002, Joel C. Adams.  All rights reserved.
 ****************************************************************/

#ifndef MATRIX
#define MATRIX

#include <vector>     // vector
#include <iostream>   // istream, ostream
#include <cassert>    // assert()
using namespace std;

typedef double Item;

class Matrix {
 public:
   Matrix();
   Matrix(unsigned rows, unsigned columns);
   ~Matrix();
   
   Item get(unsigned row, unsigned col) const;
   void set(unsigned row, unsigned col, Item value);
   
   unsigned getRows() const;
   unsigned getColumns() const;
   void print(ostream& out) const;
   void read(istream& in);
   void fill(const string& fileName);
   
   bool operator==(const Matrix& mat1) const;
   Matrix operator*(const Matrix& mat1) const; 
   // ... additional operations omitted ...
protected:
   void allocate(unsigned rows, unsigned columns);
   void deallocate();
 private:
   unsigned myRows,
            myColumns;
   Item**   myMatrix;
};

/* default constructor
 * Postcondition: myRows == 0 && myColumns == 0 &&
 *                 myMatrix == NULL
 */
inline Matrix::Matrix() 
{
   myRows = 0;
   myColumns = 0;
   myMatrix = NULL;
}

/* constructor
 * Parameters: rows, columns, two unsigned values.
 * Precondition: rows > 0 && columns > 0.
 * Postcondition: myRows == rows && myColumns == columns &&
 *                 myMatrix points to a rows x columns array.
 */
inline Matrix::Matrix(unsigned rows, unsigned columns) 
{
   assert(rows > 0 && columns > 0);
   myRows = rows;
   myColumns = columns;
   myMatrix = NULL;
   allocate(rows, columns);
}

/* destructor
 * Postcondition: my memory has been reclaimed.
 */
inline Matrix::~Matrix() {
	deallocate();
}

/* access (read) a value
 * Parameters: row, col, two unsigned values.
 * Precondition: row >= 0 && col >= 0 &&
 *               row < myRows && col < myCols.
 * Postcondition: myMatrix[row][col] has been returned.
 */
inline Item Matrix::get(unsigned row, unsigned col) const {
	return myMatrix[row][col];
}

/* access (read) a value
 * Parameters: row, col, two unsigned values;
 *             value, an Item.
 * Precondition: row >= 0 && col >= 0 &&
 *               row < myRows && col < myCols.
 * Postcondition: myMatrix[row][col] == value.
 */
inline void Matrix::set(unsigned row, unsigned col, Item value) {
	myMatrix[row][col] = value;
}

/* Number of rows in a Matrix
 * Postcondition: myRows has been returned.
 */
inline unsigned Matrix::getRows() const
{
   return myRows;
}


/* Number of columns in a Matrix
 * Postcondition: myColumns has been returned.
 */
inline unsigned Matrix::getColumns() const
{
   return myColumns;
}



/* output operator
 * Parameters: out, an ostream;
 *             mat, a Matrix.
 * Precondition: out is an open ostream.
 * Postcondition: mat's values have been inserted into out.
 */
inline ostream& operator<<(ostream& out, const Matrix& mat) 
{
   mat.print(out);
   return out;
}

/* input operator
 * Parameters: in, an istream;
 *             mat, a Matrix.
 * Precondition: in is an open istream containing
 *                myRows x myColumns values.
 * Postcondition: myMatrix contains the input values.
 */
inline istream& operator>>(istream& in, Matrix& theMatrix) 
{
   theMatrix.read(in);
   return in;
}

#endif
