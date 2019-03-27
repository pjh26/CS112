/* Defines methods for ReversePoem class
 * ReversePoem.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: Peter Haagsma
 */

#include "ReversePoem.h"

/* Constructor for reversepoem object
 * @params: string file name with poem
 * Postcondition: file containing poem has been read
 * 				  Line 1 = myTitle
 * 				  Line 2 = myAuthor
 * 				  Line 3-end = myBody
 * 				  While creating myBody the lines are read into a stack
 * 				  Then the stack is read from top to bottom into myBodyReversed
 * 				  This reverses the poem and deletes the temporary stack
 */
ReversePoem::ReversePoem(const string& poemFile) {
	ifstream fin(poemFile.c_str());
	assert( fin.is_open() );
	getline(fin, myTitle);
	getline(fin, myAuthor);
	string newLine;
	Stack<string> tempStack(1);
	//Read file into Body and stack
	getline(fin, newLine); // Gets rid of line between Author and body
	while (getline(fin, newLine)) {
		myBody = myBody + newLine + "\r";
		try {
			tempStack.push(newLine);
		} catch (const StackException& se) {
			tempStack.setCapacity(tempStack.getCapacity()*2);
			tempStack.push(newLine);
		}
	}
	fin.close();
	assert( !fin.is_open() );
	//Read stack from top down into myBodyReversed
	while (true) {
		myBodyReversed = myBodyReversed + tempStack.pop() + "\r";
		if (tempStack.isEmpty()) {
			break;
		}
	}
}
