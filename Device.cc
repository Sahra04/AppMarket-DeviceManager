

#include "Device.h"

//member initialization new technique used here 
Device::Device(const string& name,const string& deviceType,const string& os): name(name), deviceType(deviceType), os(os), arr(new AppArray()) {

}

//making sure to delete everything when program ends
Device:: ~Device(){
    delete arr; 
}

string Device:: getName() const{
    return name; 

}

bool Device:: equals(const string& pName) const{
    bool x = false; 
    if(pName == name){
        x = true; 
    }
    return x; 

}

bool Device:: addApp(const App& app){
    bool x = false; 
    if (arr->isFull()) {
        x = false;  
    }else{
        App* a = new App(app.getTitle(), app.getDescription(), app.getIcon());
        arr->add(a);
        x = true; 

    }
    return x; 

}

bool Device:: deleteApp(const string& pTitle){
    bool x = false; 
    App* remove = arr->remove(pTitle);
    if(remove != nullptr){
        x = true; 

    }
    delete remove; 
    return x; 

}

//creating a deep copy of parameter device apps and then adding it to the AppArray
void Device:: cloneApps(Device& device) {
    delete arr;  
    arr = new AppArray();
    for (int i = 0; i < device.arr->size(); ++i){
        App* app = new App(*device.arr->get(i));
        arr->add(app);     
    }



}

int Device:: numApps() const{
    int size = arr->size();
    return size; 

}

void Device :: print() const{
    cout << "Device: "<<name<<endl;
    cout << "Device Type: "<< deviceType <<endl;
    cout << "OS: "<<os<<endl;
    cout<<"Apps: "<<numApps()<<endl;
    cout<<endl; 

}

void Device :: printWithApps() const {
    print();
    for (int i = 0; i < arr->size(); ++i){
        (arr->get(i))->printWithIcon();
    } 
    cout<<endl;  

}