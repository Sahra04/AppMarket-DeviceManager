
#include "AppMarket.h"

AppMarket::AppMarket(): arr(new AppArray()){

}

AppMarket:: ~AppMarket() {
    delete arr; 

}

bool AppMarket:: addApp(const string& title,const string& description,const string& icon){
    bool x = false; 
    if(arr->isFull()){
        x = false; 
    }else {
        App* a = new App(title, description, icon); 
        arr->add(a); 
        x = true; 
    }
    return x; 
}

void AppMarket:: deleteApp(int index){
    App* remove = arr->remove(index); 
    if(remove == nullptr){
        cout<< "error device is not found or could not be removed"<<endl;
       
    }else{
        cout<<"the app: "<<remove->getTitle()<< " has been deleted"<<endl;
        delete remove; 
    }
}

App* AppMarket:: getApp(int index) const{
    return arr->get(index); 

}

void AppMarket:: printApps() const{
    for (int i = 0; i < arr->size(); ++i){
         cout<<i<<":"<<endl; 
        (arr->get(i))->print(); 
        
    }   

}

void AppMarket:: printAppDetails(int index) const{
    cout<<endl; 
    (arr->get(index))->printWithIcon(); 
    cout<<endl; 

}
