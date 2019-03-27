/* Palindrome.cpp defines the methods for the palndrome class
 *
 *  Created on: Apr 13, 2018
 *      Author: Peter Haagsma
 */

#include "Palindrome.h"
#include <cctype>

/* Default constructor for the Palindrome class
 * Prompts user to input a text file to test for palindromes and an output file to see
 * whether there are any palindromes
 */
Palindrome::Palindrome() {
	cout << "Welcome to the Palindrome detector." << endl;
	while (true) {
		cout << "Enter 1 to pick a file\r"
			 << "Enter 2 to quit." << endl;
		string userInput;
		cin >> userInput;
		if (userInput == "1") {
			cout << "Enter your input file name." << endl;
			cin >> myFileIn;
			cout << "Enter your output file name." << endl;
			cin >> myFileOut;
			palindromeDetector(myFileIn, myFileOut);
		} else if (userInput == "2") {
			break;
		} else {
			cout << "Please enter valid input." << endl;
		}
	}
}

/* Constructor for palindrome class
 * @params: string file name containing palindromes, string file name where output will go
 * Postcondition: palindromeDetector run on the parameters
 */
Palindrome::Palindrome(const string& fileNameIn, const string& fileNameOut) {
	myFileIn = fileNameIn;
	myFileOut = fileNameOut;
	palindromeDetector(myFileIn, myFileOut);
}

/* Reads through a if a line is a palindrome it addes " ***"
 * @params: string fileNameIn and fileNameOut
 * Postcondition: Output file created
 * 				  lines from input copied to output and lines that are palindromes
 * 				  have " ***" at the end of the line
 */
void Palindrome::palindromeDetector(const string& fileNameIn, const string& fileNameOut) {
	ifstream fin(fileNameIn.c_str());
	ofstream fout(fileNameOut.c_str());
	string tempStr;
	while (fin) {
		getline(fin, tempStr);

		if (isPalindrome(tempStr)) {
			fout << tempStr + " ***" << endl;
		} else {
			fout << tempStr << endl;
		}
	}
	fin.close();
	fout.close();
}

/* Takes in a string and returns true if a palindrome and returns false otherwise
 * @params: string line from a file
 * returns: true if the line is a palindrome and false otherwise ( also checks
 * 			for the case where the line is one character long )
 */
bool isPalindrome(string& line) {
	const char* pLine = line.c_str();
	Stack<char> myStack(1);
	ArrayQueue<char> myQueue(1);
	if (strlen(pLine) <= 1) {
		return false;
	}
	for (unsigned i = 0; i < strlen(pLine); i++) {
		if ( isalpha(pLine[i]) ) {
			try {
				myStack.push( tolower(pLine[i]) );
			} catch (StackException&) {
				myStack.setCapacity(myStack.getCapacity()*2);
				myStack.push( tolower(pLine[i]) );
			}
			try {
				myQueue.append( tolower(pLine[i]) );
			} catch (FullQueueException&) {
				myQueue.setCapacity(myQueue.getCapacity()*2);
				myQueue.append( tolower(pLine[i]) );
			}
		}
	}
	for ( unsigned i = 0; i < myStack.getSize(); i++ ) {
		if ( myStack.pop() != myQueue.remove() ) {
			return false;
		}
	}
	return true;
}

