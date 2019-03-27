/*
 * main.cpp
 *
 *  Created on: Feb 5, 2018
 *      Author: Peter
 *      CS 112
 *      Project 1
 */

#include <iostream>
#include <string>
#include <cassert>
#include "SongTester.h"
#include "PlayListTester.h"

using namespace std;

int main() {
	SongTester sTester;
	sTester.runTests();
	PlayListTester plTester;
	plTester.runTests();
}
