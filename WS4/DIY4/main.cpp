/***********************************************************************
// OOP244 Workshop #4 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name     Hla Myint Myat            Date   7.10.23         Reason
***********************************************************************/
#include <iostream>
#include "Label.h"
#include "LabelMaker.h"
using namespace sdds;
using namespace std;
int main() {
   int noOfLabels;

   Label
      theProgram("/-\\|/-\\|"),
      test1,
      test2("ABCDEFGH");
   test1.printLabel();
   test2.printLabel();
   theProgram.printLabel();
   test1.text("Testing one, two, three");
   test1.printLabel() << endl;
   theProgram.text("Professor's Label Maker Program Tester");
   theProgram.printLabel() << endl << endl;

   cout << "Number of labels to create: ";
   cin >> noOfLabels;
   cin.ignore(10000, '\n');

   LabelMaker lblMkr(noOfLabels);

   lblMkr.readLabels();

   lblMkr.printLabels();
   return 0;
}