/* ArrayTester.cpp defines the methods to test C-style array operations.
 * Student:
 * Date:
 * By: Joel Adams, for CS 112 at Calvin College.
 */
 
 #include "ArrayTester.h"
 #include <fstream>
 using namespace std;

ArrayTester::ArrayTester() {
	a1 = a2 = a3 = NULL;
}

ArrayTester::~ArrayTester() {
        cleanup();
}

void ArrayTester::cleanup() {
	delete [] a1; a1 = NULL;
	delete [] a2; a2 = NULL;
	delete [] a3; a3 = NULL;
}

void ArrayTester::runTests() {
	testInitialize();
	testPrint();
	testAverage();
	testSum();
	testResize();
	testConcat();
	testFill();
	testRead();
	cout << "All tests passed!" << endl;
}

void ArrayTester::setup() {
	a1 = new double[3];
	for (int i = 0; i < 3; i++) {
		a1[i] = i+1;
	}
	a2 = new double[4];
	for (int i = 0; i < 4; i++) {
		a2[i] = i+2;
	}
	a3 = new double[5];
	for (int i = 0; i < 5; i++) {
		a3[i] = i+3;
	}
}

void ArrayTester::testInitialize()  {
	cout << "Testing initialize()... " << flush;
	setup();
	initialize(a1, 3);
	for (int i = 0; i < 3; i++) {
		assert( a1[i] == i+1 );
	}
	initialize(a2, 4);
	for (int i = 0; i < 4; i++) {
		assert( a2[i] == i+1 );
	}
	initialize(a3, 5);
	for (int i = 0; i < 5; i++) {
		assert( a3[i] == i+1 );
	}
        cleanup();
	cout << "Passed!" << endl;
}

void ArrayTester::testPrint() {
	cout << "Testing print()... " << flush;
	setup();
	cout << "\nExpecting 3 values: 1, 2, 3..." << endl;
	print(a1, 3);
	cout << "\nExpecting 4 values: 2, 3, 4, 5..." << endl;
	print(a2, 4);
	cout << "\nExpecting 5 values: 3, 4, 5, 6, 7..." << endl;
	print(a3, 5);
        cleanup();
	cout << "\nPassed!" << endl;
}

void ArrayTester::testAverage() {
	cout << "Testing average()... " << flush;
	setup();
	assert( average(a1, 3) == 2  );
	assert( average(a2, 4) == 3.5 );
	assert( average(a3, 5) == 5 );
        cleanup();
	cout << "Passed!" << endl;
}

void ArrayTester::testSum() {
	cout << "Testing sum()... " << flush;
	setup();
	assert( sum(a1, 3) == 6 );
	assert( sum(a2, 4) == 14 );
	assert( sum(a3, 5) == 25 );
        cleanup();
	cout << "Passed!" << endl;
}

void ArrayTester::testResize() {
	cout << "Testing resize()... " << flush;
	setup();
	double * temp1 = a1;
	resize(a1, 3, 7);
	assert( a1 != temp1 );
	for (int i = 0; i < 3; i++) {
		assert( a1[i] == i+1 );
	}
	for (int i = 3; i < 7; i++) {
		assert( a1[i] == 0 );
	}
	
	double *temp3 = a3;
	resize(a3, 5, 3);
	assert( temp3 != a3 );
	for (int i = 0; i < 3; i++) {
		assert( a3[i] == i+3 );
	}
        cleanup();
	cout << "Passed!  But double-check that you deleted the old array..." << endl;
}

void ArrayTester::testConcat() {
	cout << "Testing concat()... " << flush;
	setup();
	int size1 = 3, size2 = 4, size3 = 5;
	double *temp1 = a1;
	double *temp2 = a2;
	double *temp3 = a3;
	concat(a1, size1, a2, size2, a3, size3);
	assert( temp1 == a1 );
	assert( temp2 == a2 );
        /* the next assertion assumes that the new array's base
         *  address is different from the old array's base address,
         *  which may not be true. If concat() seems to be right,
         *  and passes all assertions except this one, you may
         *  comment out this assertion.
         */
//	assert( temp3 != a3 );
	assert( size1 == 3 );
	assert( size2 == 4 );
	assert( size3 == 7 );
	for (int i = 0; i < 3; i++) {
		assert( a3[i] == i+1 );
	}
	int j = 2;
	for (int i = 3; i < 7; i++) {
		assert( a3[i] == j );
		j++;
	}
        cleanup();
	cout << "Passed!  But double-check that you deleted the old array..." << endl;
}


void ArrayTester::testFill() {
	cout << "Testing fill()... " << flush;	
	setup();
	int size1 = 3;
	double *temp1 = a1;
	fill("arrayData.txt", a1, size1);
	assert( a1 != temp1 );
	assert( size1 == 6);
	for (int i = 0; i < size1; i++) {
		assert( a1[i] == i+10 );   // values should be 10, 11, 12, 13, 14, 15
	}
        cleanup();
	cout << "Passed!  But double-check that you deleted the old array..." << endl;
}

void ArrayTester::testRead() {
	cout << "Testing read()... " << flush;
	double* a4 = new double[6];
	ifstream fin("arrayData.txt");
	assert( fin.is_open() );
	string firstLine, secondLine;
	getline(fin, firstLine);         // skip past the '6' that's there for fill()...
	getline(fin, secondLine);        // skip past the '10' 
	read(fin, a4, 5);                // read 5 values instead of 6 
	for (int i = 0; i < 5; i++) {    // check what we got:
		assert( a4[i] == i+11 );	 //  values should be 11, 12, 13, 14, 15,
	}                                //   so test-values differ from fill()
        delete [] a4;
	cout << "Passed!" << endl;
}

