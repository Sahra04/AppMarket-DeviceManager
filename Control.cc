
#include "Control.h"
#include "DeviceManager.h"
#include <limits>
#include <vector>

using namespace std;
#define NUM_DEVICES 4
#define NUM_OS 5
extern const  string DEVICETYPE[NUM_DEVICES];
extern const  string OS[NUM_OS];
extern const string deviceNames[5];
extern int deviceType[5];
extern int os[5];
extern const string appTitles[10];
extern const string descriptions[10];
extern const string icons[10];



void Control::launch(){

    vector<string> menu ={
        "Print apps",
        "Print devices",
        "Print device apps",
        "Add apps to device", 
        "Delete app",
        "Delete device",
        "Clone device"
    };

    initApps();
    initDevices();
    int choice = -1;

    while (choice!= 0){
        view.menu(menu, choice);
        switch(choice){
            case 1: printApps(); break;
            case 2: printDevices(); break;
            case 3: printDeviceDetails(); break;
            case 4: addAppsToDevice(); break;
            case 5: deleteApp(); break;
            case 6: deleteDevice(); break;
            case 7: cloneDevice(); break;
        }
    }
    cout<<"exiting program!!!"<<endl;
}

void Control::initApps(){
    cout<<"Initializing apps..."<<endl;
    for (int i = 0; i < 10; ++i){
        appMarket.addApp(appTitles[i], descriptions[i], icons[i]);
    }
    cout<<"Apps initialized!"<<endl;
}

void Control::initDevices(){
    cout<<"Initializing devices..."<<endl;
    for (int i = 0; i < 5; ++i){
        deviceManager.addDevice(deviceNames[i], DEVICETYPE[deviceType[i]], OS[os[i]]);
    }
    cout<<"Devices initialized!"<<endl;
}

void Control::printApps(){
    cout<<"Printing apps..."<<endl;
    appMarket.printApps();
    cout<<"Apps printed!"<<endl;
}

void Control::printDevices(){
    cout<<"Printing devices..."<<endl;
    deviceManager.printDevices();
    cout<<"Devices printed!"<<endl;
}

void Control::printAppDetails(){
    printApps();
    int index;
    view.getNumber(index);
    cout<<"Printing app details..."<<endl;
    appMarket.printAppDetails(index);
}

void Control::printDeviceDetails(){
    printDevices(); 
    int index; 
    view.getNumber(index); 
    cout<<"Printing device details..."<<endl;
    deviceManager.printDeviceDetails(index);
    
}

//purpose: to add apps to device that user chooses
//added while loops to continue asking and also checking for errors
void Control::addAppsToDevice(){
    bool x = true; 
    printDevices(); 
    int index; 
    while(x){
        cout<<"please choose a device" <<endl;
        view.getNumber(index);
        Device* dev = deviceManager.getDevice(index); 
        if(dev!= nullptr){
            x = false;
        }else{
             cout<< "No such device exists." << endl;
        }
       
    }
    int amount; 
    cout << "How many apps do you want to install: ";
    cin >> amount;
    int counter = 0; 
    printApps();
    while(counter < amount){
        int index2; 
        cout<<"which app would you like to install? " <<endl; 
        view.getNumber(index2); 
        App* install =  appMarket.getApp(index2); 
        if(install  == nullptr){
            cout<<"app not found"<<endl;
            continue; 
   
        }
        cout << "Adding apps to device..." << endl; 
        (deviceManager.getDevice(index))->addApp(*install); 
        counter++;

    }
 
}

void Control::deleteApp(){
    int index; 
    printApps(); 
    cout<<"Which app would you like deleted? "<<endl;
    view.getNumber(index); 
    appMarket.deleteApp(index); 

}

void Control::deleteDevice(){
    int index; 
    printDevices();
    cout<<"Which Device would you like deleted? "<<endl; 
    view.getNumber(index);
    deviceManager.deleteDevice(index);
 
   
}

void Control::cloneDevice(){
    printDevices(); 
    int cloneFrom; 
    cout<<"Which Device would you like to clone from"<<endl;
    view.getNumber(cloneFrom); 
    int cloneTo; 
    cout<<"now choose a Device to clone to "<<endl; 
    view.getNumber(cloneTo); 
    deviceManager.cloneDevice(cloneTo, cloneFrom);

   
}

#define NUM_DEVICES 4
#define NUM_OS 5

const  string DEVICETYPE[NUM_DEVICES]={"PHONE", "TABLET", "LAPTOP", "DESKTOP"};
const  string OS[NUM_OS] = {"ANDROID", "IOS", "WINDOWS", "MACOS", "LINUX"};

const string deviceNames[5] = {"My Android Phone", "My iPad", "My Gaming Desktop", "My Macbook", "My Linux Laptop"};
int deviceType[5] = {0, 1, 3, 2, 2};
int os[5] = {0, 1, 2, 3, 4};

const string appTitles[10] = {"Flappy Birds", "Office", "Snapchat", "VirtualBox", "Grand Theft Auto 6", "Messages", "Netflix", "iTunes", "Photoshop", "Gimp"};
const string descriptions[10] = {"Video game", "Office apps", "Social Media", "OS Virtualization", "AAA Game", "Text Messages", "Video Streaming", "Music and Video Streaming", "Editing", "Image Editing"};

const string icons[10] = {
R"(
  ___
 / _ \
| (_) |
 \___/
)",

R"(
  ,--.
 /  0 \
|   .  |
 \___/
)",

R"(
  ,--.
 /  0 \
|   |  |
 \___/
)",

R"(
  ,--.
 /  0 \
|   |  |
 \__O/
)",

R"(
   /\
  /  \
 |    |
 |----|
 |    |
 |----|
)",

R"(
   /\
  /  \
 | [] |
 |----|
 |    |
 |----|
)",

R"(
 ______
/ 0  0 \
|    ∆   |
 \_____/
)",

R"(
  ____
 /  00\
|    0 |
|______|
)",

R"(
   ,--.
  / 00\
 |  |  |
  \__/
)",

R"(
  ,--,
 /    \
|  ☏   |
 \    /
  '--'
)"
};
