/*
 * Collection.h
 *
 *  Created on: Oct 24, 2012
 *      Author: Mahesh Gadge
 */

#ifndef COLLECTION_H_
#define COLLECTION_H_

#include<iostream>
using namespace std;

class Collection{ // Start class Collection

private:
	int size_;
protected:
	//int size_;
	void setSize(int aSize);
public:
	inline Collection(); //Default constructor
	inline Collection(int aSize);
	inline Collection(const Collection& aCollection); // Copy Constructor
	virtual bool add(int anElement) = 0;
	virtual bool remove(int anElement) = 0;
	virtual Collection& operator=(Collection& aCollection) = 0; // Assignment Operator
	virtual int& operator[](const int index) = 0;
	virtual Collection* copy() = 0;
	bool contains(int anInteger);
	void iterate(void(*funPtr)(int anElement)); // Applies a function to the receiver
	int getSize(); // Public accessor for size_
	virtual ~Collection(); // virtual Destructor


}; // End class Collection


inline Collection::Collection(){ // Start Default Constructor
	size_ = 0;
} // End default Constructor

inline Collection::Collection(int aSize){ // Start Parameterized constructor

	size_ = aSize;
} // End Parameterized constructor

inline Collection::Collection(const Collection& aCollection){ // Start Copy Constructor

	this->size_ = aCollection.size_;

} // End Copy Constructor

Collection::~Collection(){ // Start Virtual Destructor

	size_ = 0;
} // End Virtual Destructor

int Collection::getSize(){ // Start int size()

	return size_;
} // End int size()

void Collection::setSize(int aSize){ // Start void size(int)

	size_ = aSize;
} // End void size(int)

#endif /* COLLECTION_H_ */
