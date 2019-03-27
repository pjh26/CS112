/* tester.cpp drives the testing of our Vec template and Matrix class.
 * Student: Peter Haagsma & Samuel Poortenga
 * Date:	March 05, 2018
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "VecTester.h"
#include "MatrixTester.h"
#include "Application.h"

int main() {
//	VecTester vt;
//	vt.runTests();
//	cout << "\n";
	MatrixTester mt;
	mt.runTests();
	Application app;
	app.runApp();
}
