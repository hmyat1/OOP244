#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
#include "Perishable.h"
#include "Item.h"
#include "Status.h"
#include "Date.h"

namespace sdds {

    Perishable::Perishable() : Item(), m_handlingInstructions(nullptr) {}

    Perishable::Perishable(const Perishable& src) : Item(src) {
        m_handlingInstructions = nullptr;
        *this = src; // Reuse assignment operator logic
    }

    Perishable::~Perishable() {
        delete[] m_handlingInstructions;
    }

    Perishable& Perishable::operator=(const Perishable& src) {
        if (this != &src) {
            Item::operator=(src); // Call base class assignment operator

            // Clean up existing resources
            delete[] m_handlingInstructions;
            m_handlingInstructions = nullptr;

            // Copy expiry date
            m_expiryDate = src.m_expiryDate;

            // Copy handling instructions
            if (src.m_handlingInstructions != nullptr) {
                m_handlingInstructions = new char[strlen(src.m_handlingInstructions) + 1];
                strcpy(m_handlingInstructions, src.m_handlingInstructions);
            }
        }
        return *this;
    }

    const Date& Perishable::expiry() const {
        return m_expiryDate;
    }

    Perishable::operator bool() const {
        return m_sku!=0;
    }

    std::istream& Perishable::read(std::istream& istr) {
        Item::read(istr);
        delete[] m_handlingInstructions;
        m_handlingInstructions = nullptr;

        // Prompt for expiry date
        std::cout << "Expiry date (YYMMDD): ";
        istr >> m_expiryDate;
        istr.ignore();  // Ignore the newline

        // Prompt for handling instructions
        std::cout << "Handling Instructions, ENTER to skip: ";
        char firstChar = istr.peek();
        if (firstChar != '\n') {
            m_handlingInstructions = new char[1000];  // Adjust the size as needed
            istr.getline(m_handlingInstructions, 1000);
        }
        else {
            istr.ignore();  // Ignore the newline
        }

        // Check if the istream object is in a fail state
        if (istr.fail()) {
            m_status = "Perishable console date entry failed!";
        }

        return istr;
    }

    std::ostream& Perishable::display(std::ostream& ostr) const {
        if (!m_status) {
            ostr << m_status;
        }
        else {
            if (Item::linear()) {
                Item::display(ostr);  // Call the display of the base class in linear mode

                ostr << (m_handlingInstructions && *m_handlingInstructions ? '*' : ' ');// PUT THE DATE FUNTION HERE //
                ostr << m_expiryDate; //EDITED EXPIREY//
            }
            else {
                ostr << "Perishable ";
                Item::display(ostr);
                ostr << "Expiry date: ";// PUT THE DATE FUNTION HERE //
                ostr << m_expiryDate; //EDITED EXPIREY//
                std::cout << std::endl;
                if (m_handlingInstructions && *m_handlingInstructions) {
                    ostr << "Handling Instructions: " << m_handlingInstructions << std::endl;
                }
            }
        }
        return ostr;
    }

    std::ofstream& Perishable::save(std::ofstream& ofstr) const {
        if (m_status) {
            Item::save(ofstr);  // Call the save of the base class


            if (m_handlingInstructions!=nullptr) {
                ofstr << m_handlingInstructions << "\t";
            }
            else {
                ofstr << "\t";
            }
            ofstr << std::setw(2) << std::setfill('0') << (m_expiryDate.m_year % 100)
                << std::setw(2) << std::setfill('0') << m_expiryDate.m_month
                << std::setw(2) << std::setfill('0') << m_expiryDate.m_day << "\t";

            //ofstr << std::endl;

            return ofstr;
        }
        return ofstr;
    }

    std::ifstream& Perishable::load(std::ifstream& ifstr) {
        Item::load(ifstr);

        if (ifstr.fail()) {
            m_status = "Input file stream read (perishable) failed!";
            return ifstr;
        }

        delete[] m_handlingInstructions;
        m_handlingInstructions = nullptr;

        //ifstr.ignore(); // Ignore the tab character

        char temp[1000];
        //ifstr.ignore();
        if (ifstr.getline(temp, 1000, '\t') && isalpha(temp[0])) {
            m_handlingInstructions = new char[strlen(temp) + 1];
            strcpy(m_handlingInstructions, temp);
        }

        ifstr >> m_expiryDate;
        ifstr.ignore(); // Ignore the newline character

        return ifstr;
    }

    int Perishable::readSku(std::istream& istr) {
        m_status.clear();
        bool success = false;
        std::cout << "SKU: ";
        while (!success) {

            if (!(istr >> m_sku)) {
                std::cout << "Invalid Integer, retry: ";
                istr.clear();
                istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (m_sku < 10000 || m_sku > 39999) {
                std::cout << "Value out of range [10000<=val<=39999]: ";
            }
            else {
                success = true;
            }
        }

        return m_sku;
    }

    
}
















