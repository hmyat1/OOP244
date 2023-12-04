#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"
#include "Utils.h"

namespace sdds {
    Date::Date() : m_year(0), m_month(0), m_day(0), m_state(true), m_formatted(true) {
        ut.getSystemDate(&m_year, &m_month, &m_day);
    }

    Date::Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day), m_formatted(true) {
        if (!validate()) {
            m_state = "Invalid date in date";
        }
    }

    bool Date::validate() {
        if (m_year < ut.curYear() || m_year > ut.sdds_maxYear) {
            m_state = "Invalid year in date";
            m_state = 1;
            return false;
        }
        if (m_month < 1 || m_month > 12) {
            m_state = "Invalid month in date";
            m_state = 2;
            return false;
        }
        if (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year)) {
            m_state = "Invalid day in date";
            m_state = 3;
            return false;
        }
        m_state.clear();
        return true;
    }

    void Date::formatted(bool value) {
        m_formatted = value;
    }

    Status Date::state() const {
        return m_state;
    }

    bool Date::operator==(const Date& other) const {
        return uniqueDateValue() == other.uniqueDateValue();
    }

    bool Date::operator!=(const Date& other) const {
        return uniqueDateValue() != other.uniqueDateValue();
    }

    bool Date::operator<(const Date& other) const {
        return uniqueDateValue() < other.uniqueDateValue();
    }

    bool Date::operator>(const Date& other) const {
        return uniqueDateValue() > other.uniqueDateValue();
    }

    bool Date::operator<=(const Date& other) const {
        return uniqueDateValue() <= other.uniqueDateValue();
    }

    bool Date::operator>=(const Date& other) const {
        return uniqueDateValue() >= other.uniqueDateValue();
    }

    int Date::uniqueDateValue() const {
        return m_year * 372 + m_month * 31 + m_day;
    }

    void Date::read(std::istream& is) {
        int year, month, day;
        is >> year;
        if (!(year)) {
            m_state = "Invalid date value";
            //is.clear();
            //is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        if (year >= 10000) {
            m_year = year / 10000;
            month = (year / 100) % 100;
            day = year % 100;
            if (m_year < 100)
                m_year += ut.curYear() / 100 * 100;
        }
        else {
            m_year = ut.curYear();
            month = year / 100;
            day = year % 100;
        }

        m_month = month;
        m_day = day;

        //if (!validate()) {
        //    is.setstate(std::ios::failbit);
        //}
    }

    void Date::write(std::ostream& os) const {
        if (m_formatted) {
            os << std::setw(4) << std::setfill('0') << m_year << '/';
            os << std::setw(2) << std::setfill('0') << m_month << '/';
            os << std::setw(2) << std::setfill('0') << m_day;
        }
        else {
            os << std::setw(2) << std::setfill('0') << (m_year % 100);
            os << std::setw(2) << std::setfill('0') << m_month;
            os << std::setw(2) << std::setfill('0') << m_day;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Date& date) {
        date.write(os);
        return os;
    }

    std::istream& operator>>(std::istream& is, Date& date) {
        date.read(is);
        return is;
    }
}
