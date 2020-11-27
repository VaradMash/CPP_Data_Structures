/*
 * Author : Varad Mashalkar
 * Version : 1
 * Date : 24/11/2020
 * File Description : This file contains ADT for heap.
 */

#ifndef SRC_HEAP_H_
#define SRC_HEAP_H_
#define MAXSIZE 80

template <typename T>
class Heap
{
private:
	T heap[MAXSIZE];
	int size;
public:
	Heap();						//Constructor.
	Heap(int);					//Parameterized constructor.
	void get_heap();			//Method to accept heap from user.
	void display_heap(int,bool);//Method to display heap.
	void insert_node(T);		//Method to add new node to heap.
	void max_heapify(int, int);	//Method to locate position of nodes.
	void build_maxheap();		//Method to build heap.
	void heap_sort();			//Method to perform heap sort.
	int getSize();				//Method to get size of heap.
};


#endif /* SRC_HEAP_H_ */
