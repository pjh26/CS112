/* Defines methods for the PalindromeTester class
 * PalindromeTester.cpp
 *
 *  Created on: Apr 16, 2018
 *      Author: Peter Haagsma
 */

#include "PalindromeTester.h"
#include <cassert>
void PalindromeTester::runTests() {
	cout << "Testing class PalindromeDetector..." << endl;
	testIsPalindrome();
	testPalindromeDetector();
	cout << "All tests passed!\n" << endl;
}

void PalindromeTester::testIsPalindrome() {
	cout << "- testing isPalindrome" << flush;
	// Test no extra chars
	string palindrome = "lionoil";
	assert( isPalindrome(palindrome) );
	cout << " 1 " << flush;
	palindrome = "lion oil";
	assert( isPalindrome(palindrome) );
	cout << " 2 " << flush;
	palindrome = "Lion Oil";
	assert( isPalindrome(palindrome) );
	cout << " 3 " << flush;
	palindrome = "L*i&o2No000Il@";
	assert( isPalindrome(palindrome) );
	cout << " 4 " << flush;
	palindrome = "Bob the tomato";
	assert( !isPalindrome(palindrome) );
	cout << " 5 " << flush;
	cout << "Passed!" << endl;
}

void PalindromeTester::testPalindromeDetector() {
	cout << "- testing palindromeDetector" << flush;
	Palindrome p("pTestIn.txt", "pTestOut.txt");
	ifstream fin("pTestIn.txt");
	ifstream fout("pTestOut.txt");
	string tempStrIn, tempStrOut;

	while (fin) {
		getline(fin, tempStrIn);
		getline(fout, tempStrOut);
		if (isPalindrome(tempStrIn)) {
			assert( tempStrOut == tempStrIn + " ***" );
		} else if (!isPalindrome(tempStrIn)) {
			assert( tempStrOut == tempStrIn + "" );
		} else {
			assert( false );
		}
	}

	fin.close();
	fout.close();
	cout << "Passed!" << endl;
}


