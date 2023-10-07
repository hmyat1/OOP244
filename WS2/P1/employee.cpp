/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name      Hla Myint Myat      Date    19.9.23        Reason
***********************************************************************/
#include <iostream>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee &emp) {
      bool ok = false;
      if(read(emp.m_empNo) && read(emp.m_salary) && read(emp.m_name)){
          ok = true;
      }
      // return the combined success result of the three read functions. These read 
      // functions should set the properties of the reference argument of the load function
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      if(openFile(DATAFILE)){
          ok = true;
          noOfEmployees = noOfRecords();
          //cout << "Total Records: " << noOfEmployees << endl;

          employees = new Employee[noOfEmployees];
          
          for(int i = 0 ; i < noOfEmployees ; i++){
              if(!read(employees[i].m_empNo) || !read(employees[i].m_salary) || !read(employees[i].m_name)){
                  ok = false;
                  deallocateMemory();
                  cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                  break;
              }
          }

      }else{
          cout << "Could not open data file: " << DATAFILE << endl;
      }
      
      closeFile();
      return ok;
   }

   // TODO: Implementation for the display functions go here

    void display(const Employee &emp){
        cout << "NUMBER: " << emp.m_name << ", "
       << emp.m_empNo<< ", $" << emp.m_salary << std::endl;
    }
    
    void display(){
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
        sort();
        for(int i = 0 ; i < noOfEmployees ; i++){
              cout << i + 1<< "- "<< employees[i].m_empNo << ": "<< employees[i].m_name<< ", $"<< employees[i].m_salary << endl; 
        }
        
        
    }

   // TODO: Implementation for the deallocateMemory function goes here
   
   void deallocateMemory(){
       for(int i = 0 ; i < noOfEmployees; i++){
           delete [] employees[i].m_name;
       }
       delete [] employees;
   }



}