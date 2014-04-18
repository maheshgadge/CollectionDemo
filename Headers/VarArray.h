/*
 * VarArray.h
 *
 *  Created on: Oct 25, 2012
 *      Author: Mahesh Gadge
 */

#ifndef VARARRAY_H_
#define VARARRAY_H_

#include "Collection.h"
using namespace std;

class VarArray : public Collection{ // Start class VarArray

protected:
	int* arr;
	int actualSize;

public:
	VarArray();
	VarArray(const VarArray& anArray); // Copy constructor
	virtual bool add(int anElement); // add method from abstract Collection class
	virtual bool remove(int anElement); // remove method from abstract Collection class
	virtual VarArray& operator=(Collection& aCollection);
	virtual int& operator[](const int index);
	virtual VarArray* copy();
	~VarArray();
	friend bool Collection::contains(int anInteger);
	friend void Collection::iterate(void(*funPtr)(int anElement));
}; // End class VarArray

inline VarArray::VarArray() : Collection(0){ // Start Default Constructor

	arr = new int[10];
	for(int index = 0; index < 10; index++){
		arr[index] = 0;
	}
	actualSize = 10;

}  // End Default Constructor


VarArray:: ~VarArray(){ // Start Destructor

	delete[] arr;
	actualSize = 0;

} // End Destructor


#endif /* VARARRAY_H_ */
