#include <iostream>
#include "LinkList.h"
using namespace std;

//Internal Method
template <typename T>
int LinkList<T>::max(int x, int y)
{
	if(x > y)
	{
		return x;
	}
	return y;
}


//Constructors

template <typename T>
LinkList<T>::LinkList()
{
	/*
	 * Input : None
	 * Utility : Construct Object and allocate memory
	 * Output : None
	 */
	head = NULL;
}

template <typename T>
LinkList<T>::~LinkList()
{
	/*'
	 * Input : Destroy All nodes
	 * Utility : Destroy object and free memory
	 * Output : None
	 */
	if(!this->isEmpty())
	{
		LLNode<T>* temp = head;
		head = head->next;
		delete(temp);
	}
}

//Query Methods

template <typename T>
bool LinkList<T>::isEmpty()
{
	/*
	 * Input : None
	 * Utility : Determine whether the current list is empty
	 * Output : None
	 */
	return (head == NULL);
}


template <typename T>
bool LinkList<T>::isFirst(T data)
{
	/*
	 * Input : Value to be verified if it as the front of the list.
	 * Utility : Determines whether the given data is at the front of the linked list.
	 * Output : boolean(true/false) value for required condition.
	 */
	return(head->data == data);
}

template <typename T>
bool LinkList<T>::isLast(T data)
{
	/*
	 * Input : Value to be verified if it as the front of the list.
	 * Utility : Determines whether the given data is at the end of the linked list.
	 * Output : boolean(true/false) value for required condition.
	 */
	//Traverse to end of list
	LLNode<T>* temp = head;
	while(1)
	{
		if (temp->next == NULL)
		{
			break;
		}
		temp = temp->next;
	}
	return(temp->data == data);
}

//Accessor Methods

template <typename T>
LLNode<T>* LinkList<T>::get_head()
{
	return head;
}

template <typename T>
LLNode<T>* LinkList<T>::getNodeAt(int position)
{
	//Internal Method
	/*
	 * Input : position
	 * Utility : Get pointer to node at position.
	 * Output : Node pointer
	 */
	LLNode<T>* temp = head;
	for(int i = 0; i<position; i++)
	{
		temp = temp->next;
	}
	return temp;
}

template <typename T>
T LinkList<T>::getFirstNode()
{
	/*
	 * Input : None
	 * Utility : Get value of first node
	 * Output : Value of first node.
	 */
	//If list is empty, return no value.
	if(this->isEmpty())
	{
		cout<<"List Empty!"<<endl;
		return 0;
	}
	//Else, return value stored at first node
	return head->data;
}

template <typename T>
T LinkList<T>::getLastNode()
{
	/*
	 * Input : None
	 * Utility : Get value of last Node
	 * Output : Value of last node
	 */
	//If list is empty, return no value.
	if(this->isEmpty())
	{
		cout<<"List Empty!"<<endl;
		return 0;
	}
	//Initialize temporary pointer
	LLNode<T>* temp = head;
	//Loop till the end of link list is found
	while(1)
	{
		if (temp->next == NULL)
		{
			return temp->data;
		}
		temp = temp->next;
	}
}

template <typename T>
int LinkList<T>::get_size()
{
	/*
	 * Input : None
	 * Utility : Get the size(NUmber of Elements) in current list.
	 * Output : Size of linked list.
	 */
	//If List is empty, return size as 0.
	if(this->head == NULL)
	{
		return 0;
	}
	//Else, count size by traversal.
	int size = 0;
	LLNode<T>* temp = head;
	while(temp != NULL)
	{
		size += 1;
		temp = temp->next;
	}
	return size;
}


template <typename T>
T LinkList<T>::getNodebefore(int position)
{
	/*
	 * Input : position of node who's predecessor is to be accessed.
	 * Utility : Access node which is before the specified node.
	 * Output : If specified Node exists, then return appropriate value.
	 */
	//If list is empty, return NULL.
	if (this->isEmpty())
	{
		cout<<"Empty List!"<<endl;
		return 0;
	}
	//If size of node is less than position, return to call.
	if(position > this->get_size() - 1 || position <= 0)
	{
		cout<<"Index out of bound!"<<endl;
		return 0;
	}
	LLNode<T>* temp = head;
	for (int i = 0; i <= position - 2; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}

template <typename T>
T LinkList<T>::getNodeAfter(int position)
{
	/*
	 * Input : position of node who's successor is to be accessed.
	 * Utility : Access node which is before the specified node.
	 * Output : If specified Node exists, then return appropriate value.
	 */
	//If list is empty, return NULL.
	if (this->isEmpty())
	{
		cout<<"Empty List!"<<endl;
		return 0;
	}
	//If size of node is less than position, return to call.
	if(position > this->get_size() - 2 || position<0)
	{
		cout<<"Index out of bound!"<<endl;
		return 0;
	}
	LLNode<T>* temp = head;
	for (int i = 0; i <= position; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}

//Update methods

template <typename T>
void LinkList<T>::replaceElement(int position, T data)
{
	/*
	 * Input : position and data
	 * Utility : Replace element at position by provided data.
	 * Output : None
	 */
	if (position > this->get_size() - 1 || position<0)
	{
		cout<<"Index out of bound!"<<endl;
		return;
	}
	LLNode<T>* temp = this->getNodeAt(position);
	temp->data = data;
}

template <typename T>
void LinkList<T>::swapElements(int p, int q)
{
	/*
	 * Input : Index of elements to be swapped
	 * Utility : Swap elements at positions p and q
	 * Output : None
	 */
	if (this->get_size() - 1 < this->max(p, q))
	{
		cout<<"Index out of bound!"<<endl;
		return;
	}
	LLNode<int>* temp1 = this->getNodeAt(p);
	LLNode<int>* temp2 = this->getNodeAt(q);
	this->element = temp1->data;
	temp1->data = temp2->data;
	temp2->data = this->element;
}

template <typename T>
void LinkList<T>::insertFirst(T data)
{
	/*
	 * Input : Data
	 * Utility : Insert node at beginning of list.
	 * Output : None
	 */
	LLNode<T>* temp = new LLNode<T>();
	temp->data = data;
	temp->next = head;
	head = temp;
}

template <typename T>
void LinkList<T>::insertLast(T data)
{
	/*
	 * Input : data
	 * Utility : add node at end with received data.
	 * Output : Nones
	 */
	LLNode<T>* newNode = new LLNode<T>();
	newNode->data = data;
	newNode->next = NULL;
	LLNode<T>* temp = head;
	while(1)
	{
		if(temp->next == NULL)
		{
			temp->next = newNode;
			break;
		}
		temp = temp->next;
	}


}


//Display Method

template <typename T>
void LinkList<T>::display()
{
	/*
	 * Input : None
	 * Utility : Display value of all node sequentially.
	 * Output : Values of nodes.
	 */
	//If list is empty, display message
	if (this->isEmpty())
	{
		cout<<"Empty List!"<<endl;
		return;
	}
	//Else, display nodes using temporary pointer.
	LLNode<T>* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

template <typename T>
void LinkList<T>::insertAfter(int position, T data)
{
	/*
	 * Input : node position and data
	 * Utility : insert node after given position
	 * Output : None
	 */
	if (position >this->get_size()-1 || position<0)
	{
		cout<<"Index out of bound!"<<endl;
		return;
	}
	LLNode<T>* temp = this->getNodeAt(position);
	LLNode<T>* newNode = new LLNode<T>();
	newNode->data = data;
	newNode->next = temp->next;
	temp->next = newNode;
}

template <typename T>
void LinkList<T>::insertBefore(int position, T data)
{
	/*
	 * Input : node position and data
	 * Utility : insert node before given position
	 * Output : None
	 */
	if (position >this->get_size()-1 || position<0)
	{
		cout<<"Index out of bound!"<<endl;
		return;
	}
	if (position == 0)
	{
		this->insertFirst(data);
		return;
	}
	LLNode<T>* temp = this->getNodeAt(position - 1);
	LLNode<T>* newNode = new LLNode<T>();
	newNode->data = data;
	newNode->next = temp->next;
	temp->next = newNode;
}

template <typename T>
void LinkList<T>::removeAfter(int position)
{
	/*
	 * Input : node position and data
	 * Utility : remove node after given position
	 * Output : None
	 */
	if (position >this->get_size()-1 || position<0)
	{
		cout<<"Index out of bound!"<<endl;
		return;
	}
	LLNode<T>* temp = this->getNodeAt(position);
	LLNode<T>* temp1 = temp->next;
	cout<<temp1->data<<endl;
	temp->next = temp1->next;
	delete(temp1);
}

template <typename T>
void LinkList<T>::removeAt(int position)
{
	/*
	 * Input : node position and data
	 * Utility : remove node at given position
	 * Output : None
	 */
	if (position >this->get_size()-1 || position<0)
	{
		cout<<"Index out of bound!"<<endl;
		return;
	}
	if (position == 0)
	{
		LLNode<T>* temp = head;
		head = head->next;
		delete(temp);
		return;
	}
	LLNode<T>* temp = this->getNodeAt(position - 1);
	LLNode<T>* temp1 = temp->next;
	cout<<temp1->data<<endl;
	temp->next = temp1->next;
	delete(temp1);
}
