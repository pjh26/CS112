 /* main.cpp
  * Student name: Peter Haagsma
  * Date: January 30, 2018
  * Author: Prof. Joel Adams
  * For: CS 112, Lab 0 at Calvin College.
  */

#include <iostream>
#include <string>
#include "Matrix.h"
using namespace std;

int main() {
		cout << "Welcome to the Matrix program!" << endl;

      cout << "Enter name of file containing the first matrix: ";
      string fileName1;
      cin >> fileName1;
      Matrix m1;
      m1.fill(fileName1);
      cout << m1 << endl;

      cout << "Enter name of file containing the second matrix: ";
      string fileName2;
      cin >> fileName2;
      Matrix m2;
      m2.fill(fileName2);
      cout << m2 << endl;

      if (m1 == m2) {
              cout << "The two matrices are the same!" << endl;
      } else {
              cout << "The two matrices are different!" << endl;
      }
}
