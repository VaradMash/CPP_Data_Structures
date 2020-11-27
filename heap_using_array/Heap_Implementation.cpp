/*
 * Author : Varad Mashalkar
 * Version : 1
 * Date : 24/11/2020
 * File Description : This file contains heap implementation code.
 */

#include <iostream>
#include "Heap.h"
#define MAXSIZE 80
using namespace std;

template <typename T>
Heap<T>::Heap()
{
	/*
	 * Constructor
	 */
	size = 0;
}

template <typename T>
Heap<T>::Heap(int s)
{
	/*
	 * Parameterized Constructor.
	 */
	size = s;
}

template <typename T>
void Heap<T>::get_heap()
{
	/*
	 * Input : None
	 * Utility : Method to accept heap and size from user.
	 * Output : None
	 */
	cout<<"Enter size of heap : ";
	cin>>size;
	while(size<0 || size>80)
	{
		cout<<"\nSize cannot be negative or greater than zero!"<<endl;
		cout<<"Please re enter size : ";
		cin>>size;
	}
	cout<<"\nEnter Elements of heap"<<endl;
	for (int i = 0;i < this->size; i++)
	{
		cin>>this->heap[i];
	}
}

template <typename T>
void Heap<T>::display_heap(int index, bool reverse)
{
	/*
	 * Input : None
	 * Utility : Display heap.
	 * Output : None
	 */
	//if reverse flag is not set, display in order.
	if (!reverse)
	{
		for (int i = 0; i<=index; i++)
		{
			cout<<this->heap[i]<<" | ";
		}
		cout<<endl;
	}
	else
	{
		for (int i = index; i>=0; i--)
		{
			cout<<this->heap[i]<<" | ";
		}
		cout<<endl;
	}
}

template <typename T>
void Heap<T>::insert_node(T data)
{
	/*
	 * Input : None
	 * Utility : Add new node to heap and re build heap.
	 * Output : None
	 */
	//If heap overflows, return to call.
	if (this->size >= MAXSIZE)
	{
		cout<<"Maximum size of heap : "<<MAXSIZE<<endl;
		cout<<"Cannot add new node."<<endl;
		return;
	}
	//else, add new node and rebuild heap.
	this->heap[size] = data;
	size += 1;
}

template <typename T>
void Heap<T>::max_heapify(int i, int s)
{
	/*
	 * Input : index of element
	 * Utility : Find right position for heap[i] w.r.t. max heap property. (Recursive algorithm)
	 * Output : None
	 */
	//if heap is empty, return to call.
	if (size == 0)
	{
		cout <<"Heap Empty!"<<endl;
		return;
	}
	//else execute algorithm.
	int largest = i;
	int left = 2*i + 1;
	int right =  2*i + 2;
	if (left < s && heap[left] > heap[i])
	{
		largest = left;
	}
	if (right < s && heap[right] > heap[largest])
	{
		largest = right;
	}
	if (largest != i)
	{
		T temp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = temp;
		this->max_heapify(largest, s);
	}
}

template <typename T>
void Heap<T>::build_maxheap()
{
	/*
	 * Input : None
	 * Utility : Build heap from given array.
	 * Output : None
	 */
	//if heap is empty, return to call
	if (size ==0)
	{
		cout<<"Heap Empty!"<<endl;
		return;
	}
	//else covert given array to heap
	for (int i = (size/2) - 1; i >= 0; i--)
	{
		this->max_heapify(i, this->size);
	}

}

template <typename T>
void  Heap<T>::heap_sort()
{
	/*
	 * Input : None
	 * Utility : Perform Heap Sort
	 * Output : None
	 */
	//Build a heap out of the given array.
	this->build_maxheap();
	//Find position of element by recursively array
	for (int i = size - 1; i >0; i--)
	{
		cout<<"Deleted Element : "<<this->heap[0]<<endl;
		this->display_heap(i, true);
		cout<<endl;
		T temp = heap[i];
		heap[i] = heap[0];
		heap[0] = temp;
		this->max_heapify(0, i);
	}
}

template <typename T>
int Heap<T>::getSize()
{
	/*
	 * Getter method for size of heap.
	 */
	return size;
}
