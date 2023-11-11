/*---------------------------------------------------------- -
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -*/
#include "Status.h"
#include <string>
#include <cstring>
#include <iostream>
#include <ostream>


namespace sdds {

    Status::Status() : description(nullptr), code(0) {}

    Status::Status(const char* desc) : description(nullptr), code(0) {
        if (desc) {
            size_t len = strlen(desc);
            description = new char[len + 1];
            strcpy(description, desc);
        }
    }

    Status::Status(int c) : description(nullptr), code(c) {}

    Status::Status(const Status& other) : description(nullptr), code(other.code) {
        if (other.description) {
            size_t len = strlen(other.description);
            description = new char[len + 1];
            strcpy(description, other.description);
        }
    }

    Status& Status::operator=(const Status& other) {
        if (this == &other) {
            return *this;
        }
        delete[] description;  // Clear the previous description
        description = nullptr;
        clear();
        code = other.code;
        if (other.description) {
            size_t len = strlen(other.description);
            description = new char[len + 1];
            strcpy(description, other.description);
        }
        return *this;
    }

    Status& Status::operator=(const char* desc) {
        clear();
        if (desc) {
            size_t len = strlen(desc);
            description = new char[len + 1];
            strcpy(description, desc);
        }
        else {
            code = 0;
        }
        return *this;
    }

    Status& Status::operator=(int c) {
        // clear();

        code = c;
        return *this;
    }

    Status::operator int() const {
        return code;
    }

    Status::operator const char* () const {
        return description ? description : "";
    }

    Status::operator bool() const {
        return code == 0 && description == nullptr;
    }

    Status& Status::clear() {
        code = 0;
        delete[] description;
        description = nullptr;

        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Status& status) {
        if (status.code != 0) {
            os << "ERR#" << status.code << ": ";
        }
        if (status.description != nullptr) {
            os << status.description;
        }
        return os;
    }

    Status::~Status() {
        clear();
    }




}
