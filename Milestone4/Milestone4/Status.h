/*---------------------------------------------------------- -
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -*/
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <ostream>

namespace sdds {
    class Status {
    public:
        Status();
        Status(const char* desc);
        Status(int c);
        Status(const Status& other);
        Status& operator=(const Status& other);
        Status& operator=(const char* desc);
        Status& operator=(int c);
        operator int() const;
        operator const char* () const;
        operator bool() const;
        Status& clear();
        friend std::ostream& operator<<(std::ostream& os, const Status& status);
       // virtual bool isClear() const;
        ~Status();

    private:
        char* description;
        int code;
    };
}



#endif
