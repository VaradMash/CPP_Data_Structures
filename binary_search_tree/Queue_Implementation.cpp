#include <iostream>
#include "Queue.h"
using namespace std;

//Constructor
template <typename T>
Queue<T>::Queue()
{
	front = NULL;
	rear = NULL;
}

//Destructor
template <typename T>
Queue<T>::~Queue()
{
	if (!this->isEmpty())
	{
		QNode<T>* temp = front;
		while(temp != NULL)
		{
			temp = front;
			front = front->next;
			//delete(temp);
		}
	}
}

//Method to enqueue data
template <typename T>
void Queue<T>::enqueue(T item)
{
	QNode<T>* newNode = new QNode<T>();
	newNode->data = item;
	newNode->next = NULL;
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

//Method to dequeue data
template <typename T>
T Queue<T>::dequeue()
{
	if (this->isEmpty())
	{
		cout<<"Queue Empty!"<<endl;
		return NULL;
	}
	this->data = front->data;
	QNode<T>* temp = front;
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

//Method to identify isEmpty condition
template <typename T>
bool Queue<T>::isEmpty()
{
	return (front == NULL);
}

//Method to display queue
template <typename T>
void Queue<T>::display()
{
	QNode<T>* temp = front;
	while(temp != NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}

//method to calculate size of queue
template <typename T>
int Queue<T>::size()
{
	/*
	 * Input : None
	 * Utility : Count number of elements in queue.
	 * Output : size of queue
	 */
	//return 0 for empty queue
	if (this->isEmpty())
	{
		return 0;
	}
	//else, traverse through queue and count elements
	QNode<T>* temp = front;
	int Qsize = 0;
	while (temp != NULL)
	{
		Qsize += 1;
		temp = temp->next;
	}
	return Qsize;

}
