/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name    Hola Myint Myat              Date   14.10.23         Reason
***********************************************************************/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>

namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;

   public:
        Portfolio();

        void emptyPortfolio();
        Portfolio(double value, const char* stock, char type);
    
        void dispPortfolio() const;
        std::ostream& display() const;
        operator double() const;
        operator const char*() const;
        operator char() const;
        operator bool() const;
        bool operator~() const;

    
        Portfolio& operator+=(double amount);
    
        friend Portfolio operator+(const Portfolio& left, const Portfolio& right) {
            if (left && right) {
                return Portfolio(left.m_value + right.m_value, left.m_stock, left.m_type);
            }
            return Portfolio(0, "", '\0');
        }
        
        friend double operator+=(double& left, const Portfolio& right) {
            if (right) {
                left += right.m_value;
            }
            return left;
        }
        
        Portfolio& operator-=(double amount) {
            if (*this && amount >= 0) {
                m_value -= amount;
            }
            return *this;
        }
        
        friend Portfolio operator<<(Portfolio& left, Portfolio& right) {
            if (&left != &right && left && right) {
                left += right;
                right.m_value = 0;
                right.m_stock[0] = 0;
                right.m_type = 'E';
            }
            return left;
        }
    
        friend Portfolio operator>>(Portfolio& left, Portfolio& right) {
            if (&left != &right && left && right) {
                right += left;
                left.m_value = 0;
                left.m_stock[0] = 0;
                left.m_type = 'E';
            }
            return right;
        }

   };
}
#endif // SDDS_Portfolio_H_