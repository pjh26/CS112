/* AccountManager.cpp defines methods for managing user+password accounts.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name:
 * Date:
 */
 
 #include "AccountManager.h"

/* initialize AccoutManager with account information from a text file.
 * Precondition: file 'accountInfo.txt' exists, is readable,
 *                and contains a sequence of user-name and password pairs.
 * Postcondition: myAccounts contains the user-name and password pairs.
 */
AccountManager::AccountManager(const string& fileName) {
   myFileName = fileName;
   ifstream fin( fileName.c_str() );
   assert( fin.is_open() );
   string userName, password;
   while (true) {
      fin >> userName >> password;
      if ( fin.eof() ) break;
      try {
         createNewAccount(userName, password);
      } catch (Exception& e) {
         cerr << "\n *** AccountManager(): unable to create account for '"
              << userName << "' (possible redundant userName)\n";
      }
   }
   fin.close();
}

/* create a new account in myAccounts
 * Parameters: userName, password, both strings.
 * Precondition: userName is not already in myAccounts.
 * Postcondition: the (user-name, password) pair has been added to myAccounts
 *        || an Exception is thrown iff the precondition is not met.
 */
void AccountManager::createNewAccount(const string& userName,
                                      const string& password) {
   pair< map<string,string>::iterator, bool > 
     insertResult = myAccounts.insert( stringPair(userName, password) );
		   
   if ( !(insertResult.second) )  
      throw Exception("createNewAccount(user, pass)",
                     string("user") + userName + " already present in system"); 
}

/* auto-save account information to text file on exit.
 * Precondition: the account manager is being destroyed.
 * Postcondition: the (user-name, password) pairs in myAccounts
 *                 have been written to 'accountInfo.txt'.
 */
AccountManager::~AccountManager() {
//	ofstream fout(myFileName.c_str());
//	assert( fout.is_open() );
//	for ( map<string,string>::iterator it = myAccounts.begin();
//	       it != myAccounts.end(); it++) {
//	       	fout << it->first << '\t' << it->second << '\n';
//	}
//	fout.close();
}

/* The AccountManager controller repeatedly
 * - displays the menu
 * - gets the users choice
 * - performs that choice
 * - until the choice indicates 'quit'
 */
void AccountManager::run() {
   while (true) {
	char choice = getMenuChoice();
	if (choice == Menu::QUIT) break;
	perform(choice);
   }
}

/* get a valid menu choice
 * Postcondition: the menu has been displayed,
 *                 the user has entered a character,
 *                 that character is a valid choice from the menu, and
 *                 the return-value == that valid choice.
 */
char AccountManager::getMenuChoice() const {
   Menu menu;
   char choice;
   while (true) {
      cout << '\n' << menu << flush;
      cin >> choice;
      if ( menu.containsChoice(choice) ) break;
      cout << "\n*** " << choice << " is not supported!\n" << endl;
   }
   return choice;
}		

/* perform whatever action the user chose.
 * Parameters: choice, a char.
 * Precondition: choice is a valid menu choice.
 * Postcondition: the action associated with choice has been performed.
 */
void AccountManager::perform(char choice) {
   switch(choice) {
      case 'a':
         createNewAccount();
         break;
      case 'b':
         changeUserName();
         break;
      case 'c':
         changePassword();
         break;
      case 'd':
         deleteAccount();
         break;
      default:
         cerr << "\n *** AccountManager::perform(choice): choice "
              << choice << " is not supported\n" << endl;	
   }
//   printAccounts();
}

/* method invoked for choice 'a'
 * Output: prompts for input, success or failure indicators.
 * Input: a user-name and password for a new account
 * Precondition: user-name is not already in myAccounts.
 * Postcondition: (user-name, password) have been added to myAccounts.
 */
void AccountManager::createNewAccount() {
   bool success = false;
   do {
      cout << "\nEnter new user-name: ";
      string userName;
      cin >> userName;
      cout << "Enter password for " << userName << ": ";
      string password;
      cin >> password;
      try {
         createNewAccount(userName, password);
         cout << "Account successfully created for '" << userName << "'\n";
         success = true;
      } catch (Exception& e) {
         cerr << e.asString() << endl;				
      }			
   } while (!success);
}

/* method invoked for choice 'b'
 * Output: prompts for input, success or failure indicators.
 * Input: an old user-name and a new user-name
 * Precondition: the old user-name is already in myAccounts,
 *                the new user-name is not.
 * Postcondition: the old user-name has been changed to 
 *                 the new user-name in myAccounts
 *                 (keeping the same password).
 */
void AccountManager::changeUserName() {
   cout << "\nChange user-name for which user? ";
   string oldUserName;
   cin >> oldUserName;
   cout << "Change " << oldUserName << " to what? ";
   string newUserName;
   cin >> newUserName;
   try {
      changeUserName(oldUserName, newUserName);
      cout << "Changed user-name '" << oldUserName
           << "' to '" << newUserName << "'\n";
   } catch (Exception& e) {
      cerr << e.asString() << endl;		
   }
}

/* utility method to replace one user-name with another.
 * Parameters: oldUserName, newUserName, a string.
 * Precondition: oldUserName is in myAccounts, newUserName is not.
 * Postcondition: oldUserName has been replaced by newUserName ||
 *          an Exception is thrown iff the precondition is not met.
 */
void AccountManager::changeUserName(const string& oldUserName, const string& newUserName) {

}

/* utility method to delete an account.
 * Parameter: userName, a string.
 * Precondition: userName is in myAccounts.
 * Postcondition: the (userName, password) pair has been
 *                 deleted from myAccounts ||
 *          an Exception is thrown iff the precondition is not met.
 */
void AccountManager::deleteAccount(const string& userName) {

}

/* method invoked for choice 'c'
 * Output: prompts for input, success or failure indicators.
 * Input: a user-name, an old password and a new password
 * Precondition: the user-name is already in myAccounts.
 * Postcondition: the old password associated with user-name has been changed to
 *                 the new password in myAccounts.
 */

void AccountManager::changePassword() {
   cout << "\nEnter the user-name whose password you wish to change: ";	
   string userName;
   cin >> userName;
   cout << "Enter the new password: ";
   string newPassword;
   cin >> newPassword;
   cout << "Reenter the new password: ";
   string newPasswordCheck;
   cin >> newPasswordCheck;
   if (newPassword == newPasswordCheck) {
      try {
         changePassword(userName, newPassword);
         cout << "Password changed for user '" << userName << "'\n" << endl;	
      } catch (Exception& e) {
         cerr << e.asString() << endl;		
      }
   } else {
      cerr << "The two passwords do not match.\n" << endl;
   }
}

void AccountManager::changePassword(const string& userName,
                                    const string& newPassword) {

}

/* method invoked for choice 'd'
 * Output: prompts for input, success or failure indicators.
 * Input: a user-name
 * Precondition: the user-name is in myAccounts,
 * Postcondition: the (user-name,password) have been deleted from myAccounts
 */

void AccountManager::deleteAccount() {
   cout << "\nDelete which user? ";
   string userName;
   cin >> userName;
   try {
      deleteAccount(userName);
      cout << "Account '" << userName << "' removed!" << endl;
   } catch (Exception& e) {
      cerr << e.asString() << endl;
   }
}

/* utility method for displaying the info in myAccounts
 *  (for debugging purposes only).
 * Postcondition: all (user-name, password) pairs in myAccounts
 *                 have been displayed to cout.
 */
void AccountManager::printAccounts()  {
   for ( map<string,string>::iterator it = myAccounts.begin();
          it != myAccounts.end(); it++) {
      cout << it->first << ":" << it->second << endl;
   }
}

