#define _CRT_SECURE_NO_WARNINGS
#include "AidMan.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include <iomanip>
#include <string>
#include "Perishable.h"
#include "Item.h"
using namespace std;

namespace sdds {

    AidMan::AidMan() :mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database"),filename(nullptr),num_items(0) {};

    AidMan::~AidMan() {
        delete[] filename;
        deallocate();
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
            //std::cout << "\n";
            
                std::cout << "---------------------------------" << endl;

           unsigned int choice = menu();
           int flag = 0;
           if (choice != 0 && filename == nullptr) {
               std::cout << "\n****New/Open Aid Database****\n";
               std::cout << "Enter file name: ";
               char newFileName[256];
               std::cin >> newFileName;
               delete[]filename;
               filename = new char[strlen(newFileName) + 1];
               strcpy(filename, newFileName);
               flag = 1;
               loadDataFromFile(filename);
               std::cout << num_items-1 << " records loaded!"<<std::endl;
               std::cout << std::endl;
               
           }
           if (!flag) {
               switch (choice) {
               case 0:
                   std::cout << "Exiting Program!" << std::endl;
                   return;
               case 1:
                   std::cout << "\n****List Items****\n";
                   listItems();
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
    }

    void AidMan::listItems()const
    {
        // Display the header
        std::cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;

        std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

        // Display each item's information
        for (int i = 0; i < num_items-1; ++i) {
            if (items[i]) {
                std::cout<< std::setfill(' ') << std::setw(4) << i+1 << " | ";
                items[i]->linear(1);
                items[i]->display(std::cout);
                std::cout << std::endl;
            }
        }
        std::cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
        
        // Prompt the user to enter a row number or press Enter to continue
        std::cout << "Enter row number to display details or <ENTER> to continue:" << std::endl;
        std::cout << "> ";

        // Read the user input
        //std::string userInput;
        //int userInput;
        //std::getline(std::cin, userInput);
        //std::cin >> userInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        char firstChar = cin.peek();
        if (firstChar == '\n') {
            std::cout << endl;
            cin.ignore();
        }
        else if (std::isdigit(firstChar)) {
            
            // Convert the character to an integer
            int selectedIndex = firstChar - '0';

            if (selectedIndex >= 1 && selectedIndex <= num_items) {
                if (items[selectedIndex - 1] != nullptr) {
                    // Valid pointer, safe to dereference
                    items[selectedIndex-1]->linear(0);
                    items[selectedIndex - 1]->display(std::cout);
                }
            }
            std::cout << endl<<endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        
        
    }

    unsigned int AidMan::menu() {
        return mainMenu.run();
    }

    void AidMan::loadDataFromFile(const char* filename) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        int index = 0;
        while (index < sdds_max_num_items && !file.eof()) {
            

            iProduct* newItem = nullptr;

            if (index == 0 || index == 4 || index == 5) {
                newItem = new Perishable;
            }
            else {
                newItem = new Item;
            }
            

            if (newItem) {
                
                newItem->load(file);

                // Add the item to the array
                items[index++] = newItem;
                
                num_items++;
            }

        }

        file.close();
    }

    void AidMan::deallocate() {
        for (int i = 0; i < 7; ++i) {
            delete items[i];  // Use delete, not delete[]
            items[i] = nullptr;
        }

        //delete items;  
        //items = nullptr;
        num_items = 0;
    }
}