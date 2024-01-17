#include "DeviceArray.h"

DeviceArray::DeviceArray(){
	numDevices = 0;
	device = new Device*[MAX_ARRAY];
}


DeviceArray::~DeviceArray(){
	for(int i=0;i<numDevices;i++){
        delete device[i]; 
    }
	delete [] device;
}


bool DeviceArray::add(Device* dev){
    bool x = false; 
	if (isFull()){
        x = false; 
    }
    else if(numDevices < MAX_ARRAY){
        device[numDevices] = dev; 
        ++numDevices; 
        x = true; 
    }else{
        x = false; 

    }
    return x; 
}

Device* DeviceArray::remove(const string& title){
	int index = 0;

	while (index < numDevices){
		if (device[index]->equals(title)){ break; }
		++index;
	}

	if (index >= numDevices) return NULL;

	Device* goner;
	goner = device[index];

	while (index < numDevices-1){
		device[index] = device[index+1];
		++index;
	}
	--numDevices;
	return goner;
}

Device* DeviceArray::remove(int i){
	if (i < 0 || i >= numDevices) return nullptr;
	Device* goner = device[i];

	while (i < numDevices-1){
		device[i] = device[i+1];
		++i;
	}
	--numDevices;
	return goner;
}

Device* DeviceArray::get(const string& title) const{
	for (int i = 0; i < numDevices; ++i){
		if (device[i]->equals(title)){
			return device[i];
		}
	}
	return nullptr;
}


Device* DeviceArray::get(int i) const {
	Device* dev =  device[i]; 
	if (i < 0 || i >= numDevices){
		dev = nullptr; 
	}
	return dev; 
}

bool DeviceArray::isFull() const{
	return numDevices >= MAX_ARRAY;
}

int DeviceArray::size() const{
	return numDevices;
}