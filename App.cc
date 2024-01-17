
#include "App.h"

App::App(const string& title,const string& description, const string& icon){
	this->title = title; 
    this->description = description;
    this->icon = icon; 
}


App:: ~App(){
}

bool App :: equals(const string& pTitle) const{
    bool x = false; 
    if(title == pTitle){
        x = true; 
    }
    return x; 
}

void App::print() const{
    cout << "Title: "<< title << endl;
    cout << "Description: "<< description << endl;
    cout<<endl; 

}

void App::printWithIcon() const{
    print();
    cout << "Icon: "<< icon <<endl;
    cout<<endl; 

}

string App:: getTitle() const {
    return title;
}

string App:: getDescription() const{
    return description; 
}

string App:: getIcon() const{
    return icon;
}