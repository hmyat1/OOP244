/***********************************************************************
 OOP244 Workshop #2 DIY (part 2):

 File  File.cpp
 Version 1.0
 Author   Fardad Soleimanloo
 Description
   To completed by students
 Revision History
 -----------------------------------------------------------
 Name   Hla Myint Myat         Date    21.9.23          Reason
***********************************************************************/
 #define _CRT_SECURE_NO_WARNINGS
 #include <cstdio>
 #include <cstring>
 #include <iostream>
 #include "File.h"
 namespace sdds {
    FILE* fptr;
   
    bool openFile(const char filename[]) {
       fptr = fopen(filename, "r");
       return fptr != NULL;
    }
   
    void closeFile() {
       if (fptr) fclose(fptr);
    }
   
    int noOfRecords() {
       int noOfRecs = 0;
       char ch = '\n';
       while (fscanf(fptr, "%c", &ch) == 1) {
          noOfRecs += (ch == '\n');
       }
       rewind(fptr);
       return ++noOfRecs;
    }
   
     bool read(char* &postalCode , int &people) {
        char data[128] = "";
        int population = 0;
        char ch = '\0';
        //int i = 0;
        for(int i = 0 ; i < 4 ;i++){
            fscanf(fptr, "%c",&ch);
            data[i] = ch;
        }
    
        int dataLength = strlen(data);
           postalCode = new char[dataLength + 1];
           strncpy(postalCode, data,3);
       
        fscanf(fptr, "%d",&population);
        people = population;
        fscanf(fptr, "%c",&ch);
        return true;
    }
   

 }

