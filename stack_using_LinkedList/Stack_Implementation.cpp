#include <iostream>
#include "Stack.h"
using namespace std;

//Default Constructor
template <typename T>
Stack<T>::Stack()
{
	top = NULL;
	count = 0;
	max_size = 0;
}

//Parameterized Constructor
template <typename T>
Stack<T>::Stack(int size)
{
	top = NULL;
	count = 0;
	max_size = size;
}

//Destructor
template <typename T>
Stack<T>::~Stack()
{
	/*
	 * Input : None
	 * Utility : Delete all Stack Nodes
	 * Output : None
	 */
	if(!this->isEmpty())
	{
		SNode<T>* temp;
		while(temp != NULL)
		{
			temp = top;
			top = top->next;
			delete(temp);
		}
	}
}

//method to identify isEmpty condition of queue
template <typename T>
bool Stack<T>::isEmpty()
{
	/*
	 * Input : None
	 * Utility : Determine whether the stack is empty.
	 * Output : returns boolean(true/false) value.
	 */
	return(top == NULL);
}

//method to identify isFull condition of queue
template <typename T>
bool Stack<T>::isFull()
{
	/*
	 * Input : None
	 * Utility : Determine whether the stack is full.
	 * Output : returns boolean(true/false)
	 */
	return (count >= max_size);
}

//method to push data passed to it
template <typename T>
void Stack<T>::push(T data)
{
	/*
	 * Input : Data to be pushed into stack
	 * Utility : Push received data into given stack.
	 * Output : None
	 */
	//Return to call if stack is full
	if(this->isFull())
	{
		cout<<"Stack Overflow!"<<endl;
		return;
	}
	//Else, create new node and add to start.
	SNode<T>* newNode = new SNode<T>();
	newNode->data = data;
	//if stack is empty, then set next pointer of new node to null.
	if (this->isEmpty())
	{
		newNode->next = NULL;
	}
	//Else, add to start with appropriate rear pointer
	else
	{
		newNode->next = top;
	}
	top = newNode;
	//Increment Counter
	count += 1;
}

//method to pop data from stack
template <typename T>
T Stack<T>::pop()
{
	/*
	 * Input : None
	 * Utility : Pop element from top of stack.
	 * Output : Popped Element
	 */
	//If stack is empty, return NULL to call
	if(this->isEmpty())
	{
		cout<<"Stack Underflow on Pop!"<<endl;
		return NULL;
	}
	//Else, remove node from front.
	this->data = top->data;
	SNode<T>* delete_node = top;
	top = top->next;
	delete(delete_node);
	if(count != 0)
	{
		count -= 1;
	}
	return data;
}

//method to peep into stack
template <typename T>
T Stack<T>::peep()
{
	/*
	 * Input : None
	 * Utility : Get element at top of stack
	 * Output : Element at top;
	 */
	//If stack is empty, return to call.
	if(this->isEmpty())
	{
		cout<<"Stack Underflow on Peep!"<<endl;
		return NULL;
	}
	//Else return data of top.
	return top->data;
}

//method to display stack from top to bottom
template <typename T>
void Stack<T>::display()
{
	/*
	 * Input : None
	 * Utility : Display Stack content
	 * Output: : None
	 */
	if(this->isEmpty())
	{
		cout<<"Stack Underflow!"<<endl;
		return;
	}
	SNode<T>* temp = top;
	while(temp!= NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}
