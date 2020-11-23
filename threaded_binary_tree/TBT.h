/*
 * TBT.h
 * Author : Varad Mashalkar
 * File Description : Header file for Threaded Binary Tree
 * Version : 1
 */

#ifndef SRC_TBT_H_
#define SRC_TBT_H_

template <typename T>
class TBTNode
{
public:
	T data;
	TBTNode<T>* lptr;
	TBTNode<T>* rptr;
	int lthread;
	int rthread;
	int flag;
};

template <typename T>
class ThreadedBinaryTree
{
private:
	TBTNode<T>* root = NULL;					//Head pointer of TBT.
	TBTNode<T>* head;
public:
	ThreadedBinaryTree();				//Constructor
	void createRoot(T);					//Method to create root.
	void insert_node(T);				//Method to insert node in TBT.
	void display_pre_order();			//Method to display TBT in pre order.
	void display_in_order(bool);		//Method to display TBT in in order.
	void display_post_order();			//Method to display TBT in post order.
	void reset_all_flags();				//Method to reset flag values of all nodes using in order.
};

#endif /* SRC_TBT_H_ */
