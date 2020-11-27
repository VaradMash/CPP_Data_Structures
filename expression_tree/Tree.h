/*
 * Author : Varad Mashalkar
 * Roll Number : 23321
 * Lab : Data Structures and Algorithms.
 * Version : 1
 * File Description : File contains Expression Tree ADT.
 */

#ifndef SRC_TREE_H_
#define SRC_TREE_H_

class TNode
{
public:
	char value;
	TNode* lChild;
	TNode* rChild;
};

class Tree
{
private:
	TNode* root;
public:
	Tree();								//default constructor
	TNode* getNode(char);				//method to create and return a new node having value same as passed data
	void createTree();					//method to get expression and create tree
	void recursiveInorder(TNode*);		//method to traverse tree in recursive manner for inorder traversal
	void recursivePreorder(TNode*);		//method to traverse tree in recursive manner for preorder traversal
	void recursivePostorder(TNode*);	//method to traverse tree in recursive manner for postorder traversal
	void nonrecursiveInorder();			//method to traverse tree in iterative manner for inorder traversal
	void nonrecursivePreorder();		//method to traverse tree in iterative manner for preorder traversal
	void nonrecursivePostorder();		//method to traverse tree in iterative manner for postorder traversal
	TNode* getRoot();					//method to get root of tree
};

#endif /* SRC_TREE_H_ */
