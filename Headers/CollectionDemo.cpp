/*
 * CollectionDemo.cpp
 *
 *  Created on: Oct 24, 2012
 *      Author: Mahesh Gadge
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#include "Collection.h"
#include "VarArray.h"
#include "LinkedList.h"

void elementPrint(int anElement); // global Function prototype declaration

void elementPrint(int anElement){ // Start global function elementPrint
	std::cout<< anElement << "  ";
}// End global function elementPrint

void Collection::iterate(void(*funPtr)(int anElement)){ // Start function iterate

	VarArray* pArray = dynamic_cast<VarArray*>(this);
	LinkedList* pList = dynamic_cast<LinkedList*>(this);

	if(pArray){
		int* array = pArray->arr;
		for(int index = 0; index < pArray->actualSize; index++){
			(*funPtr)(*array);
			array++;
		}
		std::cout << endl;
		array = NULL;
		pArray = NULL;
	}

	if(pList){

		LNode* nodePtr = pList->head;
		while(nodePtr != NULL){
			(*funPtr)(nodePtr->getElement());
			nodePtr = nodePtr->getNext();
		}
		std::cout << endl;
		pList = NULL;
	}
} // End function iterate

bool Collection::contains(int anInteger){ // Start method contains

	VarArray* pArray = dynamic_cast<VarArray*>(this);
	LinkedList* pList = dynamic_cast<LinkedList*>(this);

	if(pArray){
		bool flag = false;
		int* array = pArray->arr;
		for(int index = 0; index < pArray->size_; index++){
			if(array[index] == anInteger){
				flag = true;
				break;
			}
		}
		array = NULL;
		pArray = NULL;
		return flag;
	}

	if(pList){
		bool flag = false;
		LNode* nodePtr;
		nodePtr = pList->head;
		while(nodePtr != NULL){
			if(nodePtr->getElement() == anInteger){
				flag = true;
				break;
			}
			nodePtr = nodePtr->getNext();
		}
		nodePtr = NULL;
		pList = NULL;
		return flag;
	}

	return false;

} // End method contains

// code for method iterate here

// code for method iterate here

//*******************************Start VarArray Methods**************************************

VarArray::VarArray(const VarArray& anArray): Collection(anArray){ // Start Copy Constructor for VarArray anArray.size_

	//size_ = anArray.size_;
	arr = new int[anArray.actualSize];
	actualSize = anArray.actualSize;
	int* arrPtr = arr;
	int* anArrayPtr = anArray.arr;

	for(int index = 0; index < actualSize; index++ ){
		*arrPtr = *anArrayPtr;
		arrPtr++;
		anArrayPtr++;
	}

	arrPtr = NULL;
	anArrayPtr = NULL;

}// End Copy Constructor for VarArray

VarArray* VarArray:: copy(){ // Start copy method for VarArray

	return (new VarArray(*this));

} // End copy method for VarArray

bool VarArray::add(int anElement){ // Start VarArray add

	bool flag = false;

	if(this->getSize() < actualSize){ // size_
		int* arrPtr = arr;
		for(int index = 0; index < actualSize; index++){
			if((*arrPtr) == 0){
				(*arrPtr) = anElement;
				flag = true;
				//size_++;
				this->setSize(this->getSize() + 1);
				break;
			}
			else{
				arrPtr++;
			}
		}
		return flag;
	}
	else{

		// Create an Array of Double size
		int* tempArrPtr = arr;
		int* aPtr = arr;
		int tempActualSize = actualSize;
		actualSize = actualSize * 2;
		arr = new int[actualSize];
		int* arrPtr = arr;

		// Assign the elements from the earlier array to the new array
		for(int index = 0; index < tempActualSize; index++){
			(*arrPtr) = (*tempArrPtr);
			arrPtr++;
			tempArrPtr++;
		}
		// Input the new element
		//arrPtr++;
		(*arrPtr) = anElement;
		//size_++;
		this->setSize(this->getSize() + 1);

		flag = true;
		// Deallocate the earlier space
		tempArrPtr = NULL;
		arrPtr = NULL;
		delete[]aPtr;
		return flag;

	}
	return flag;
}// End VarArray add

bool VarArray:: remove(int anElement){ // Start VarArray remove

	int tempSize;
	int* arrPtr = arr;
	bool flag = false;

	for(tempSize = 0; tempSize < this->getSize(); tempSize++){//size_
		if((*arrPtr) == anElement){
			*arrPtr = 0;
			flag = true;
			break;
		}
		else{
			arrPtr++;
		}
	}

	if(!flag){
		arrPtr = NULL;
		return flag;
	}
	else{

		if(tempSize == this->getSize() -1){ // Element removed is last element of array size_ - 1
			//next = NULL;
			arrPtr = NULL;
			//size_--;
			this->setSize(this->getSize() - 1);
			return flag;
		}
		else{ // element removed is a middle element

			int* next = arrPtr;
			next++;

			for(int index = tempSize; index < this->getSize() ; index++){ //size_
				if(next == NULL){
					(*arrPtr) = 0;
				}
				else{
					(*arrPtr) = int(*next);
					(*next) = 0;
				}

				arrPtr = next;
				if(index == this->getSize() - 2){ //size_- 2
					next = NULL;
				}
				else{
					next++;
				}
			}
			//size_--;
			this->setSize(this->getSize() - 1);
			arrPtr = NULL;
			next = NULL;
			return flag;
		}
	}
	return flag;

} // End VarArray remove

VarArray& VarArray::operator=(Collection& aCollection){ // Start operator =

	VarArray* anArray = &(dynamic_cast<VarArray&> (aCollection));

	//size_ = anArray->size_;
	this->setSize(anArray->getSize());
	actualSize = anArray->actualSize;
	if(arr != NULL){
		delete[] arr;
		arr = new int[actualSize];
		int* arrPtr = arr;
		int* anArrayPtr = anArray->arr;
		for(int index = 0; index < actualSize; index++){

			(*arrPtr) = (*anArrayPtr);
			arrPtr++;
			anArrayPtr++;
		}

		arrPtr = NULL;
		anArrayPtr = NULL;
	}
	return *this;
} // End operator =

int& VarArray::operator[](const int index){ // Start operator []

	if(index < 0 || index > this->getSize() - 1){//size_ -1
		std::cout<< "Subscript out of bounds" << endl;
		exit(1);
	}
	else{
		return arr[index];
	}

} // End operator []


//*******************************End VarArray Methods****************************************
//*******************************Start LinkList Methods****************************************

LinkedList::LinkedList(const LinkedList& aList): Collection(aList){ // Start Copy Constructor for LinkedList aList.size_

	//size_ = aList.size_;
	head = NULL;
	tail = NULL;
	actualSize = aList.actualSize;

	LNode* nodePtr = aList.head;
	LNode* current;
	LNode* previous;
	while(nodePtr != NULL){

		if(head == NULL){
			head = new LNode(nodePtr->getElement());
			tail = head;
			previous = head;
		}
		else{
			current = new LNode(nodePtr->getElement());
			previous->setNext(current);
			previous = current;
			current = NULL;
			tail = previous;
		}
		nodePtr = nodePtr->getNext();
	}

	previous = NULL;
	nodePtr = NULL;
	current = NULL;

} // End Copy Constructor for Linked List

LinkedList* LinkedList::copy(){ // Start Copy method for LinkedList

	return (new LinkedList (*this));
} // End Copy method for LinkedList

bool LinkedList::add(int anElement){ // Start LinkedList add

	if(this->getSize() < actualSize){//size_
		LNode* nodePtr;
		nodePtr = head;
		while(nodePtr->getElement() != 0){
			nodePtr = nodePtr->getNext();
		}
		nodePtr->setElement(anElement);
		//size_++;
		this->setSize(this->getSize() + 1);
		nodePtr = NULL;
	}
	else{

		LNode* tempHead;
		LNode* nodePtr;
		tempHead = head;
		nodePtr = head;
		head = NULL;
		tail = NULL;
		actualSize = actualSize * 2;

		for(int index = 0; index < actualSize; index++){ // Start creates list of double size

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
		}// End creates list of double size

		LNode* newListPtr;
		newListPtr = head;

		while(nodePtr != NULL){ // insert elems of old list into new List

			newListPtr->setElement(nodePtr->getElement());
			newListPtr = newListPtr->getNext();
			nodePtr = nodePtr->getNext();
		}// insert elems of old list into new List


		if(newListPtr != NULL){ // insert the new element
			//newListPtr = newListPtr->getNext();
			newListPtr->setElement(anElement);
			//size_++;
			this->setSize(this->getSize() + 1);
		}// insert the new element

		nodePtr = NULL;
		newListPtr = NULL;
		if(tempHead != NULL){
			delete tempHead;
		}
	}
	return true;
} // End LinkedList add

bool LinkedList:: remove(int anElement){

	LNode* current = head;
	LNode* aNext;

	while(current->getElement() != anElement && current->getNext() != NULL){
		current = current->getNext();
	}
	if(current->getNext() == NULL){ // reached the end (actual size)
		current = NULL;
		return false;
	}
	else if (current->getElement() == anElement){
		aNext = current->getNext();

		while(aNext != NULL){
			current->setElement(aNext->getElement());
			current = aNext;
			aNext->setElement(0);
			aNext = aNext->getNext();
		}

		aNext = NULL;
		current = NULL;
		//size_--;
		this->setSize(this->getSize() - 1);
		return true;
	}

	if(current != NULL){
		current = NULL;
	}
	return false;
}

LinkedList& LinkedList::operator=(Collection& aCollection){ // Start = operator


	LinkedList* aList = &(dynamic_cast<LinkedList&> (aCollection));

	if(head != NULL){
		delete head;
	}
	tail = NULL;
	this->setSize(aList->getSize()); //size_ = aList->size_;
	head = NULL;
	actualSize = aList->actualSize;

	LNode* nodePtr = aList->head;
	LNode* current;
	LNode* previous;
	while(nodePtr != NULL){

		if(head == NULL){
			head = new LNode(nodePtr->getElement());
			tail = head;
			previous = head;
		}
		else{
			current = new LNode(nodePtr->getElement());
			previous->setNext(current);
			previous = current;
			current = NULL;
			tail = previous;
		}
		nodePtr = nodePtr->getNext();
	}

	previous = NULL;
	nodePtr = NULL;
	current = NULL;

	return *this;
} // End = operator

int& LinkedList::operator[](const int index){ // Start operator []

	if(index < 0 || index > this->getSize() - 1){ //size_ - 1
		std::cout<<"Subscript out of range" <<endl;
		exit(1);
	}
	else{
		LNode* nodePtr = head;
		int loopIndex = 0;
		while(loopIndex != index){
			nodePtr = nodePtr->getNext();
			loopIndex++;
		}
		return nodePtr->element;
	}


} // End operator []

//*******************************End LinkList Methods****************************************

int main(){ // Start Function main


	Collection* pCollection = new LinkedList;
	pCollection->add(4);
	pCollection->add(5);
	pCollection->add(6);
	pCollection->remove(5);
	pCollection->contains(4);
	(*pCollection)[1] = 3; // [] operator as an l-value
	pCollection->iterate(&elementPrint); // use of iterate function
	int a = (*pCollection)[1]; // use as an r-value
	Collection* aList = pCollection->copy(); // Copy Method
	aList->add(10);
	(*pCollection) = (*aList); // Assignment Operator
	delete pCollection;
	delete aList;


	Collection* aCollection = new VarArray;
	aCollection->add(4);
	aCollection->add(5);
	aCollection->add(6);
	aCollection->remove(5);
	(*aCollection)[1] = 5;
	int b = (*aCollection)[1];
	Collection* aArray = aCollection->copy();
	aArray->add(10);
	(*aCollection) = (*aArray);
	aCollection->contains(10);
	aCollection->iterate(&elementPrint);
	delete aArray;
	delete aCollection;


	return 0;

} // End Function main



