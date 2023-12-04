#include "Item.h"
#include "AidMan.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>
#include <limits>
#include "Utils.h"

namespace sdds {

    Item::Item() : m_price(0.0), m_quantityOnHand(0), m_quantityNeeded(0), m_description(nullptr), m_displayLinear(false), m_sku(0) {}

    Item::~Item() {
        delete[] m_description;
    }

    Item::Item(const Item& src) : m_price(src.m_price), m_quantityOnHand(src.m_quantityOnHand), m_quantityNeeded(src.m_quantityNeeded),
        m_displayLinear(src.m_displayLinear), m_status(src.m_status), m_sku(src.m_sku) {
        if (src.m_description != nullptr) {
            m_description = new char[strlen(src.m_description) + 1];
            strcpy(m_description, src.m_description);
        }
        else {
            m_description = nullptr;
        }
    }

    Item& Item::operator=(const Item& src) {
        if (this != &src) {
            m_price = src.m_price;
            m_quantityOnHand = src.m_quantityOnHand;
            m_quantityNeeded = src.m_quantityNeeded;
            m_displayLinear = src.m_displayLinear;
            m_status = src.m_status;
            m_sku = src.m_sku;

            delete[] m_description;

            if (src.m_description != nullptr) {
                m_description = new char[strlen(src.m_description) + 1];
                strcpy(m_description, src.m_description);
            }
            else {
                m_description = nullptr;
            }
        }
        return *this;
    }

    void Item::clear() {
        m_status.clear();
    }

    int Item::qtyNeeded() const {
        return m_quantityNeeded;
    }

    int Item::qty() const {
        return m_quantityOnHand;
    }

    Item::operator double() const {
        return m_price;
    }

    Item::operator bool() const {
        return m_status;
    }

    int Item::operator-=(int qty) {
        if (qty > 0) {
            m_quantityOnHand -= qty;
        }
        return m_quantityOnHand;
    }

    int Item::operator+=(int qty) {
        if (qty > 0) {
            m_quantityOnHand += qty;
        }
        return m_quantityOnHand;
    }

    void Item::linear(bool isLinear) {
        m_displayLinear = isLinear;
    }

    bool Item::operator==(int sku) const {
        return m_sku == sku;
    }

    bool Item::operator==(const char* description) const {
        if (description == nullptr || m_description == nullptr) {
            return false;
        }

        // Check if the SKU matches
        if (isdigit(description[0]) && std::stoi(description) == m_sku) {
            return true;
        }

        // Check if the description contains the provided Cstring
        if (strstr(m_description, description) != nullptr) {
            return true;
        }

        return false;
    }

    std::ofstream& Item::save(std::ofstream& ofstr) const {
        if (m_status) {
            ofstr << m_sku << "\t" << m_description << "\t" << m_quantityOnHand << "\t" << m_quantityNeeded << "\t"
                << std::fixed << std::setprecision(2) << m_price << "\t";
        }
        return ofstr;
    }

    std::ifstream& Item::load(std::ifstream& ifstr) {
        
        
        delete[] m_description;

        m_description = nullptr;
        
        
    
        ifstr >> m_sku;
        if (ifstr.fail()) {
            m_status = "Input file stream read failed!";
        }
        else {
            //std::cout << "SKU: " << m_sku << std::endl;
            char temp[2000];
            ifstr.ignore();
            ifstr.getline(temp, 2000, '\t');
            m_description = new char[strlen(temp) + 1];
            strcpy(m_description, temp);
            //std::cout << "Description: " << m_description << std::endl;
            ifstr >> m_quantityOnHand;
            ifstr.ignore();

            ifstr >> m_quantityNeeded;
            ifstr.ignore();

            ifstr >> m_price;
            ifstr.ignore(1);
        }
        return ifstr;
    }

    std::ostream& Item::display(std::ostream& ostr) const {
        if (!m_status) {
            ostr << m_status;
        }
        if (m_status&&m_sku != 0 && m_description != nullptr) {
            if (m_displayLinear) {
                ostr << std::setw(5) << m_sku << " | "
                    << std::left << std::setw(35) << std::setfill(' ') << (std::strlen(m_description) > 35 ? std::string(m_description, 35) : m_description)
                    << " | " << std::right << std::setw(4) << m_quantityOnHand << " | "
                    << std::right << std::setw(4) << m_quantityNeeded << " | "
                    << std::right << std::setw(7) << m_price << " |";
            }
            else {
                ostr << "AMA Item:" << std::endl
                    << std::setw(5) << m_sku << ": "
                    << m_description << std::endl
                    << "Quantity Needed: " << m_quantityNeeded << std::endl
                    << "Quantity Available: " << m_quantityOnHand << std::endl
                    << "Unit Price: $" << std::fixed << std::setprecision(2) << m_price << std::endl
                    << "Needed Purchase Fund: $" << std::fixed << std::setprecision(2) << (m_quantityNeeded * m_price) - (m_quantityOnHand * m_price) << std::endl;
            }
        }
        return ostr;
    }

    int Item::readSku(std::istream& istr) {
        m_status.clear();
        bool success = false;
        std::cout << "SKU: ";
        while (!success) {
            
            if (!(istr >> m_sku)) {
                std::cout << "Invalid Integer, retry: ";
                istr.clear();
                istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (m_sku < 40000 || m_sku > 99999) {
                std::cout << "Value out of range [40000<=val<=99999]: ";
            }
            else {
                success = true;
            }
        }

        return m_sku;
    }

    std::istream& Item::read(std::istream& istr) {
        delete[] m_description;
        m_description = nullptr;

        std::cout << "AMA Item:" << std::endl
            << "SKU: " << m_sku << std::endl
            << "Description: ";

        istr.ignore();
        char temp[2000];
        istr.getline(temp, 2000);
        m_description = new char[strlen(temp) + 1];
        strcpy(m_description, temp);

        // Quantity Needed
        bool success = false;
        std::cout << "Quantity Needed: ";
        while (!success) {
            
            if (!(istr >> m_quantityNeeded)) {
                std::cout << "Invalid Integer, retry: ";
                istr.clear();
                istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (m_quantityNeeded < 1 || m_quantityNeeded > 9999) {
                std::cout << "Value out of range [1<=val<=9999]: ";
            }
            else {
                success = true;
            }
        }

        // Quantity On Hand
        success = false;
        std::cout << "Quantity On Hand: ";
        while (!success) {
            
            if (!(istr >> m_quantityOnHand)) {
                std::cout << "Invalid Integer, retry: ";
                istr.clear();
                istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (m_quantityOnHand < 0 || m_quantityOnHand > m_quantityNeeded) {
                std::cout << "Value out of range [0<=val<=22]: ";
            }
            else {
                success = true;
            }
        }

        // Price
        success = false;
        std::cout << "Unit Price: $";
        while (!success) {
            
            if (!(istr >> m_price)) {
                std::cout << "Invalid number, retry: ";
                istr.clear();
                istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (m_price < 0.0 || m_price > 9999.0) {
                std::cout << "Value out of range [0.00<=val<=9999.00]: ";
            }
            else {
                success = true;
            }
        }

        return istr;
    }
    

    bool Item::linear() const {
        return m_displayLinear;
    }

    void Item::setsku(int Presku) {
        presku = Presku;
    }
}


















