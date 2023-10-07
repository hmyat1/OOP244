/***********************************************************************
// OOP244 Workshop #3 lab (part 1): tester program
//
// File  main.cpp
// Version 1.0
// Author   Cornel Barna, Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name  Hla Myint Myat               Date  27.9.23          Reason
***********************************************************************/
#define MIN_TIME 700
#define MAX_TIME 2300
#define MAX_NO_OF_PASSENGERS 1000

namespace sdds{
    
    class Train{
        
        private:
            char *t_name;
            int t_people;
            int t_time;
            
        public:
            void initialize();
            bool validTime(int value)const;
            bool validNoOfPassengers(int value)const;
            void set(const char* name);
            void set(int noOfPassengers, int departure);
            void set(const char* name, int noOfPassengers, int departure);
            void finalize();
            bool isInvalid()const;
            int noOfPassengers() const;
            const char* getName() const;
            int getDepartureTime() const;
            void display() const;


            
    };
    
}

