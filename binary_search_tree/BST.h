/*
 * BST.h
 *
 *  Created on: 27-Oct-2020
 *      Author: varadm
 */

#ifndef SRC_BST_H_
#define SRC_BST_H_

template <typename T>
class BSTNode
{
public:
	T data;
	BSTNode<T>* lchild;
	BSTNode<T>* rchild;
};

template <typename T>
class BinarySearchTree
{
private:
	BSTNode<T>* root;
	T max(T,T);
public:
	BinarySearchTree();									//Constructor method
	BinarySearchTree(BSTNode<T>*);						//Parameterized constructor
	BSTNode<T>* getRoot();								//Getter method for root
	BSTNode<T>* getNode(T);								//This method is used to create a node with provided data
	BSTNode<T>* recursive_insert(BSTNode<T>*,T);		//Method to insert new node in tree
	void iterative_insert(T);							//Method to insert new node in tree iteratively
	bool isEmpty();										//Method to determine whether tree is empty
	bool isLeaf(BSTNode<T>*);							//Method to determine if node is a leaf
	void searchTree(T);									//Non recursive method to search tree
	int height();										//method to calculate height of tree
	void level_order_display(BSTNode<T>*);				//Method to display the tree in level order
	void mirror(BSTNode<T>*);							//method to generate mirror image of the tree.
	void displayLeaves(BSTNode<T>*);					//Method to display leaves
	void displayParents(BSTNode<T>*);					//Method to display parents and their child nodes
	BSTNode<T>* getDuplicate(BSTNode<T>*);				//return copy of tree as an object
	void recursive_inorder_display(BSTNode<T>*);		//recursive inorder display
	void recursive_preorder_display(BSTNode<T>*);		//recursive preorder display
	void recursive_postorder_display(BSTNode<T>*);		//recursive postorder display
	void iterative_inorder_display();					//iterative inorder display
	void iterative_preorder_display();					//iterative preorder display
	void iterative_postorder_display();					//iterative postorder display
	BSTNode<T>* delete_node(T, BSTNode<T>*);			//recursive delete method
	T find_min(BSTNode<T>*);							//Find minimum node from right subtree.
	void setRoot(BSTNode<T>*);							//Setter method for root.
};

#endif /* SRC_BST_H_ */
