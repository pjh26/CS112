/* AccountManagerTester.cpp defines test-methods for AccountManager.
 * Joel Adams, for CS 112 at Calvin College.
 */

#include "AccountManagerTester.h"

void AccountManagerTester::runTests() {
	cout << "Testing AccountManager methods..." << endl;
	testCreateAndDelete();
//	testChangeUser();
//	testChangePassword();
	cout << "All tests passed!" << endl;
}

//void AccountManagerTester::testChangePassword() {
//	cout << "- Testing changePassword()... " << flush;
//	AccountManager am("testAccountInfo.txt");
//	// change password
//	am.createNewAccount("dan", "dan1234");
//	am.changePassword("dan", "1234dan");
//	assert( am.myAccounts["dan"] == "1234dan" );
//	cout << " 1 " << flush;
//	// try on non-existant account
//	am.deleteAccount("dan");
//	try {
//		am.changePassword("dan", "d");
//		cerr << "\n changed password for 'dan' after deleting him\n";
//		exit(1);
//	} catch (Exception& e) {
//		cout << " 2 " << flush;
//	}
//	cout << " Passed!" << endl;
//}

//void AccountManagerTester::testChangeUser() {
//	cout << "- Testing changeUserName()... " << flush;
//	AccountManager am("testAccountInfo.txt");
//	// change user-name
//	am.createNewAccount("dan", "dan1234");
//	am.changeUserName("dan", "danno");
//	assert( am.myAccounts["danno"] == "dan1234" );
//	cout << " 1 " << flush;
//	// verify that the old account is gone
//	try {
//		am.deleteAccount("dan");
//		cerr << "\n able to delete 'dan' after changed\n";
//		exit(1);
//	} catch (Exception& e) {
//		cout << " 2 " << flush;
//	}
//	try {
//		am.deleteAccount("danno");
//	} catch (Exception& e) {
//		cerr << e.asString() << endl;
//		exit(1);
//	}
//	cout << " 3 " << flush;
//	cout << " Passed!" << endl;
//}

void AccountManagerTester::testCreateAndDelete() {
	cout << "- Testing create and delete()... " << flush;
	// construct an account manager
	AccountManager am("testAccountInfo.txt");
	assert( am.myAccounts["ann"] == "1234" );
	assert( am.myAccounts["bob"] == "bubba" );
	assert( am.myAccounts["cam"] == "mac" );
	// create a new account
	am.createNewAccount("dan", "nad");
	assert( am.myAccounts["dan"] == "nad" );
	cout << " 1 " << flush;
	// try to create a duplicate account -- should fail
	try {
		am.createNewAccount("dan", "d");
		cerr << "\ncreated duplicate account for 'dan'\n";
		exit(1);
	} catch (Exception& e) {
		cout << " 2 " << flush;
	}
	// delete the account
	am.deleteAccount("dan");
	cout << " 3 " << flush;
	// try to delete the deleted account -- should fail
	try {
		am.deleteAccount("dan");
		cerr << "\ndelete succeeded for 'dan'\n";
		exit(1);
	} catch (Exception& e) {
		cout << " 4 " << flush;
	}
	cout << " Passed!" << endl;
}
