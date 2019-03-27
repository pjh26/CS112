/* hexList.cpp generates an ascending list of hexadecimal addresses
 *  Joel Adams, Fall 2008, for CS 112 at Calvin College.
 */

#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

typedef long word;

char getChoice();
void getLimits(word& start, word& stop);
unsigned hexDigit(char ch);
word convertFromHex(const string& str);
void displayList(word start, word stop, char choice);
void runTests();

int main() {	
	// runTests();
	cout << "This program generates a list of consecutive hex addresses.\n\n";
	char choice = getChoice();
	word start, stop;
	getLimits(start, stop);
	displayList(start, stop, choice);
}

char getChoice() {
	char choice; string choiceStr;
	do {
		cout << "Do you want:\n"
			<< "\ta - ascending, or\n"
			<< "\td - descending addresses\n"
			<< "? ";
		getline(cin, choiceStr);
		choice = choiceStr[0];
	} while (choice != 'a' && choice != 'd');
	return choice;
}

void getLimits(word& start, word& stop) {
    cout << " Enter the first hex address: ";
	string startStr, stopStr;
	getline(cin, startStr);
	cout << " Enter the last hex address: ";
	getline(cin, stopStr);
   	start = convertFromHex(startStr);
	stop = convertFromHex(stopStr);
}

word convertFromHex(const string& str) {
	word result = 0;
	unsigned exp = 0;
	unsigned digit;
	for (unsigned i = str.length()-1; i > 1; i--) {
		digit = hexDigit(str[i]);
		result += (digit * (long) pow(16.0, (double) exp));
		exp++;
	}

	return result;
}

unsigned hexDigit(char ch) {
	switch (ch) {
		case '0': case '1': case '2':
		case '3': case '4': case '5':
		case '6': case '7': case '8':
		case '9':
			return (ch - '0');
		case 'a': case 'b': case 'c':
		case 'd': case 'e': case 'f':
			return (ch - 'a' + 10);
		default:
			cerr << "Invalid hex char";
			return 0;
	}
}

void displayList(word start, word stop, char choice){
	cout << "\n";
	if (choice == 'a') {
		for (long i = start; i <= stop; i++) {
			cout << hex << i << endl;
		}
	} else {
		for (long i = start; i >= stop; i--) {
			cout << hex << i << endl;
		}
	}
	cout << "\nList complete.\n";

}

void runTests() {
	assert( convertFromHex("0xa") == 10 );
	assert( convertFromHex("0x0a") == 10 );
	assert( convertFromHex("0xf") == 15 );
	assert( convertFromHex("0x0f") == 15 );
	assert( convertFromHex("0x10") == 16 );
	assert( convertFromHex("0x1f") == 31 );
	assert( convertFromHex("0x20") == 32 );
	assert( convertFromHex("0x21") == 33 );
	assert( convertFromHex("0x2f") == 47 );
	assert( convertFromHex("0x02f") == 47 );
	assert( convertFromHex("0x12f") == 16*16 + 32 + 15 );
}

