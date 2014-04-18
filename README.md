CollectionDemo
==============

Implementation of Collection types varArray and varLinkedList which doubles the size when needed


Problem Statement: 

For this project you must implement an abstract class called Collection in C++. This class defines
a protocol for a number of concrete Collection subclasses that will hold integer values. In C++ you can
define an abstract class by deferring the definition of one or more virtual member functions. Deferred
functions are called pure virtual member functions and are denoted by the =0 syntax in the function
declaration appearing in the class definition. Your abstract Collection class will defer the definition of
functions add(), remove(), the assignment operator operator=(), and the indexing operator operator[]().
Method add() takes as input two integers, denoting the element to be inserted in the collection and the
index position where the insertion should take place. This method is defined in the subclasses; however,
it will have no effect (except for printing an error message) in the Array subclass. Method remove() takes
as input an integer to be removed. No action is taken if the integer is not contained in the receiver or if
the receiver is an Array instance. Both methods return the modified receiver. Define the methods in such
a way that their invocations can be cascaded.
In addition, Collection will define concrete implementations of functions iterate(), which applies an
argument function to all elements of the receiver, and contains(), which checks whether an argument
integer is contained in the receiver. You are not allowed to redefine either function iterate() or contains()
in the two Collection subclasses below. In addition, Collection defines appropriate constructors, a virtual
destructor, and a virtual copy() method. Finally, Collection will have exactly one an integer data member
size , which holds the size of the receiver (i.e., the number of integer numbers stored therein). Collection
defines a public accessor for size ; however, only functions in the Collection class and its subclasses are
allowed to modify this data member.

In addition, you are required to code two concrete Collection subclasses named LinkedList
and varArray. Thus, this classes defines sequenceable collections that are stored contiguously but have variable size. The
initial size of instances of this class should be 10 elements. When the collection is full (i.e., when trying to
insert a fifth element), a new allocation is made of double the original size, the elements of the previous
collection are copied, and the old collection is deallocated.
