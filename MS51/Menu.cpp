#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <string>
#include <cstring>
#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

namespace sdds {

    Menu::Menu(const char* content) {
        int options=0;
        for (size_t i = 0; i < strlen(content); i++) {
            if (content[i] == '\t') {
                options++;
            }
        }
        
        if (content&&options<=15) {
            menuContent = new char[strlen(content) + 1];
            strcpy(menuContent, content);
            numOptions = options+1;
        }
        else {
            menuContent = nullptr;
            numOptions = 0;
        }
    }

    Menu::~Menu() {
        delete[] menuContent;
    }

    unsigned int Menu::run() {
        if (!menuContent) {
            std::cout << "Invalid Menu!" << std::endl;
            return 0;
        }

        while (true) {
            
            size_t optionNum = 1;
            std::istringstream stream(menuContent);
            std::string token;

            while (std::getline(stream, token, '\t')) {
                std::cout << optionNum << "- " << token << std::endl;
                optionNum++;
            }

            std::cout << "---------------------------------" << std::endl;
            std::cout << "0- Exit" << std::endl;

            unsigned int choice;
            do {
                std::cout << "> ";
                std::cin >> choice;

                if (std::cin.fail()) {
                    std::cout << "Invalid Integer, retry: ";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cin >> choice;
                }
                else if (choice < 0 || choice > numOptions) {
                    std::cout << "Value out of range [0<=val<=" << numOptions << "]: ";
                    std::cin >> choice;
                }
            } while (choice < 0 || choice > numOptions);

            if (choice == 0) {
                return choice; 
            }

            return choice;
        }

        
    }
}