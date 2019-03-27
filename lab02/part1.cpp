///* part1.cpp
// * Name:
// * Date:
// * Begun by: Joel Adams, for CS 112 at Calvin College.
// */
//
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int main() {
//	bool          boolVal;
//	short         shortVal;
//	int           intVal;
//	long          longVal;
//	float         floatVal;
//	double        doubleVal;
//	long double   ldoubleVal;
//	long double	  ldoubleVal2;
//	char          charVal1;
//	char          charVal2;
//
//	bool *        bPtr;
//	short *       sPtr;
//	int *         iPtr;
//	long *        lPtr;
//	float *       fPtr;
//	double *      dPtr;
//	long double * ldPtr;
//	char *        cPtr;
//
//	ofstream fout("hexListAddress.txt");
//
//	fout << "Bool Adrs" << "\t" << &boolVal << "\n"
//		 << "Short Adrs" << "\t" << &shortVal << "\n"
//		 << "Int Adrs" << "\t" << &intVal << "\n"
//		 << "Long Adrs" << "\t" << &longVal << "\n"
//		 << "Float Adrs" << "\t" << &floatVal << "\n"
//		 << "Dble Adrs" << "\t" << &doubleVal << "\n"
//		 << "Long Dbl Adrs" << "\t" << &ldoubleVal << "\n"
//		 << "Char Adrs 1" << "\t" << static_cast<void*>(&charVal1) << "\n"
//		 << "Char Adrs 2" << "\t" << static_cast<void*>(&charVal2) << "\n"
//		 << endl;
//
//	fout << "Boolean Ptr" << "\t" << &bPtr << "\n"
//		 << "Short Ptr" <<  "\t" << &sPtr << "\n"
//		 << "Integer Ptr" <<  "\t" << &iPtr << "\n"
//		 << "Long Ptr" <<  "\t" << &lPtr << "\n"
//		 << "Float Ptr" <<  "\t" << &fPtr << "\n"
//		 << "Double Ptr" <<  "\t" << &dPtr << "\n"
//		 << "Long Dble Ptr" <<  "\t" << &ldPtr << "\n"
//		 << "Char Ptr" << "\t" << &cPtr << "\n";
//
//		fout.close();
//
//}
