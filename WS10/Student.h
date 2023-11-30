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
#include <iostream>
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "Displayable.h"
namespace sdds {
   class Student : public Displayable {
      int m_stno{};
      char m_name[41]{};
      double m_gpa{};
   public:
      Student() = default;
      Student(int stno, const char* name, double gpa);
      std::ostream& display(std::ostream& os)const;
      bool operator==(double gpa)const;
   };
}
#endif // !SDDS_STUDENT_H_
