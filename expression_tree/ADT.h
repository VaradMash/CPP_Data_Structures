/*
 * Implementation.cpp
 *
 *  Created on: 26-Sep-2020
 *  Author: Varad Mashalkar
 *  Lab : Data Structures and Algorithms
 *  Assignment : 2
 *  File Description : This file contains the Stack ADT
 */

#include <iostream>
using namespace std;

#ifndef SRC_ADT_H_
#define SRC_ADT_H_

template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;
};

template <typename T>
class Stack
{
private:
	Node<T>* top;
	int max_size, count;	//Change to "count" and "max_size"
public:
	T element;
	Stack();				//Default constructor
	~Stack();				//Destructor
	void push(T data);		//push received data;
	T pop();				//pop data from stack
	bool isFull();			//check if stack is full
	bool isEmpty();			//check if stack is empty
	void setSize();			//Set maximum Size of stack
	void displayStack();	//Display Stack
	T peep();				//Return data at the top
};
//Default Constructor
template <typename T>
Stack<T>::Stack()
{
	/*
	 * Constructor
	 */
	top = NULL;
	max_size = 80;
	count = 0;
}

//Destructor
template <typename T>
Stack<T>:: ~Stack()
{
	/*
	 * Destructor
	 */
	Node<T>* temp = top;
	while(top != NULL)
	{
		temp = top;
		top = top->next;
		delete(temp);
	}
}

//method to set size of stack
template <typename T>
void Stack<T>::setSize()
{
	/*
	 * Input : None
	 * Utility : Set maximum size of stack
	 * Output : None
	 */
	cout<<"Enter Size of Stack"<<endl;
	cin>>max_size;
	//validating size value
	while(max_size<0)
	{
		cout<<"Size Cannot be negative!"<<endl;
		cout<<"Please re Enter Size!"<<endl;
		cin>>max_size;
	}
}

//Method to check whether stack is empty
template <typename T>
bool Stack<T>::isEmpty()
{
	/*
	 * Input : None
	 * Utility : Method to determine whether stack is empty.
	 * Output : Boolean true or false.
	 */
	return(top == NULL);
}

//Method to check whether the stack is full
template <typename T>
bool Stack<T>::isFull()
{
	/*
	 * Input : None
	 * Utility : Method to determine whether stack is full
	 * Output : Boolean true or false.
	 */
	return (count >= max_size);
}

//Method to push an data in The stack
template <typename T>
void Stack<T>::push(T data)
{
	/*
	 * Input : None
	 * Utility : Push Data into Stack
	 * Output : None
	 */
	//Return to call if stack is full
	if (this->isFull())
	{
		cout<<"Stack Overflow!"<<endl;
		cout<<"Cannot Add above data!"<<endl;
		return;
	}
	//Create new node and assign received data value
	Node<T>* new_node = new Node<T>;
	new_node->data = data;
	//Push a node in the empty stack
	if (top==NULL)
	{
		top = new_node;
		new_node->next = NULL;
	}
	//Push a node in a non empty stack
	else
	{
		new_node->next = top;
		top = new_node;
	}
	count += 1;
}

//Method to pop data from stack
template <typename T>
T Stack<T>::pop()
{
	/*
	 * Input : None
	 * Utility : Pop content of stack and remove top data.
	 * Output : Top data
	 */
	//Evaluate underflow condition
	if (this->isEmpty())
	{
		cout<<"Stack Underflow on POP !"<<endl;
		//Type cast to NULL value
		return NULL;
	}
	this->element = top->data;
	Node<T>* temp = top;
	top = top->next;
	delete temp;
	if (count != 0)
	{
		count -= 1;
	}
	return this->element;
}

//Method to peep into the stack
template <typename T>
T Stack<T>::peep()
{
	/*
	 * Input : None
	 * Utility : Return contents of top
	 * Output : Top Content
	 */
	//Evaluate underflow Condition
	if (this->isEmpty())
	{
		//cout<<"Stack Underflow on peep!"<<endl;
		//Type cast to NULL value
		return (T)0;
	}
	else
	{
		return top->data;
	}
}

//Method to display Stack
template <typename T>
void Stack<T>::displayStack()
{
	/*
	 * Input : None
	 * Utility : Display Stack contents
	 * Output : Stack Contents
	 */
	//Evaluate underflow condition
	if (this->isEmpty())
	{
		cout<<"Empty";
		return;
	}
	//Display
	Node<T>* temp = top;
	while(temp!=NULL)
	{
		//top to bottom
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
#endif /* SRC_ADT_H_ */
