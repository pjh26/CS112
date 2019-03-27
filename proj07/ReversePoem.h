/* Declares ReversePoem class used to read poems and reverse them
 *
 * ReversePoem.h
 *
 *  Created on: Mar 28, 2018
 *      Author: Peter
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_
#include <string>
#include <fstream>
#include <cassert>
#include "Stack.h"
#include "StackException.h"

using namespace std;
class ReversePoem {
public:
	ReversePoem(const string& poemFile);
	const string& getAuthor() const { return myAuthor; }
	const string& getTitle() const { return myTitle; }
	const string& getBody() const { return myBody; }
	const string& getBodyReversed() const { return myBodyReversed; }

private:
	friend class ReversePoemTester;
	string myAuthor;
	string myTitle;
	string myBody;
	string myBodyReversed;
};

#endif /* REVERSEPOEM_H_ */
