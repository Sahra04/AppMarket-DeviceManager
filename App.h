#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class App{

    public:
        //constructor
        App(const string& title,const string& description, const string& icon); 
        
        //deconstructor
        ~App(); 
           
   
        //member functions

        //getter functions for when I make a copy of the App in Device class for the addApp() function
        string getTitle() const; 
        string getDescription() const;
        string getIcon() const;
        //to see if 2 app titles are equal
        bool equals(const string& pTitle) const; 
        //printing app
        void print() const; 
        void printWithIcon() const; 

        

    private:
        string title; 
        string description; 
        string icon; 


};
#endif

