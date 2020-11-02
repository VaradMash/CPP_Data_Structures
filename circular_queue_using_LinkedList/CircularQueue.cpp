#include <iostream>
#include "CircularQueue.h"
using namespace std;

// Constructor
template <typename T>
CircularQueue<T>::CircularQueue()
{
	/*
	 * Input : None
	 * Utility : Allocate memory location to object.
	 * Output : None
	 */
	front = NULL;
	rear = NULL;
}

// Destructor
template <typename T>
CircularQueue<T>::~CircularQueue()
{
	/*
	 * Input : None
	 * Utility : Free memory locations alloted to object.
	 * Output : None
	 */
	CQNode<T>* temp = front;
	while(temp != NULL)
	{
		temp = front;
		front = front->next;
		//free(temp);
	}
}

template <typename T>
void CircularQueue<T>::enqueue(T item)
{
	/*
	 * Input : item to be queued
	 * Utility : add item to the queue.
	 * Output : None
	 */
	CQNode<T>* newNode = new CQNode<T>();
	newNode->data = item;
	newNode->next = front;
	//If queue is empty,
	if (this->isEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
}

template <typename T>
T CircularQueue<T>::dequeue()
{
	/*
	 * Input : None
	 * Utility : Serve items in queue
	 * Output : Served element
	 */
	//If queue is empty, return NULL
	if (this->isEmpty())
	{
		cout<<"Queue Empty!"<<endl;
		return NULL;
	}
	//Else, return data of deleted item
	this->data = front->data;
	CQNode<T>* temp = front;
	if (front == rear)
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		front = front->next;
	}
	delete(temp);
	return this->data;
}

template <typename T>
bool CircularQueue<T>::isEmpty()
{
	/*
	 * Input : None
	 * Utility : Determine if queue is empty
	 * Output : boolean(true/false) value
	 */
	return (front == NULL);
}

template <typename T>
void CircularQueue<T>::display()
{
	/*
	 * Input : None
	 * Utility : Display all elements of stack
	 * Output : items of queue are displayed
	 */
	CQNode<T>* temp = front;
	while(temp != rear)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}
