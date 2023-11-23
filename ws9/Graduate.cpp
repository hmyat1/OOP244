// File: Graduate.cpp
#include <iostream>
#include <cstring>
#include "Graduate.h"

void Graduate::setEmpty() {
        m_thesisTitle = nullptr;
        m_supervisor = nullptr;
    }

    void Graduate::setThesisTitle(const char* title) {
        delete[] m_thesisTitle;
        if (title != nullptr) {
            m_thesisTitle = new char[strlen(title) + 1];
            strcpy(m_thesisTitle, title);
        }
        else {
            setEmpty();
        }
    }

    void Graduate::setSupervisor(const char* supervisor) {
        delete[] m_supervisor;
        if (supervisor != nullptr) {
            m_supervisor = new char[strlen(supervisor) + 1];
            strcpy(m_supervisor, supervisor);
        }
        else {
            m_supervisor = nullptr; // Only set m_supervisor to nullptr
        }
    }

    Graduate::Graduate() : Student() {
        setEmpty();
    }

    Graduate::Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor)
        : Student(name, age) {
        setEmpty();
        setThesisTitle(thesisTitle);
        setSupervisor(supervisor);
    }

    Graduate::~Graduate() {
        delete[] m_thesisTitle;
        delete[] m_supervisor;
    }

    Graduate::Graduate(const Graduate& src) : Student(src) {
        setEmpty();
        *this = src;
    }

    Graduate& Graduate::operator=(const Graduate& src) {
        if (this != &src) {
           
            Student::operator=(src);
          
            setThesisTitle(src.m_thesisTitle);
            setSupervisor(src.m_supervisor);
        }
        return *this;
    }

    void Graduate::display() const {
        Student::display();
        if (m_thesisTitle != nullptr && m_supervisor != nullptr) {
            std::cout << "Thesis Title: " << m_thesisTitle << std::endl;
            std::cout << "Supervisor: " << m_supervisor << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
        }
    }