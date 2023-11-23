#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

class Student {
        char* m_name;
        int m_age;
        
    public:
        void init(const char* name, int age);
        Student();
        Student(const char* name, int age);
        Student(const Student& src);
        Student& operator=(const Student& src);
        virtual ~Student();
        void display() const;
    };
#endif // SDDS_STUDENT_H