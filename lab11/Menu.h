/* Menu.h declares a Menu class for the AccountManager class to use.
 * Joel Adams, for CS 112 at Calvin College.
 */

#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <string>
#include <set>
using namespace std;

class Menu {
public:
	static char QUIT;

	Menu();
	string asString() const;
	void print(ostream& out) const;
	bool containsChoice(char choice) const;
private:
	set<char> myValidChoices;  // the valid menu choices
	string    myValue;         // the menu that is displayed
};

/* insertion operator for ostream output
 * Parameters: out, an ostream;
 *             m, a Menu.
 * Precondition: out.good().
 * Postconndition: out contains m.myValue &&
 *                  return-value == out.
 */
inline ostream& operator<<(ostream& out, const Menu& m) {
	m.print(out);
	return out;
}

#endif /*MENU_H_*/
