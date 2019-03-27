/* ReversePoemTester.cpp
 * contains the methods for the ReversePoemTester class
 *
 *  Created on: Mar 28, 2018
 *      Author: Peter
 */

#include "ReversePoemTester.h"

void ReversePoemTester::runTests() {
	cout << "Testing ReversePoem class" << endl;
	testConstructors();
	testGetters();
	cout << "All tests passed!" << endl;
}

void ReversePoemTester::testConstructors() {
	cout << "- Testing constructor..." << flush;
	ReversePoem reverseTest("poems/testPoem.txt");
	assert( reverseTest.myAuthor == "Leo J. Smada\r" );
	assert( reverseTest.myTitle == "Cats\r" );
	assert( reverseTest.myBody == "I love it when cats rub against me.\r\rI could never say\r\rI hate those purring felines.\r\r");
	assert( reverseTest.myBodyReversed == "I hate those purring felines.\r\rI could never say\r\rI love it when cats rub against me.\r\r");
	cout << "Passed!" << endl;
}

void ReversePoemTester::testGetters() {
	cout << "- Testing getters..." << flush;

	ReversePoem reverseTest("poems/testPoem.txt");

	assert( reverseTest.getAuthor() == "Leo J. Smada\r" );
	assert( reverseTest.getTitle() == "Cats\r" );
	assert( reverseTest.getBody() == "I love it when cats rub against me.\r\rI could never say\r\rI hate those purring felines.\r\r");
	assert( reverseTest.getBodyReversed() == "I hate those purring felines.\r\rI could never say\r\rI love it when cats rub against me.\r\r");

	cout << "Passed" << endl;
}
