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
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds {
   class Displayable {
   public:
      virtual std::ostream& display(std::ostream& os)const = 0;
   };
   std::ostream& operator<<(std::ostream& os, const Displayable& c);
}
#endif // !SDDS_READWRITE_H_
