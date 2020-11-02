/*
 * Stack.h
 *
 *  Created on: 27-Oct-2020
 *  Author: Varad Mashalkar
 * 	Repository Link :
 *  Version : 1
 *  Description : Stack Using linked organization
 *  */

#ifndef SRC_STACK_H_
#define SRC_STACK_H_

//Node
template <typename T>
class SNode
{
public:
	T data;
	SNode* next;
};

//Stack Class
template <typename T>
class Stack
{
private:
	SNode<T>* top;
	int count, max_size;
public:
	T data;				//temporary variables to store data
	Stack();			//Default Constructor
	Stack(int);			//Parameterized Constructor
	~Stack();			//Destructor
	bool isFull();		//method to identify isFull condition of queue
	bool isEmpty();		//method to identify isEmpty condition of queue
	void push(T);		//method to push data passed to it
	T pop();			//method to pop data from stack
	T peep();			//method to peep into stack
	void display();		//method to display stack from top to bottom
};

#endif /* SRC_STACK_H_ */
