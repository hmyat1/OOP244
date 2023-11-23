#include <iostream>
#include <cstring>
#include "Student.h"
void Student::init(const char* name, int age) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        m_age = age;
    }

    Student::Student() : m_name(nullptr), m_age(0) {
        // Default constructor
    }

    Student::Student(const char* name, int age) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name,name);
        m_age = age;
    }

    Student::Student(const Student& src) {
        init(src.m_name, src.m_age);
    }

    Student& Student::operator=(const Student& src) {
        if (this != &src) {
            delete[] m_name;
            init(src.m_name, src.m_age);
        }
        return *this;
    }

    Student::~Student() {
        delete[] m_name;
    }

    void Student::display() const {
        std::cout << "Name: " << m_name << std::endl;
        std::cout << "Age: " << m_age << std::endl;
    }
