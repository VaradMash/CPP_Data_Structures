/*
 * LinkList.h
 *
 *  Created on: 29-Oct-2020
 *      Author: varadm
 */

#ifndef SRC_LINKLIST_H_
#define SRC_LINKLIST_H_

template <typename T>
class LLNode
{
public :
	T data;
	LLNode<T>* next;
};

template <typename T>
class LinkList
{
private:
	LLNode<T>* head;
	int max(int, int);
	LLNode<T>* getNodeAt(int);
public:
	T element;
	LinkList();				//Constructor
	~LinkList();			//Destructor
	bool isEmpty();
	bool isFirst(T);
	bool isLast(T);
	LLNode<T>* get_head();
	int get_size();
	T getNodebefore(int);
	T getNodeAfter(int);
	T getFirstNode();
	T getLastNode();
	void display();
	void swapElements(int,int);
	void replaceElement(int, T);
	void insertFirst(T);
	void insertLast(T);
	void insertBefore(int, T);
	void insertAfter(int, T);
	void removeAfter(int);
	void removeAt(int);
};




#endif /* SRC_LINKLIST_H_ */
