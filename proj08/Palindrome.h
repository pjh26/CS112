/* Palindrome.h header file for the Palindrome class
 * Palindrome class reads a file and creates a duplicate file where the lines
 * that are palindromes are indicated with *** attached to the end
 *
 *  Created on: Apr 13, 2018
 *      Author: Peter Haagsma
 */

#ifndef PALINDROME_H_
#define PALINDROME_H_
#include "ArrayQueue.h"
#include "Stack.h"
#include <fstream>

class Palindrome {
public:
	Palindrome();
	Palindrome(const string& fileNameIn, const string& fileNameOut);
	void palindromeDetector(const string& fileNameIn, const string& fileNameOut);
private:
	string myFileIn;
	string myFileOut;
};

bool isPalindrome(string& line);

#endif /* PALINDROME_H_ */
