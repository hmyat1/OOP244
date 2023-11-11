#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Utils.h"
#include <chrono>
#include <string>
#include <cstring>

using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    void Utils::alocpy(char*& destination, const char* source) {
        if (source) {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
        else {
            destination = nullptr;
        }
    }

    int Utils::getint(const char* prompt) {
        int num;
        bool success = false;

        while (!success) {
            if (prompt)
                cout << prompt;

            if (!(cin >> num)) {
                cout << "Invalid Integer, retry: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                success = true;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return num;
    }

    int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
        int num;
        bool valid = false;

        while (!valid) {
            num = getint(prompt);

            if (num < min || num > max) {
                if (errMes)
                    cout << errMes << ", retry: ";
                else
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
            }
            else {
                valid = true;
            }
        }

        return num;
    }

    int Utils::curYear() const {
        if (m_testMode) {
            return sdds_testYear;
        }
        else {
            auto now = std::chrono::system_clock::now();
            auto time = std::chrono::system_clock::to_time_t(now);
            std::tm* timeInfo = std::localtime(&time);
            return timeInfo->tm_year + 1900;
        }
    }



}
