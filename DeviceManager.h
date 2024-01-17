#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <iostream>
#include <string>
#include <iomanip>
#include "DeviceArray.h"

using namespace std;

class DeviceManager{
    public: 
        //constructor
        DeviceManager(); 
        //deconstructor
        ~DeviceManager(); 

        //member functions
        bool addDevice(const string& name,const string& deviceType,const string& os);
        void deleteDevice(int index); 
        void cloneDevice(int cloneTo, int cloneFrom); 
        //getter function
        Device* getDevice(int index) const; 
        //printing function 
        void printDevices() const; 
        void printDeviceDetails(int index) const; 



    private: 
        DeviceArray* arr; 

        


};
#endif