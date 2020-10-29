#include <iostream>
#include "Queue.h"
using namespace std;

//Constructor
template <typename T>
Queue<T>::Queue()
{
	/*
	 * Input : None
	 * Utility : Constructor
	 * Output : None
	 */
	front = NULL;
	rear = NULL;
}

//Destructor
template <typename T>
Queue<T>::~Queue()
{
	/*
	 * Input : None
	 * Utility : Destroy all Queue nodes.
	 * Output : None
	 */
	if (!this->isEmpty())
	{
		QNode<T>* temp = front;
		while(temp != NULL)
		{
			temp = front;
			front = front->next;
			delete(temp);
		}
	}
}

//Method to enqueue data
template <typename T>
void Queue<T>::enqueue(T item)
{
	/*
	 * Input : Item to be added to queue.
	 * Utility : Add item to queue.
	 * Output : None
	 */
	//Create new Node
	QNode<T>* newNode = new QNode<T>();
	newNode->data = item;
	newNode->next = NULL;
	//If stack is empty, set front and rear pointers to new node
	if (this->isEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	//else, change value of rear pointer accordingly.
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
	/*
	 * Input : None
	 * Utility : Serve Item From Queue.
	 * Output : Dequeued item.
	 */
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
	/*
	 * Input : None
	 * Utility : Determine whether queue is empty.
	 * Output : boolean(true/false) value.
	 */
	return (front == NULL);
}

//Method to display queue
template <typename T>
void Queue<T>::display()
{
	/*
	 * Input : None
	 * Utility : Display Elements of queue.
	 * Output : Display of elements sequentially from front to rear.
	 */
	QNode<T>* temp = front;
	while(temp != NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}
