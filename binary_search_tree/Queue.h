/*
 * Author : Varad Mashalkar
 * Lab : Data Structures and algorithms
 * Version : 1
 * File Description : ADT of Queue using linked organization.
 */


#ifndef SRC_QUEUE_H_
#define SRC_QUEUE_H_

//Node
template <typename T>
class QNode
{
public:
	T data;
	QNode* next;
};

//Queue class
template <typename T>
class Queue
{
private:
	QNode<T>* front;
	QNode<T>* rear;
public:
	T data;				//Data member for internal transaction
	Queue();			//Constructor
	~Queue();			//Destructor
	bool isEmpty();		//Method to identify isEmpty condition
	void enqueue(T);	//Method to enqueue data
	T dequeue();		//Method to dequeue data
	void display();		//Method to display queue
	int size();
};

#endif /* SRC_QUEUE_H_ */
