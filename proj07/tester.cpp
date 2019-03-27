/* tester.cpp is a "driver" to run the tests in the StackTester class.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Peter Haagsma
 * 		   Date: March 27, 2018
 */
 
#include "StackTester.h"
#include "ReversePoemTester.h"
int main() {
	StackTester st;
	st.runTests();
	ReversePoemTester rpt;
	rpt.runTests();

	while (true) {
		cout << "\nEnter the name of the poem file: "
			 << "\nEnter 1 to quit";
		string poemFile;
		cin >> poemFile;

		if (poemFile == "1") { break; }
		ReversePoem reversePoem(poemFile);
		cout << reversePoem.getTitle() << "\n"
			 << reversePoem.getAuthor() << "\n"
			 << "\n*** Top-To-Bottom ***\n\n"
			 << reversePoem.getBody()
			 << "\n\n*** Bottom-To-Top ***\n\n"
			 << reversePoem.getBodyReversed()
			 << endl;
	}
}

