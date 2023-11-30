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
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#include "Displayable.h"
namespace sdds {
   class EmployeeOffice : public Displayable {
      int m_office{};
      char m_name[41]{};
   public:
      EmployeeOffice() = default;
      EmployeeOffice(const char* name, int office);
      std::ostream& display(std::ostream& os)const;
      bool operator==(int office)const;
   };


}
#endif // !SDDS_EMPLOYEE_H_