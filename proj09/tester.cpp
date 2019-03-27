
#include "BST_Tester.h"
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

void fileToBST() {
	ofstream fout("BSTSize.txt");
	ofstream foutDup("BSTDups.txt");
	for (unsigned i = 0; i < 10; i++) {
		BST<long int> tempBST;
		unsigned height;
		unsigned numDups = 0;
		string fileNames [10];
		fileNames[0] = "/home/cs/112/proj/09/randomInts01.txt";
		fileNames[1] = "/home/cs/112/proj/09/randomInts02.txt";
		fileNames[2] = "/home/cs/112/proj/09/randomInts03.txt";
		fileNames[3] = "/home/cs/112/proj/09/randomInts04.txt";
		fileNames[4] = "/home/cs/112/proj/09/randomInts05.txt";
		fileNames[5] = "/home/cs/112/proj/09/randomInts06.txt";
		fileNames[6] = "/home/cs/112/proj/09/randomInts07.txt";
		fileNames[7] = "/home/cs/112/proj/09/randomInts08.txt";
		fileNames[8] = "/home/cs/112/proj/09/randomInts09.txt";
		fileNames[9] = "/home/cs/112/proj/09/randomInts10.txt";

		ifstream fin(fileNames[i].c_str());
		string tempStr;
		long int tempLong;
		char* pEnd;
		while (fin) {
			getline(fin, tempStr);
			tempLong = strtol(tempStr.c_str(), &pEnd, 10);
			try {
				tempBST.insert(tempLong);
			} catch (Exception& e) {
				numDups++;
				cout << e << endl;
			}
		}
		fin.close();
		height = tempBST.getHeight();
		fout << height << endl;
		foutDup << numDups << endl;
		tempBST.~BST();
	}
	fout.close();
	foutDup.close();
}


int main() {
	BST_Tester bstt;
	bstt.runTests();
	fileToBST();
}
