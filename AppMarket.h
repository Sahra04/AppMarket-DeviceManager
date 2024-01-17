#ifndef APPMARKET_H
#define APPMARKET_H

#include <iostream>
#include <string>
#include <iomanip>
#include "AppArray.h"

using namespace std;

class AppMarket{

    public:
        //constructor
        AppMarket();

        //deconstructor
        ~AppMarket(); 

        //member functions
        bool addApp(const string& title,const string& description,const string& icon);
        void deleteApp(int index); 
        //getter function to get specific app at index
        App* getApp(int index) const; 
        //printing functions
        void printApps() const;
        void printAppDetails(int index) const; 

    private:
        //member variables
        AppArray* arr;

};
#endif 