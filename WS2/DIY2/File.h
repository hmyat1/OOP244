/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name  Hla Myint Myat          Date   21.9.23           Reason
***********************************************************************/
 #ifndef SDDS_FILE_H_
 #define SDDS_FILE_H_
 namespace sdds {
    bool openFile(const char filename[]);
    void closeFile();
    int noOfRecords();
    // TODO: Declare overloaded read function prototypes
    bool read(char*&,int&);

 }
 #endif // !SDDS_FILE_H_

