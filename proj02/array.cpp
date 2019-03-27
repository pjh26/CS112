/* array.cpp defines "C style" array operations
 * Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
 
#include "array.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

void initialize(double * a, int size) {
	int val = 0;
	for (int i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}
 
void print(double *a, int size) {
	for (int i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}		

/* Inputs: Double pointer for an array and an int size of array
 * Outputs: Average of the values in the array
 */
double average(double *a, int size) {
	// Gathers the sum of the array
	double sum = 0.0;
	for ( int i = 0; i < size; i++) {
		sum += a[i];
	}
	// Divides that sum by the number of terms and returns
	return sum/size;
}

/* Inputs: Double pointer for the first slot of an array and an int size of array
 * Outputs: Sum of array
 * Description: Takes the location of an array and iterates through it taking the sum
 */
double sum(double *a, int size) {
	double sum = 0.0;
	for( int i = 0; i < size; i++ ) {
		sum += *a;
		a++;
	}
	return sum;
}

/* Inputs: An open istream, a pointer and a size
 * Creates an array using the values from istream and places them at the location *a points to and creates
 * an array of size "size"
 */
void read(istream& in, double * a, int size) {
	double tempVal;
	string tempValStr;
	for( int i = 0; i < size; i++ ) {
		in >> tempValStr;
		tempVal = atoi( tempValStr.c_str() );
		a[i] = tempVal;
	}

}

/* Inputs: a string filename, a pointer for an array
 * Reads the file and first grabs an array size then creates an array at the location of a.
 * Reads values from the file and places them in the array
 */
void fill(const string& fileName, double* &a, int &numValues) {
	ifstream fin;
	fin.open( fileName.c_str() );
	string numValuesStr;
	fin >> numValuesStr;
	numValues = atoi( numValuesStr.c_str() );

	delete [] a;
	a = new double[numValues];

	string tempVal;
	for( int i = 0; i < numValues; i++) {
		fin >> tempVal;
		a[i] = atoi( tempVal.c_str() );
	}
	fin.close();
}

/* Inputs: A pointer for an array and the old size of the array as well as the new size
 * Takes an array and adds zero on the end if newSize is bigger and truncates is newSize is smaller
 */
void resize(double* &a, int oldSize, int newSize) {
	double* temp = new double[oldSize];
	for(int i = 0; i < oldSize; ++i) {
		temp[i] = a[i];
	}

	delete [] a;
	a = new double[newSize];

	for(int i = 0; i < newSize; ++i) {
		if( i < oldSize ) {
			a[i] = temp[i];
		} else {
			a[i] = 0;
		}
	}
	delete [] temp;
}


/* Inputs: 3 pointers and array sizes
 * Creates a new array at location array 3 with the values of a2 tagged on to the end
 * of a1 at that location
 */
void concat(double * a1, int size1, double * a2, int size2, double * &a3, int &size3) {
	size3 = size1 + size2;
	delete [] a3;
	a3 = new double[size3];
	for( int i = 0; i < size1; i++ ) {
		a3[i] = a1[i];
	}
	for( int i = size1; i < size3; i++ ) {
		a3[i] = a2[i - size1];
	}
}

