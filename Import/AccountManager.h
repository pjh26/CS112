/* AccountManager.h declares a class to manage user+password accounts.
 * Joel Adams, for CS 112 at Calvin College.
 */

#ifndef ACCOUNTMANAGER_H_
#define ACCOUNTMANAGER_H_

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Exception.h"
using namespace std;

class AccountManager {
public:
   AccountManager(const string& fileName);
   ~AccountManager();
   void run();
	
protected:
   char getMenuChoice() const;
   void perform(char choice);
   // methods invoked to handle menu choices
   void createNewAccount();        // menu choice 'a'
   void changeUserName();       // menu choice 'b'
   void changePassword();       // menu choice 'c'
   void deleteAccount();           // menu choice 'd'
   // methods to manipulate the map (see below)
   void createNewAccount(const string& userName, const string& password);
   void deleteAccount(const string& userName);
   void changeUserName(const string& oldUserName, const string& newUserName);
   void changePassword(const string& userName, const string& newPassword);
   void printAccounts();
	
private:	
   map<string, string> myAccounts;          // maps userNames to passwords
   typedef pair<string, string> stringPair; // for inserting items into the map
   string myFileName;                       // file containing account info
   friend class AccountManagerTester;
};

#endif /*ACCOUNTMANAGER_H_*/

