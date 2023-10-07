/***********************************************************************
// OOP244 Workshop #3 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author   Cornel Barna, Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name  Hla Myint Myat                Date   31.9.23         Reason
***********************************************************************/

#include "Train.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds{
    
    void Train::initialize(){
        t_name = NULL;
        t_people = -1;
        t_time = -1;
    }
    
    bool Train::validTime(int value) const{
        int lastTwoDigits = value % 100;

        if(value > MIN_TIME && value < MAX_TIME && lastTwoDigits <= 59){
            return true;
        }
        return false;
    }
    
    bool Train::validNoOfPassengers(int value)const{
        
        if(value > 0 && value < MAX_NO_OF_PASSENGERS ){
            return true;
        }
        return false;
    }
    
    void Train::set(const char* name){
        delete[] t_name;
        t_name = NULL;
        if(name != NULL && *name != '\0'){
            t_name = new char[strlen(name)+1];
            strcpy(t_name,name);
        }
    }
    
    void Train::set(int noOfPassengers, int departure){
        if(validNoOfPassengers(noOfPassengers)){
            t_people = noOfPassengers;
        }else{
            t_people = -1;
        }
        
        if(validTime(departure)){
            t_time = departure;
        }else{
            t_time = -1;
        }
    }
    
    void Train::set(const char* name, int noOfPassengers, int departure){
        Train::set(name); // Corrected for setting t_name
        Train::set(noOfPassengers, departure); // Corrected for setting t_people and t_time
    }

    
    void Train::finalize(){
        delete[] t_name;
    }
    
    bool Train::isInvalid() const{
        if(t_name == NULL || t_people == -1 || t_time == -1){
            return true;
        }
        return false;
    }
    
    int Train::noOfPassengers() const{
        return t_people;
    }
    
    const char* Train::getName() const{
        return t_name;
    }
    
    int Train::getDepartureTime() const{
        return t_time;
    }

    void Train::display() const{
        if(isInvalid()){
            cout << "Train in an invalid State!" << endl;
        }else{
            cout << "NAME OF THE TRAIN:    " <<  t_name << endl;
            cout << "NUMBER OF PASSENGERS: "<<  t_people << endl;
            cout << "DEPARTURE TIME:       "<< t_time << endl;
        }
    }

    bool Train::load(int &value){
        int passenger = 0;
        cout << "Enter number of passengers boarding:" << endl;
        cout << "> ";
        cin >> passenger;
        
        int availableSpace = MAX_NO_OF_PASSENGERS - t_people;
    
        if (passenger <= availableSpace) {
            // Board all passengers
            t_people += passenger;
            value = 0;

            return true;
            
        } else {
            // Board as many passengers as possible and set remainingPassengers
            t_people = MAX_NO_OF_PASSENGERS;
            value = passenger - availableSpace;
            return false;
        }
        
    }
    
    bool Train::updateDepartureTime(){
        int newTime = 0;
        cout << "Enter new departure time:" << endl;
        cout << "> ";
        cin >> newTime;
        
        if(Train::validTime(newTime)){
            t_time = newTime;
            return true;
        }else{
            t_time = -1;
        }
        
        return false;
        
    }
    

    bool Train::loadPassengers(int num) {
            if (t_people + num <= MAX_NO_OF_PASSENGERS) {
                t_people += num;
                //cout << "Total Person on Train One:" << t_people << endl;
                return true;
            }
            return false;
    }
    
    bool Train::transfer(const Train& otherTrain){
        
        if(isInvalid() || otherTrain.isInvalid()){
            return false;
        }
        char name[150];
        strcpy(name,t_name);
        strcat(name,", ");
        strcat(name,otherTrain.t_name);
        set(name);
            // Attempt to board passengers from the other train to the current train
        int remainingPassengers = 0;
        bool success = loadPassengers(otherTrain.t_people);
        
            // Calculate the number of passengers left behind
        if (!success) {
          
            remainingPassengers = (otherTrain.t_people + t_people) - MAX_NO_OF_PASSENGERS;
             t_people = MAX_NO_OF_PASSENGERS;
            std::cout << "Train is full; " << remainingPassengers << " passengers of " << otherTrain.t_name << " could not be boarded!" << std::endl;
        
        }
        
            // Print a message if some passengers were left behind
    
        return true;
    }

    
}
