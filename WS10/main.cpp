/***********************************************************************
// OOP244 Workshop # 10: tester program
//
// File: main.cpp
// Version 1.0
// Date: 2023/11/25
// Author: Fardad Soleimanloo
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Car.h"
#include "EmployeeOffice.h"
#include "Student.h"
#include "selection.h"
using namespace std;
using namespace sdds;

int main() {

   Student oop244[7] = { { 22345, "Lisa Simpson", 4.0}, {12345, "Bart Simpson", 2.1},
                     { 24567, "Ralph Wiggum", 2.0}, {56789, "Milhouse Van Houten",4.0},
                     { 67890, "Todd Flanders", 4.0}, {34567, "Nelson Muntz", 3.5},{33223, "Magie Simpson", 3.0} };
   EmployeeOffice seneca[6] = { {"Carl Carlson", 1000},{"Mindy Simmons", 2000},
                    {"Lenny Leonard", 1000},{"Waylon Smithers", 3000},
                    {"Frank Grimes", 3000},{"Homer Simpson", 1000} };
   Car parking[7] = { {"GVBT01", "Tesla Model S"}, {"BBCDEF", "BMW 320"},
                {"CDEFG", "Ford Festiva"},{"GVAB24", "Tesla Cyber Truck"}, {"BCDEFG", "Ford Explorer"},
                {"AFGHIJ", "Nissan Maxima"},{"GVDD99", "Tesla Model 3"} };
   int* idx;
   idx = select(oop244, 4.0, 7);
   csvDisplaySelection("OOP244 Students with 4.0 GPA:", oop244, idx);
   cout << "=============" << endl;
   delete[] idx;
   idx = select(seneca, 3000, 6);
   csvDisplaySelection("Seneca employees in office number 3000:", seneca, idx);
   cout << "=============" << endl;
   delete[] idx;
   idx = select(parking, "Ford", 7);
   csvDisplaySelection("Ford Cars in the parking:", parking, idx);
   cout << "=============" << endl;
   delete[] idx;
   return 0;
}
