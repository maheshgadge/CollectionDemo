/*
 * LinkedList.h
 *
 *  Created on: Oct 24, 2012
 *      Author: Mahesh Gadge
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Collection.h"
using namespace std;

class LNode{ // Start class LNode

protected:
	int element;
	LNode* next;

public:
	inline LNode(); // Default Constructor
	inline LNode(int anElement); // Parameterized Constructor
	inline int getElement();
	inline void setElement(int anElement);
	inline LNode* getNext();
	inline void setNext(LNode* aNode);
	~LNode();
	friend class LinkedList;

}; // End class LNode


class LinkedList:public Collection { // Start class LinkedList

protected:

	LNode* head;
	LNode* tail;
	int actualSize;

public:

	LinkedList(); // Default Constructor
	LinkedList(int listSize); // Parameterized Constructor
	LinkedList(const LinkedList& aList); // Copy Constructor
	virtual bool add(int anElement); // add method from abstract Collection class
	virtual bool remove(int anElement); // remove method from abstract Collection class
	virtual LinkedList& operator=(Collection& aCollection); // Assignment operator
	virtual int& operator[](const int index); // [] operator
	virtual LinkedList* copy(); // copy method from abstract Collection class
	~LinkedList(); // Destructor
	friend bool Collection::contains(int anInteger);
	friend void Collection::iterate(void(*funPtr)(int anElement));
}; // End class LinkedList

inline LinkedList::LinkedList(): Collection(0){ // Start Default Constructor

	head = NULL;
	tail = NULL;

	// Create a List of 10 nodes
	for(int index = 0; index < 10; index++){

		LNode* nodePtr = new LNode(0);
		if(head == NULL){
			head = nodePtr;
			tail = nodePtr;
			nodePtr = NULL;
		}
		else{
			tail->setNext(nodePtr);
			tail = nodePtr;
			nodePtr = NULL;
		}
	}
	actualSize = 10;

} // End Default Constructor


LinkedList::~LinkedList(){ // Start Destructor

	if(head != NULL){
		delete head;
	}
	tail = NULL;
	actualSize = 0;

} // End Destructor

inline LNode::LNode(){ // Start Default Constructor for LNode
	element = 0;
	next = NULL;
}// End Default Constructor for LNode

inline LNode::LNode(int anElement){ // Start parameterized Constructor
	element = anElement;
	next = NULL;
}// End parameterized Constructor

inline int LNode::getElement(){ // Start getElement

	return this->element;
} // End getElement

inline void LNode::setElement(int anElement){ // Start setElement

	this->element = anElement;
} // End setElement

inline LNode* LNode::getNext(){ // Start getNext

	return this->next;
} // End getNext

inline void LNode::setNext(LNode* aNode){ // Start setNext

	this->next = aNode;
} // End setNext

LNode::~LNode(){ // Start Node Destructor

	if(this->next != NULL){
		delete next;
	}
} // End Node Destructor





#endif /* LINKEDLIST_H_ */
