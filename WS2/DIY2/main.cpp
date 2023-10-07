/***********************************************************************
// OOP244 Workshop #2 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name   Hla Myint Myat         Date    21.9.23          Reason
***********************************************************************/
 #include "Population.h"
 using namespace sdds;
 int main() {
     char code[4]{};
    
    if (load("PCpopulationsComplete.csv",code)) {
       display();
    }
    deallocateMemory();
    return 0;
 }

