// File: Graduate.h
#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H

#include "Student.h"

 class Graduate : public Student {
        char* m_thesisTitle;
        char* m_supervisor;

        void setEmpty();
        void setThesisTitle(const char* title);
        void setSupervisor(const char* supervisor);

    public:
        Graduate();
        Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor);
        virtual ~Graduate();

        Graduate(const Graduate& src);
        Graduate& operator=(const Graduate& src);

        void display() const;
    };

#endif // SDDS_GRADUATE_H