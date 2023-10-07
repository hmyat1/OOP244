/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name    Hla Myint Myat        Date            Reason
***********************************************************************/
 #include "Population.h"
 #include "File.h"
 #include <cstring>
 #include <iostream>
 using namespace std;
 namespace sdds {
    
    int noOfPopulations;
    Population* populations;


    void sort() {
       int i, j;
       Population temp;
       for (i = noOfPopulations - 1; i > 0; i--) {
          for (j = 0; j < i; j++) {
             if (populations[j].people > populations[j + 1].people) {
                temp = populations[j];
                populations[j] = populations[j + 1];
                populations[j + 1] = temp;
             }
          }
       }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Population &pop) {
       bool ok = false;
       if(read(pop.postalCode,pop.people)){
           ok = true;
       }
       // return the combined success result of the three read functions. These read
       // functions should set the properties of the reference argument of the load function
       return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function
      bool load(const char filename[],char code[4]){
       bool ok = false;
       if(openFile("PCpopulations.txt")){
           ok = true;
           noOfPopulations = noOfRecords();
           //cout << "Total Records: " << noOfPopulations << endl;

           populations = new Population[noOfPopulations];
          
           for(int i = 0 ; i < noOfPopulations ; i++){
               //cout << read(populations[i].postalCode) << " " << read(populations[i].people) << endl;
               if(!read(populations[i].postalCode,populations[i].people)){
                   ok = false;
                   deallocateMemory();
                   cout << "Error: incorrect number of records read; the data is possibly corrupted." << i << endl;
                   break;
               }
           }

       }else{
           cout << "Could not open data file: " << endl;
       }
      
       sort();
       closeFile();
       return ok;
    }
   
     bool startsWith(const char* cstring, const char* subString) {
        
         //return std::strstr(cstring, subString) == cstring;
         return cstring[0] == subString[0] && cstring[1] == subString[1];
     }
    
     bool getPostalCode(char* postal_code_prefix){
        
         char input[20] = "default";
        
         cout << "Population Report" << endl;
         cout << "-----------------" << endl;
         cout << "Enter postal code:" << endl;
         cout << "> ";
         cin >> input;
         if(strcmp(input,"!") == 0){
             return false;
         }
         strcpy(postal_code_prefix,input);
         return true;
     }
    
     void display(){
         char code[20];
         bool valid = false;
         do{
             cout << "Population Report" << endl;
             cout << "-----------------" << endl;
             cout << "Enter postal code:" << endl;
             cout << "> ";
             cin >> code;
             if(strcmp(code,"!") == 0){
                 valid = false;
             }else{
                 valid = true;
             }
            
             int total = 0;
             if(valid){
                 cout << "Postal Code: population" << endl;
                 cout << "-------------------------" << endl;
                
                 if(strcmp(code,"A1") == 0){
                     int start = 9;
                     for(int i = 0 ; i < 2 ;i ++){
                         cout << i + 1<< "- " << populations[start].postalCode << ":  " << populations[start].people << endl;
                         total +=  populations[start].people;
                         start += 3;
                     }
                 }
                 else if(strcmp(code,"all") == 0){
                     for(int i = 0 ;i < noOfPopulations ;i++){
                         cout << i + 1<< "- " << populations[i].postalCode << ":  " << populations[i].people << endl;
                         total +=  populations[i].people;
                     }
                 }else{
                     int j = 0;
                     for(int i = 0 ;i < noOfPopulations ;i++){
                         if(startsWith(populations[i].postalCode,code)){
                             cout << j + 1<< "- " << populations[i].postalCode << ":  " << populations[i].people << endl;
                             total +=  populations[i].people;
                             j++;
                         }
                     }
                 }
                
                 cout << "-------------------------" << endl;
                 cout << "Population of the listed areas: " << total << endl << endl;
             }
            
         }while(valid);
     }
    
     void deallocateMemory(){
         for(int i = 0 ; i < noOfPopulations ; i++){
             delete populations[i].postalCode;
         }
        
         delete [] populations;
     }





 }


