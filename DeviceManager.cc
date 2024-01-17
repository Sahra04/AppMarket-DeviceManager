
#include "DeviceManager.h"

DeviceManager::DeviceManager(): arr(new DeviceArray()) {

}

//making sure to delete everything once program ends
DeviceManager:: ~DeviceManager() {
    delete arr;
}

bool DeviceManager:: addDevice(const string& name,const string& deviceType,const string& os){
    bool x = false; 
    if(!arr->isFull()){
        Device* dev = new Device(name, deviceType, os); 
        arr->add(dev); 
        x = true; 
    }else{
        x = false; 
    }
    return x; 

}

void DeviceManager:: deleteDevice(int index){
    Device* remove = arr->remove(index); 
    if(remove == nullptr){
        cout<< "error device is not found or could not be removed"<<endl; 
    }else{
        cout<<"the device: "<<remove->getName()<< " has been deleted"<<endl;
        delete remove; 
    }

}

//creating a deep copy to make sure if original device is deleted, then the cloned device is still present
//also added error checking to make sure user is inputting valid values
void DeviceManager:: cloneDevice(int cloneTo, int cloneFrom){
    if ((cloneFrom >= 0 ) && (cloneFrom < arr->size()) && (cloneTo >= 0) && (cloneTo < arr->size())){
        Device* clonedDev =  arr->get(cloneFrom);
        Device* newClone = arr->get(cloneTo);
        newClone->cloneApps(*clonedDev);; 
        cout<<"the device: "<<clonedDev->getName()<< " has been cloned"<<endl;
        
    }else{
        cout<<"invalid index "<<endl; 
    }
}

Device* DeviceManager:: getDevice(int index) const {
	return arr->get(index); 
}

void DeviceManager:: printDevices() const{
    for (int i = 0; i < arr->size(); ++i){
        cout<<i<<":"<<endl; 
        (arr->get(i))->print(); 
    }
    cout<<endl;

}


//getting the individual device using the get function and then using the device printWithApps function to printDeviceDetails
void DeviceManager:: printDeviceDetails(int index) const{
    cout<<endl;
    (arr->get(index))->printWithApps(); 
    cout<<endl;
    
} 