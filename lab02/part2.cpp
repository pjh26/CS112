/* part2.cpp demonstrates a simple dynamically allocated "C-style" array.
 * Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "array.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
	const unsigned SIZE = 5;
	double * a1 = new double[SIZE];
	assert( a1 != NULL );
	initialize(a1, SIZE);
	cout << "\na1: ";
	print(a1, SIZE);
	cout << "\na1 average: " << average(a1, SIZE) << endl;
	delete [] a1;

	const unsigned SIZE2 = 4;
	double a2[SIZE2];
	initialize(a2, SIZE2);
	cout << "\na2: ";
	print(a2, SIZE2);
	cout << "\na2 average: " << average(a2, SIZE2) << endl;

	const unsigned SIZE3 = 6;
	double a3[SIZE3];
	double value = 100.0;
	for (unsigned i = 0; i < SIZE3; i++) {
		a3[i] = value;
		value -= 1.0;
	}
	cout << "\na3: ";
	print(a3, SIZE3);
	cout << "\na3 average: " << average(a3, SIZE3) << endl;

}

