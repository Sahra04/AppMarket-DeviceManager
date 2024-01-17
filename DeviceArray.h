#ifndef DEVICEARRAY_H
#define DEVICEARRAY_H

#include "Device.h"
#include "defs.h"

using namespace std;

class DeviceArray {
		
	public:
		//constructor
		DeviceArray();
		
		//deconstructor
		~DeviceArray();
		
		//member functions

		//other
		bool add(Device*);
		Device* remove(const string& title);
		Device* remove(int);
		int size() const;
		bool isFull() const;
		//getter functions
		Device* get(int) const;
		Device* get(const string&) const;
	
	private:
	    //member variables
		int numDevices;
		Device** device;
};
#endif
