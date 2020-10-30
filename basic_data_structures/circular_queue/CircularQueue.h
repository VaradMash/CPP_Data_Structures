/*
 * CircularQueue.h
 *
 *  Created on: 27-Oct-2020
 *      Author: varadm
 */

#ifndef SRC_CIRCULARQUEUE_H_
#define SRC_CIRCULARQUEUE_H_

#include <iostream>
using namespace std;

template <typename T>
class CQNode
{
public:
	T data;
	CQNode<T>* next;
};

template <typename T>
class CircularQueue
{
private:
	CQNode<T>* front;		//front pointer
	CQNode<T>* rear;		//rear pointer
public:
	T data;				//Data member for internal transaction
	CircularQueue();	//Constructor
	~CircularQueue();	//Destructor
	bool isEmpty();		//Method to determine whether queue is empty
	void enqueue(T);	//method to add data to queue
	T dequeue();		//method to serve item from Queue
	void display();		//Method to display items in queue
};

#endif /* SRC_CIRCULARQUEUE_H_ */
