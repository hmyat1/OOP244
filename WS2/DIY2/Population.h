/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name   Hla Myint Myat         Date      21.9.23        Reason
***********************************************************************/
 #ifndef SDDS_POPULATION_H_
 #define SDDS_POPULATION_H_

 namespace sdds {
    struct Population {
       char* postalCode;
       int people;
    };
   
    void sort();
   
    bool load(Population &pop);

    bool load(const char filename[],char code[4]);

    bool startsWith(const char* cString, const char* subString);

    bool getPostalCode(char* postal_code_prefix);
   
    void display();
   
    void deallocateMemory();

 }
 #endif // SDDS_POPULATION_H_

