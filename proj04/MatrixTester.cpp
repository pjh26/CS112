/* MatrixTester.cpp defines test-methods for class Matrix.
 * Joel Adams, for CS 112 at Calvin College.
 */
 
#include "MatrixTester.h"
#include <cassert>
#include <iostream>        // cout, cerr, ...
#include <cstdlib>         // exit()
#include <stdexcept>       // range_error, ...
using namespace std;

void MatrixTester::runTests() {
	cout << "Running Matrix tests..." << endl;
	testDefaultConstructor();
	testExplicitConstructor();
	testCopyConstructor();
	testAssignment();
	testEquality();
	testSubscripts();
	testInequality();
	testTranspose();
	testAddition();
	testSubtraction();
//	testMultiply();
	testReadFromStream();
	testWriteToStream();
	testReadFromFile();
	testWriteToFile();
	cout << "All tests passed!" << endl;
}


void MatrixTester::testDefaultConstructor() {
	cout << "Testing default constructor..." << flush;
	Matrix<double> m1;
	assert( m1.getRows() == 0 );
	assert( m1.getColumns() == 0 );
	cout << " 0 " << flush;

	Matrix<double> m2;
	assert( m2.getRows() == 0 );
	assert( m2.getColumns() == 0 );
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}

void MatrixTester::testExplicitConstructor() {
	cout << "Testing explicit constructor..." << flush;
	Matrix<double> m1(2, 3);
	assert( m1.getRows() == 2 );
	assert( m1.getColumns() == 3 );
	for (unsigned i = 0; i < m1.getRows(); i++) {
		for (unsigned j = 0; j < m1.getColumns(); j++) {
			assert( m1.myVec[i][j] == 0 );
		}
	}
	cout << " 1 " << flush;

	Matrix<double> m2(3, 1);
	assert( m2.getRows() == 3 );
	assert( m2.getColumns() == 1 );
	for (unsigned i = 0; i < m2.getRows(); i++) {
		for (unsigned j = 0; j < m2.getColumns(); j++) {
			assert( m2.myVec[i][j] == 0 );
		}
	}
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void MatrixTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty matrix
	Matrix<double> m1;
	Matrix<double> m2(m1);
	assert( m2.getRows() == 0 );
	assert( m2.getColumns() == 0 );
	assert( m2.myVec.getSize() == 0 );
	cout << " 1 " << flush;

	// copy non-empty matrix
	Matrix<double> m3(2, 3);
	for (unsigned i = 0; i < m3.getRows(); i++) {
		for (unsigned j = 0; j < m3.getColumns(); j++) {
			m3.myVec[i][j] = i+j;
		}
	}
	Matrix<double> m4(m3);
	assert( m4.getRows() == m3.getRows() );
	assert( m4.getColumns() == m3.getColumns() );
	assert( m4.myVec.getSize() == m3.myVec.getSize() );
	for (unsigned i = 0; i < m3.getRows(); i++) {
		for (unsigned j = 0; j < m3.getColumns(); j++) {
			assert( m4.myVec[i][j] == i+j );
		}
	}
	cout << " 2 " << flush;

	cout << " Passed!" << endl;
}

void MatrixTester::testAssignment() {
	cout << "Testing =... " << flush;
	// empty to empty
	Matrix<double> m0;
	Matrix<double> m1;
	m0 = m1;
	assert( m0.getRows() == 0 );
	assert( m0.getColumns() == 0 );
	assert( m0.myVec.getSize() == 0 );
	cout << " 0 " << flush;

	// nonempty to empty
	Matrix<double> m2(2,3);
	m0 = m2;
	assert( m0.getRows() == 2 );
	assert( m0.getColumns() == 3 );
	assert( m0.myVec == m2.myVec );
	cout << " 1 " << flush;

	// empty to nonempty
	m2 = m1;
	assert( m2.getRows() == 0 );
	assert( m2.getColumns() == 0 );
	assert( m2.myVec == m1.myVec );
	cout << " 2 " << flush;

	// non-empty to non-empty
	Matrix<double> m3(2, 3);
	for (unsigned i = 0; i < m3.getRows(); i++) {
		for (unsigned j = 0; j < m3.getColumns(); j++) {
			m3[i][j] = i+j;
		}
	}
	Matrix<double> m4(5, 4);
	m4 = m3;
	assert( m4.getRows() == 2 );
	assert( m4.getColumns() == 3 );
	assert( m4.myVec == m3.myVec );
	cout << " 3 " << flush;

	// chaining
	Matrix<double> m5;
	m5 = m0 = m4;
	assert( m0.getRows() == 2 );
	assert( m0.getColumns() == 3 );
	assert( m0.myVec == m4.myVec );
	assert( m5.getRows() == 2 );
	assert( m5.getColumns() == 3 );
	assert( m5.myVec == m0.myVec );
	cout << " 4 " << flush;

	// self-assignment
//	m5 = m5;
	assert( m5.getRows() == 2 );
	assert( m5.getColumns() == 3 );
	for (unsigned i = 0; i < m5.getRows(); i++) {
		for (unsigned j = 0; j < m5.getColumns(); j++) {
			assert( m5[i][j] == i+j );
		}
	}
	cout << " 5 " << flush;

	cout << "Passed!" << endl;
}

void MatrixTester::testEquality() {
	cout << "Testing ==... " << flush;
	// empty
	Matrix<double> m1;
	Matrix<double> m2;
	assert( m1 == m2 );
	cout << " 1 " << flush;

	// same sized
	Matrix<double> m3(2, 3);
	Matrix<double> m4a(2, 3);
	Matrix<double> m4b(2, 3);
	Matrix<double> m5(2, 3);
	for (unsigned i = 0; i < m3.getRows(); i++) {
		for (unsigned j = 0; j < m3.getColumns(); j++) {
			m3[i][j] = i+j;
			m4a[i][j] = i+j;
			m4b[i][j] = i+j;
			m5[i][j] = i*j;
		}
	}
	assert( m3 == m4a );
	assert( !(m1 == m3) );
	assert( !(m3 == m5) );
	m4b[1][1] = 0;
	assert( !(m3 == m4b) );
	cout << " 2 " << flush;

	// different row sizes
	Matrix<double> m6(3,3);
	Matrix<double> m7(2,3);
	assert( !(m6 == m7) );
	cout << " 3 " << flush;

	// same row sizes, different column sizes
	Matrix<double> m8(2,4);
	assert( !(m8 == m7 ) );
	cout << " 4 " << flush;

	cout << "Passed!" << endl;
}

void MatrixTester::testReadSubscript(const Matrix<double>& mat) {
	for (unsigned i = 0; i < mat.getRows(); i++) {
		for (unsigned j = 0; j < mat.getColumns(); j++) {
			assert( i*j == mat[i][j] );
		}
	}
}

void MatrixTester::testSubscripts() {
	cout << "Testing subscripts... " << flush;
	Matrix<double> m(4, 3);
	// test write-subscript
	for (unsigned i = 0; i < m.getRows(); i++) {
		for (unsigned j = 0; j < m.getColumns(); j++) {
			m[i][j] = i*j;
		}
	}
	cout << " 1 " << flush;

	// test read-subscript -- see above
	testReadSubscript(m);
	cout << " 2 " << flush;

	// exceptions
	// empty Matrix
	Matrix<double> m0;

	// read subscript
	try {
		m0[0][0];
		cerr << "successfully read from empty Matrix";
		exit(1);
	} catch (range_error&) {
		cout << " 3 " << flush;
 	}

	// write subscript
	try {
		m0[0][0] = 0;
		cerr << "successfully wrote to empty Matrix";
		exit(1);
	} catch (range_error&) {
		cout << " 4 " << flush;
 	}

	// nonempty Matrix
	Matrix<double> m2(2,3);

	// beyond last row
	try {
		m2[2][0] = 0;
		cerr << "successfully wrote past last Matrix row";
		exit(1);
	} catch (range_error&) {
		cout << " 5 " << flush;
 	}

	// beyond last column
	try {
		m2[0][3] = 0;
		cerr << "successfully wrote past last Matrix column";
		exit(1);
	} catch (range_error&) {
		cout << " 6 " << flush;
 	}

	cout << "Passed!" << endl;
}

void MatrixTester::testInequality() {
	cout << "Testing !=... " << flush;

	// empty
	Matrix<double> m1;
	Matrix<double> m2;
	assert( !(m1 != m2) );
	cout << " 0 " << flush;

	// nonempty, same size
	Matrix<double> m3(2, 3);
	Matrix<double> m4(2, 3);
	Matrix<double> m5(2, 3);
	for (unsigned i = 0; i < m3.getRows(); i++) {
		for (unsigned j = 0; j < m3.getColumns(); j++) {
			m3[i][j] = i+j;
			m4[i][j] = i+j;
			m5[i][j] = i*j;
		}
	}
	assert( !(m3 != m4) );
	assert( m1 != m3 );
	assert( m3 != m5 );
	cout << " 1 " << flush;

	// nonempty, different row sizes
	Matrix<double> m6(3,3);
	for (unsigned i = 0; i < m6.getRows(); i++) {
		for (unsigned j = 0; j < m6.getColumns(); j++) {
			m6[i][j] = i+j;
		}
	}
	assert( m3 != m6 );
	cout << " 2 " << flush;

	// nonempty, different column sizes
	Matrix<double> m7(2, 4);
	for (unsigned i = 0; i < m7.getRows(); i++) {
		for (unsigned j = 0; j < m7.getColumns(); j++) {
			m7[i][j] = i+j;
		}
	}
	assert( m3 != m7 );
	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}

void MatrixTester::testTranspose() {
	cout << "Testing getTranspose()... " << flush;
	// empty
	Matrix<double> m0a, m0b(2,3);
	m0b = m0a.getTranspose();
	assert( m0b.getRows() == 0 );
	assert( m0b.getColumns() == 0 );
	assert( m0b.myVec.getSize() == 0 );
	cout << " 0 " << flush;

	// nonempty
	Matrix<double> m1(4, 3);
	for (unsigned i = 0; i < m1.getRows(); i++) {
		for (unsigned j = 0; j < m1.getColumns(); j++) {
			m1[i][j] = i*j;
		}
	}
	Matrix<double> m2 = m1.getTranspose();
	assert( m2.getRows() == m1.getColumns() );
	assert( m2.getColumns() == m1.getRows() );
	for (unsigned i = 0; i < m1.getRows(); i++) {
		for (unsigned j = 0; j < m1.getColumns(); j++) {
			assert( m2[j][i] == m1[i][j] );
		}
	}
	cout << " 1a " << flush;
	// check that m1 is unchanged
	for (unsigned i = 0; i < m1.getRows(); i++) {
		for (unsigned j = 0; j < m1.getColumns(); j++) {
			assert( m1[i][j] == i*j );
		}
	}
	cout << " 1b " << flush;

	cout << "Passed!" << endl;
}

void MatrixTester::testAddition() {
	cout << "Testing +... " << flush;
	// empty
	Matrix<double> m0a, m0b, m0c(3,2);
	m0c = m0a + m0b;
	assert( m0c.getRows() == 0 );
	assert( m0c.getColumns() == 0 );
	assert( m0c.myVec.getSize() == 0 );
	cout << " 0 " << flush;

	// nonempty, same size
	Matrix<double> m1(3, 4);
	Matrix<double> m2(3, 4);
	for (unsigned i = 0; i < m1.getRows(); i++) {
		for (unsigned j = 0; j < m1.getColumns(); j++) {
			m1[i][j] = i*j;
			m2[i][j] = i+j;
		}
	}

	Matrix<double> m3 = m1 + m2;

	for (unsigned i = 0; i < m1.getRows(); i++) {
		for (unsigned j = 0; j < m1.getColumns(); j++) {
			assert( m3[i][j] == i*j + i+j );
		}
	}
	cout << " 1a " << flush;

	// check that left operand did not change
	for (unsigned i = 0; i < m1.getRows(); i++) {
		for (unsigned j = 0; j < m1.getColumns(); j++) {
			assert( m1[i][j] == i*j );
		}
	}
	cout << " 1b " << flush;

	// nonempty, different sized rows
	Matrix<double> m4(4,4);
	try {
		m3 = m2 + m4;
		cerr << "operator+ worked with different row sizes";
		exit(1);
	} catch (invalid_argument&) {
		cout << " 2 " << flush;
	}

	// nonempty, different sized columns
	Matrix<double> m5(3,3);
	try {
		m3 = m2 + m5;
		cerr << "operator+ worked with different column	sizes";
		exit(1);
	} catch (invalid_argument&) {
		cout << " 3 " << flush;
	}

	cout << "Passed!" << endl;
}

void MatrixTester::testSubtraction() {
	cout << "Testing -... " << flush;
	// empty
	Matrix<double> m0a, m0b, m0c(3,2);
	m0c = m0a - m0b;
	assert( m0c.getRows() == 0 );
	assert( m0c.getColumns() == 0 );
	assert( m0c.myVec.getSize() == 0 );
	cout << " 0 " << flush;

	//non-empty, valid
	Matrix<double> m1(3, 4);
	Matrix<double> m2(3, 4);
	for (unsigned i = 0; i < m1.getRows(); i++) {
		for (unsigned j = 0; j < m1.getColumns(); j++) {
			m1[i][j] = i*j;
			m2[i][j] = i+j;
		}
	}

	Matrix<double> m3 = m1 - m2;
	for (unsigned i = 0; i < m1.getRows(); i++) {
		for (unsigned j = 0; j < m1.getColumns(); j++) {
			assert( m3[i][j] == m1[i][j] - m2[i][j] );
		}
	}
	cout << " 1a " << flush;

	// check that left operand did not change
	for (unsigned i = 0; i < m1.getRows(); i++) {
		for (unsigned j = 0; j < m1.getColumns(); j++) {
			assert( m1[i][j] == i*j );
		}
	}
	cout << " 1b " << flush;

	// nonempty, different sized rows
	Matrix<double> m4(4,4);
	try {
		m3 = m2 - m4;
		cerr << "operator- worked with different row sizes";
		exit(1);
	} catch (invalid_argument&) {
		cout << " 2 " << flush;
	}

	// nonempty, different sized columns
	Matrix<double> m5(3,3);
	try {
		m3 = m2 - m5;
		cerr << "operator- worked with different column	sizes";
		exit(1);
	} catch (invalid_argument&) {
		cout << " 3 " << flush;
	}

	cout << "Passed!" << endl;
}

//void MatrixTester::testMultiply() {
//	cout << "Testing *..." << flush;
//	// empty
//	Matrix m0a, m0b, m0c(3,2);
//	m0c = m0a * m0b;
//	assert( m0c.getRows() == 0 );
//	assert( m0c.getColumns() == 0 );
//	assert( m0c.myVec.getSize() == 0 );
//	cout << " 0 " << flush;
//
//	Matrix m1(2, 3);
//	Matrix m2(3, 2);
//	for (unsigned i = 0; i < m1.getRows(); i++) {
//		for (unsigned j = 0; j < m1.getColumns(); j++) {
//			m1[i][j] = i+j+1;
//			m2[j][i] = i+j+1;
//		}
//	}
//	
//	Matrix m3 = m1 * m2;
//	assert( m3.getRows() == 2);
//	assert( m3.getColumns() == 2 );
//	assert( m3[0][0] == 14 );
//	assert( m3[0][1] == 20 );
//	assert( m3[1][0] == 20 );
//	assert( m3[1][1] == 29 );
//	cout << " 1a " << flush;
//	
//	// check that left operand did not change
//	for (unsigned i = 0; i < m1.getRows(); i++) {
//		for (unsigned j = 0; j < m1.getColumns(); j++) {
//			assert( m1[i][j] == i+j+1 );
//		}
//	}
//	cout << " 1b " << flush;
//
//	// nonempty, m1.columns != m2.rows
//	Matrix m4(3,3);
//	try {
//		m3 = m2 * m4;
//		cerr << "operator* worked with bad row/column sizes";
//		exit(1);
//	} catch (invalid_argument&) {
//		cout << " 2 " << flush;
//	}
//
//	cout << "Passed!" << endl;
//}

void MatrixTester::testReadFromStream() {
	cout << "Testing readFrom(istream)... " << flush;
	ifstream fin("MatrixTest1.txt");
	assert( fin.is_open() );
	unsigned rows, columns;
	fin >> rows >> columns;
	Matrix<double> m(rows, columns);
	m.readFrom(fin);
	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < columns; j++) {
			assert( m[i][j] == i*m.getColumns()+j+1 );
		}
	}

	cout << "Passed!" << endl;
}

void MatrixTester::testReadFromFile() {
	cout << "Testing readFrom(string)... " << flush;
	Matrix<double> m;
	m.readFrom("MatrixTest1.txt");
	assert( m.getRows() == 3 );
	assert( m.getColumns() == 4 );
	for (unsigned i = 0; i < m.getRows(); i++) {
		for (unsigned j = 0; j < m.getColumns(); j++) {
			assert( m[i][j] == i*m.getColumns()+j+1 );
		}
	}

	cout << "Passed!" << endl;
}

void MatrixTester::testWriteToStream() {
	cout << "Testing writeTo(ostream)... " << flush;
	Matrix<double> m;
	// read a Matrix whose values we know
	m.readFrom("MatrixTest1.txt");
	ofstream fout("MatrixTest1Copy.txt");
	assert( fout.is_open() );
	// now write it to a file via a stream
	fout << m.getRows() << " " << m.getColumns() << "\n";
	m.writeTo(fout);
	fout.close();
	// now, read what we just wrote into a different Matrix
	Matrix<double> m1;
	m1.readFrom("MatrixTest1Copy.txt");
	// and test it
	assert( m1.getRows() == 3 );
	assert( m1.getColumns() == 4 );
	for (unsigned i = 0; i < m.getRows(); i++) {
		for (unsigned j = 0; j < m.getColumns(); j++) {
			assert( m1[i][j] == i*m.getColumns()+j+1 );
		}
	}

	cout << "Passed!" << endl;
}

void MatrixTester::testWriteToFile() {
	cout << "Testing writeTo(string)... " << flush;
	Matrix<double> m;
	// read in a Matrix whose values we know
	m.readFrom("MatrixTest1.txt");
	// write it to a file
	m.writeTo("MatrixTest1Copy2.txt");
	// now, read what we just wrote into a different Matrix
	Matrix<double> m1;
	m1.readFrom("MatrixTest1Copy2.txt");
	// test it
	assert( m1.getRows() == 3 );
	assert( m1.getColumns() == 4 );
	for (unsigned i = 0; i < m.getRows(); i++) {
		for (unsigned j = 0; j < m.getColumns(); j++) {
			assert( m1[i][j] == i*m.getColumns()+j+1 );
		}
	}
	cout << "Passed!" << endl;
}

