/***********************************************************************
// OOP244 Workshop #2 lab (part 1): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name  Hla Myint Myat          Date  19.9.23          Reason
***********************************************************************/
#include "Employee.h"
using namespace sdds;

int main() {
   if(load()) {
      display();
   }
   
   deallocateMemory();
   return 0;
}