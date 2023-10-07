/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name   Hla Myint Myat         Date    19.9.23        Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include <cstring>

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   /* TODO: read functions go here  */  
   bool read(char* &name) {
       
       char data[128];
       int result = fscanf(fptr, "%127[^\n]\n",data);
        
       if(result == 1){
           int dataLength = strlen(data);
           name = new char[dataLength + 1];
           strcpy(name, data);
           return true;
       }
       
       return false;
   }
   
   
   bool read(int &empNo) {
       int data;
       int result = fscanf(fptr, "%d,",&data);
       if(result == 1){
           empNo = data;
           return true;
       }
       
      return false;
   }
   
   bool read(double &empSalary) {
      double data;
       int result = fscanf(fptr, "%lf,",&data);
       if(result == 1){
           empSalary = data;
           return true;
       }
       
      return false;
   }
  
}