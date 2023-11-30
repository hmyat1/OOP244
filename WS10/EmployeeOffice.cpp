/***********************************************************************
// OOP244 Workshop # 10
//
// Version 1.0
// Date: 2023/11/25
// Author: Fardad Soleimanloo
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "EmployeeOffice.h"
namespace sdds {
   EmployeeOffice::EmployeeOffice(const char* name, int office) { 
      strcpy(m_name, name);
      m_office = office;
   }
   ostream& EmployeeOffice::display(ostream& os)const {
      return os << m_name << " (Office# " << m_office << ")";
   }
   bool EmployeeOffice::operator==(int office)const {
      return m_office == office;
   }
}