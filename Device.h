#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "AppArray.h"

using namespace std;

class Device{
    public:
        //constructor
        Device(const string& name,const string& deviceType,const string& os);
        
        //deconstructor
        ~Device();

        //member functions 

        //getter function
        string getName() const; 
        //other
        bool equals(const string& pName) const; 
        bool addApp(const App& app); 
        bool deleteApp(const string& pTitle); 
        void cloneApps(Device& device); 
        int numApps() const; 
        //printing functions
        void print() const;
        void printWithApps() const; 



    private: 
        //member variables
        string name; 
        string deviceType; 
        string os; 
        AppArray* arr; 



};
#endif