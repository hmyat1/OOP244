/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name    Hla Myint Myat             Date   10.10.23        Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }
    
    Flight::operator bool() const {
        return m_passengers > 0 && m_fuel >= m_passengers * 600.0;
    }
    
    Flight::operator int() const {
        return m_passengers;
    }
    
    Flight::operator double() const {
        return m_fuel;
    }
    
    Flight::operator const char*() const {
        return m_title;
    }
    
        // Unary member operator
    bool Flight::operator~() const {
        return m_passengers == 0;
    }
    
        // Binary member operators
    Flight& Flight::operator=(Flight& other) {
        if (this != &other) {
            strcpy(m_title, other.m_title);
            m_passengers = other.m_passengers;
            m_fuel = other.m_fuel;
            other.emptyPlane();
        }
        return *this;
    }
    
    Flight& Flight::operator=(int passengers) {
        if (passengers > 0 && passengers <= Boen747Capacity) {
            m_passengers = passengers;
        }
        return *this;
    }
    
    Flight& Flight::operator=(double fuel) {
        if (fuel >= 0.0 && fuel <= FuelTankCapacity) {
            m_fuel = fuel;
        }
        return *this;
    }
    
    Flight& Flight::operator+=(double fuel) {
        if (fuel > 0.0) {
            m_fuel += fuel;
            if (m_fuel > FuelTankCapacity) {
                m_fuel = FuelTankCapacity;
            }
        }
        return *this;
    }
    
    Flight& Flight::operator+=(int passengers) {
        if (passengers > 0) {
            m_passengers += passengers;
            if (m_passengers > Boen747Capacity) {
                m_passengers = Boen747Capacity;
            }
        }
        return *this;
    }
    
    Flight& Flight::operator-=(double fuel) {
        if (fuel > 0.0) {
            m_fuel -= fuel;
            if (m_fuel < 0.0) {
                    m_fuel = 0.0;
            }
        }
        return *this;
    }
    
    Flight& Flight::operator-=(int passengers) {
        if (passengers > 0) {
            m_passengers -= passengers;
            if (m_passengers < 0) {
                m_passengers = 0;
            }
        }
        return *this;
    }
    
  
        // Binary member + operator
    int Flight::operator+(const Flight& other) const {
            if (*this && other) {
                return m_passengers + other.m_passengers;
            }
            return 0;
    }
    

}