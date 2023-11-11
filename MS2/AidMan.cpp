#define _CRT_SECURE_NO_WARNINGS
#include "AidMan.h"
#include "Utils.h"
#include <iostream>
#include <cstring>

namespace sdds {

    AidMan::AidMan(const char* fileName) :mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database") {
        if (fileName && strlen(fileName) > 0) {
            filename = new char[strlen(fileName) + 1];
            strcpy(filename, fileName);
        }
        else {
            filename = nullptr;
        }
    }

    AidMan::~AidMan() {
        delete[] filename;
    }

    void AidMan::run() {
        //Utils utils; // Create an instance of the Utils class
        //int year, month, day;

        while (true) {
            std::cout << "Aid Management System" << std::endl;

            // Call getSystemDate to get the current date
            //utils.getSystemDate(&year, &month, &day);

            std::cout << "Date: 2023/12/09"<< std::endl;
            std::cout << "Data file: " << (filename ? filename : "No file") << std::endl;
            std::cout << "\n";

           unsigned int choice = menu();

            switch (choice) {
            case 0:
                std::cout << "Exiting Program!" << std::endl;
                return;
            case 1:
                std::cout << "\n****List Items****\n\n";
                break;
            case 2:
                std::cout << "\n****Add Item****\n\n";
                break;
            case 3:
                std::cout << "\n****Remove Item****\n\n";
                break;
            case 4:
                std::cout << "\n****Update Quantity****\n\n";
                break;
            case 5:
                std::cout << "\n****Sort****\n\n";
                break;
            case 6:
                std::cout << "\n****Ship Items****\n\n";
                break;
            case 7:
                std::cout << "\n****New/Open Aid Database****\n\n";
                break;
            default:
                std::cout << "Invalid option!" << std::endl;
            }
        }
    }

    unsigned int AidMan::menu() {
        return mainMenu.run();
    }
}
