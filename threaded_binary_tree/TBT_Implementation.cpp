#include <iostream>
#include "TBT.h"
using namespace std;

template <typename T>
ThreadedBinaryTree<T>::ThreadedBinaryTree()
{
	/*
	 * Constructor
	 */
	root = NULL;
	head = new TBTNode<T>;
	head->rptr = head;
	head->lptr = head;
	head->data = -1;
	head->lthread = 0;
	head->rthread = 1;
}


template <typename T>
void ThreadedBinaryTree<T>::createRoot(T data)
{
	/*
	 * Input : pointer to head of tree
	 * Utility : create head if tree is empty
	 * Output : Head
	 */
	root = new TBTNode<T>;
	root->data = data;
	head->lptr = root;
	head->lthread = 1;
	root->lptr = head;
	root->rptr = head;
	root->lthread = 0;
	root->rthread = 0;
}

template <typename T>
void ThreadedBinaryTree<T>::insert_node(T data)
{
	/*
	 * Input : data
	 * Utility : insert new node in TBT
	 * Output : None
	 */
	//If tree is empty, create head.
	if (head->lptr == head)
	{
		cout<<"Creating root as tree is empty !"<<endl;
		this->createRoot(data);
		cout<<"Root with data "<<data<<" has been created"<<endl;
		return;
	}
	//Else place node according to necessity
	TBTNode<T>* newNode = new TBTNode<T>;
	newNode->data = data;
	newNode->lthread = newNode->rthread = 0;
	TBTNode<T>* temp = root;
	bool flag = true;
	//repeat while position of node is not located.
	while(flag)
	{
		int choice;
		cout<<"\nRoot is : "<<temp->data<<endl;
		cout<<"1. Insert at left\n2. Insert at right"<<endl;
		cout<<"Enter Choice code"<<endl;
		cin>>choice;

		switch (choice)
		{
		//Go to left pointer of thread
		case 1:
		{
			//If left thread is terminated, insert node and exit loop.
			//termination of thread is indicated by falseflag
			if (temp->lthread == 1)
			{
				temp = temp->lptr;
			}
			//else traverse to left
			else
			{
				newNode->lptr = temp->lptr;
				temp->lptr = newNode;
				newNode->rptr = temp;
				temp->lthread = 1;
				flag = false;
			}
			break;
		}
		//Go to right pointer of thread
		case 2:
		{
			//If right thread is terminated, insert node and exit loop.
			if (temp->rthread == 1)
			{
				temp = temp->rptr;
			}
			//else traverse to right
			else
			{
				newNode->rptr = temp->rptr;
				temp->rptr = newNode;
				newNode->lptr = temp;
				temp->rthread = 1;
				flag = false;
			}
			break;
		}
		default:
			cout<<"Invalid Choice !"<<endl;
			break;
		}
	}
}

template <typename T>
void ThreadedBinaryTree<T>::display_in_order(bool resetFlag)
{
	/*
	 * Input : None
	 * Utility : Display tree content in in order
	 * Output : Tree display
	 */
	TBTNode<T>* temp = head->lptr;
	//if tree is empty, display message and return to call.
	if (temp == head)
	{
		cout<<"\nTree Empty!"<<endl;
		return;
	}
	//else, traverse tree in in order manner.
	while(temp!=head)
	{
		//traverse to the node where the left thread of the subtree terminates.
		while(temp->lthread != 0)
		{
			temp = temp->lptr;
		}
		//display all node till the right thread of the subtree does not terminate.
		while(temp->rthread != 1)
		{
			if (!resetFlag)
			{
				//display temporary pointer data
				cout<<temp->data<<" ";
			}
			else
			{
				temp->flag = 0;
			}
			temp = temp->rptr;
		}
		//if the rightmost node is visited, terminate loop.
		if(temp==head)
		{
			break;
		}
		if (!resetFlag)
		{
			//display temporary pointer data
			cout<<temp->data<<" ";
		}
		else
		{
			temp->flag = 0;
		}
		//traverse to in order successor.
		temp = temp->rptr;
	}
	if (!resetFlag)
	{
		cout<<endl;
	}
}

template <typename T>
void ThreadedBinaryTree<T>::display_pre_order()
{
	/*
	 * Input : None
	 * Utility : Display tree content in pre order
	 * Output : Tree display
	 */
	TBTNode<T>* temp = head->lptr;
	//if tree is empty, display message and return to call.
	if (temp == head)
	{
		cout<<"\nTree Empty!"<<endl;
		return;
	}
	//else, traverse tree in pre order manner.
	while(temp != head)
	{
		//display data of entire left thread.
		while(true)
		{
			cout<<temp->data<<" ";
			//if left thread terminates, terminate loop.
			if (temp->lthread == 0)
			{
				break;
			}
			//else, move to left pointer.
			else
			{
				temp = temp->lptr;
			}
		}
		//move to right pointers
		while (temp->rthread != 1)
		{
			temp = temp->rptr;
		}
		//move to in order successor.
		temp = temp->rptr;
	}
	cout<<endl;
}

template <typename T>
void ThreadedBinaryTree<T>::display_post_order()
{
	/*
	 * Input : None
	 * Utility : Display tree content in post order
	 * Output : Tree display
	 */
	TBTNode<T>* temp = head->lptr;
	//if tree is empty, display message and return to call.
	if (temp == head)
	{
		cout<<"\nTree Empty!"<<endl;
		return;
	}
	//else, traverse tree in post order manner.
	temp->flag = 0;
	while (temp != head)
	{
		if (temp->lthread == 1 && temp->lptr->flag != 2)
		{
			temp = temp->lptr;
			temp->flag = 0;
		}
		if (temp->rthread == 1 && temp->rptr->flag != 2)
		{
			temp = temp->rptr;
			temp->flag = 1;
		}

		cout <<temp->data<<" ";
		if (temp->flag == 0)
		{
			temp->flag = 2;
			while(temp->rthread == 1)
			{
				temp = temp->rptr;
			}
			temp = temp->rptr;
		}
		else
		{
			temp->flag = 2;
			while (temp->lthread == 1)
			{
				temp = temp->lptr;
			}
			temp = temp->lptr;
		}
	}
	this->display_in_order(true);
}

