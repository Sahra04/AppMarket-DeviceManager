
#ifndef APPARRAY_H
#define APPARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "App.h"
#include "defs.h"

using namespace std;

class AppArray {
		
	public:
		//constructor
		AppArray();
		
		//deconstructor
		~AppArray();
		
		//member functions
		bool add(App*);
		//getter functions for class
		App* get(int) const;
		App* get(const string& title) const;
		//remove functions for class
		App* remove(const string& title);
		App* remove(int);
		//other
		int size() const;
		bool isFull() const;
	
	private:
		int numApps;
		App** apps;
};
#endif
