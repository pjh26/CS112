/* CongaLine.cpp defines the methods for class CongaLine.
 *
 * @author: Joel Adams, for CS 112 at Calvin College.
 *
 * Based on an exercise by Marc LeBlanc from Wheaton College (MS).
 */

#include "CongaLine.h"

/* The CongaLine constructor
 * @param: person1, a string
 * @param: person2, a string
 * Postcondition: myFirstPerson == person1
 *             && mySecondPerson == person2
 *             && person1 is the first Item in myLine
 *             && person2 is the second Item in myLine
 *             && MY_MENU has been initialized.
 */
CongaLine::CongaLine(const string& person1, const string& person2) {
	myLine.append(person1);
	myLine.append(person2);
	myFirstPerson = person1;
	mySecondPerson = person2;
	MY_MENU = string("Please enter:\n")
				    + " 1 to join the Conga line at the end\n"
					+ " 2 to join the Conga line after a particular person\n"
					+ " 3 to join the Conga line before a particular person\n"
					+ " 4 to quit\n"
					+ "--> ";
}

/* Method to run the CongaLine simulation,
 *  prompting the user via cout
 *  and reading the user's input via cin.
 */
void CongaLine::run() {
	unsigned menuChoice = 0;
	string yourName, otherPersonsName;
	cout << myFirstPerson << " and " << mySecondPerson
			<< " have started a Conga Line!" << endl;

	while (menuChoice != 4) {
		cout << "\n " << myLine << "\n\n";
//		cout << "\n"; myLine.writeTo(cout); cout << "\n\n";
		cout << "Conga, Conga, Con-GA!  Conga, Conga, Con-GA!\n" << endl;
		cout << MY_MENU;
		cin >> menuChoice;
		if (menuChoice == 1 || menuChoice == 2 || menuChoice == 3) {
			cout << "\nWhat is your name? ";
			cin >> yourName;
		}

		switch( menuChoice ) {
		case 1:
			myLine.append(yourName);
			break;
		case 2:
			cout << "Who do you want to follow? ";
			cin >> otherPersonsName;
			if ( !myLine.insertAfter(otherPersonsName, yourName) ) {
				cout << "\n***" << otherPersonsName
					 << " is not dancing!\n" << endl;
			}
			break;
		case 3:
			cout << "Who do you want to precede? ";
			cin >> otherPersonsName;
			if ( !myLine.insertBefore(otherPersonsName, yourName) ) {
				cout << "\n***" << otherPersonsName
					 << " is not dancing!\n" << endl;
			}
			break;
		case 4:
			cout << "\nThe dance is done!\n";
			break;
		default:
			cout << "\n*** " << menuChoice
			     << " is not a valid choice!\n" << endl;
		}
	}
}

