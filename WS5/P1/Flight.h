/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name  Hla Myint Myat               Date  10.10.23          Reason
***********************************************************************/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>
#include <cstring>
namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
   
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;
        

        operator bool() const;
    
        operator int() const;
    
        operator double() const;
    
        operator const char*() const;
    
        // Unary member operator
        bool operator~() const;
    
        // Binary member operators
        Flight& operator=(Flight& other);
    
        Flight& operator=(int passengers);
    
        Flight& operator=(double fuel);
    
        Flight& operator+=(double fuel);
    
        Flight& operator+=(int passengers);
    
        Flight& operator-=(double fuel);
    
        Flight& operator-=(int passengers);
    
        // Left shift operator (<<)
        friend Flight& operator<<(Flight& left, Flight& right) {
            if (&left != &right && left && right) {
                int spaceLeft = Boen747Capacity - left.m_passengers;
                if (spaceLeft > 0) {
                    int transferPassengers = spaceLeft < right.m_passengers ? spaceLeft : right.m_passengers;
                    left.m_passengers += transferPassengers;
                    right.m_passengers -= transferPassengers;
                }
            }
            return left;
        }
    
        // Right shift operator (>>)
        friend Flight& operator>>(Flight& left, Flight& right) {
            if (&left != &right && left && right) {
                
                int spaceLeft = Boen747Capacity - right.m_passengers; // 50
                if (spaceLeft > 0) {
                    
                    int transferPassengers = spaceLeft < left.m_passengers ? spaceLeft : left.m_passengers;
                    right.m_passengers += transferPassengers;
                    left.m_passengers -= transferPassengers;
                    
                   
                }
            }
            return left;
        }
    
        // Binary member + operator
        int operator+(const Flight& other) const;
    
        // Binary helper operator
        friend int operator+=(int& left, const Flight& right) {
            if (right) {
                left += right.m_passengers;
            }
            return left;
        }

   };
   

}
#endif // SDDS_FLIGHT_H