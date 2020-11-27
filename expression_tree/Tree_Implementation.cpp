/*
 * Author : Varad Mashalkar
 * Roll Number : 23321
 * Lab : Data Structures and Algorithms.
 * Version : 1
 * File Description : File contains Expression Tree Implementation.
 */

#include <iostream>
#include "Tree.h"
#include "Converter.h"
#include "ADT.h"
using namespace std;

//default constructor
Tree::Tree()
{
	/*
	 * Constructor
	 */
	root = NULL;
}

//method to create and return a new node having value same as passed data
TNode* Tree::getNode(char token)
{
	/*
	 * Input : Data
	 * Utility : Create new node from given data.
	 * Output : Node
	 */
	TNode* newNode = new TNode;
	newNode->value = token;
	newNode->lChild = NULL;
	newNode->rChild = NULL;
	return newNode;
}

//method to get expression and create tree
void Tree::createTree()
{
	/*
	 * Input : None
	 * Utility : Create tree from post-fix expression.
	 * Output : None
	 */
	Stack<TNode*> s;
	converter c;
	c.getInfix();
	c.infixToPostfix(true);
	char* postfix = new char[80];
	postfix = c.getPostfix();
	int i = 0;
	while(postfix[i] != '\0')
	{
		char token = postfix[i];
		if(!c.isoperator(token))
		{
			TNode* temp = getNode(token);
			s.push(temp);
		}
		else
		{
			TNode* temp = getNode(token);
			temp->rChild = s.pop();
			temp->lChild = s.pop();
			s.push(temp);
		}
		i += 1;
	}
	root = s.pop();
}

//method to traverse tree in recursive manner for inorder traversal
void Tree::recursiveInorder(TNode* node)
{
	/*
	 * Input : None
	 * Utility : Recursive In-order traversal of expression tree.
	 * Output : Contents of tree in in-order manner.
	 */
	//if node is null, return to root.
	if (node == NULL)
	{
		return;
	}
	//Visit left subtree
	this->recursiveInorder(node->lChild);
	//Display value at node.
	cout<<node->value<<" ";
	//Visit right subtree
	this->recursiveInorder(node->rChild);
}

//method to traverse tree in recursive manner for preorder traversal
void Tree::recursivePreorder(TNode* node)
{
	/*
	 * Input : None
	 * Utility : Recursive Pre-order traversal of expression tree.
	 * Output : Contents of tree in pre-order manner.
	 */
	//if node is null, return to root.
	if (node == NULL)
	{
		return;
	}
	//Display value at node.
	cout<<node->value<<" ";
	//Visit left subtree
	this->recursivePreorder(node->lChild);
	//Visit right subtree
	this->recursivePreorder(node->rChild);
}

//method to traverse tree in recursive manner for postorder traversal
void Tree::recursivePostorder(TNode* node)
{
	/*
	 * Input : Node pointer
	 * Utility : post order traversal of expression tree
	 * Output : Contents of tree
	 *
	 */
	//if node is null, return to root.
	if (node == NULL)
	{
		return;
	}
	//Visit left subtree
	this->recursivePostorder(node->lChild);
	//Visit right subtree
	this->recursivePostorder(node->rChild);
	//Display value at node.
	cout<<node->value<<" ";
}

//method to get root of tree
TNode* Tree::getRoot()
{
	/*
	 * Getter method for root of tree.
	 */
	return this->root;
}

//method to traverse tree in iterative manner for inorder traversal
void Tree::nonrecursiveInorder()
{
	/*
	 * Input : None
	 * Utility : Display contents of tree in in order manner. (Iterative)
	 * Output : Contents of tree.
	 */
	//If tree is empty, return to call.
	if (root == NULL)
	{
		cout<<"Tree Empty !"<<endl;
		return;
	}
	Stack<TNode*> s;
	TNode* top = root;
	while(top != NULL || !s.isEmpty())
	{
		while(top != NULL)
		{
			s.push(top);
			top = top->lChild;
		}
		top = s.pop();
		cout<<top->value<<" ";
		top = top->rChild;
	}
}

//method to traverse tree in iterative manner for postorder traversal
void Tree::nonrecursivePostorder()
{
	/*
	 * Input : None
	 * Utility : Display contents of tree in post order manner. (Iterative)
	 * Output : Contents of tree.
	 */
	//If tree is empty, return to call.
	if (root == NULL)
	{
		cout<<"Tree Empty!"<<endl;
		return;
	}
	//flag stack is used to store value if node is visited.
	Stack<TNode*> nodeStack;
	Stack<int> flagStack;
	int flag = 0;
	TNode* t = root;
	do
	{
		while(t != NULL && flag == 0)
		{
			nodeStack.push(t);
			flagStack.push(1);
			t = t->lChild;
		}
		if(!nodeStack.isEmpty())
		{
			t = nodeStack.pop();
			flag = flagStack.pop();
			if (flag == 1)
			{
				nodeStack.push(t);
				flagStack.push(2);
				t = t->rChild;
				flag = 0;
			}
			else
			{
				cout<<t->value<< " ";
			}
		}
	}while(!nodeStack.isEmpty());
}

//method to traverse tree in iteravtive manner for preorder traversal
void Tree::nonrecursivePreorder()
{
	/*
	 * Input : None
	 * Utility : Display contents of tree in pre order manner. (Iterative)
	 * Output : Contents of tree.
	 */
	//If tree is empty, return to call.
	if (root == NULL)
	{
		cout<<"Tree Empty!"<<endl;
		return;
	}
	Stack<TNode*> nodeStack;
	TNode* t = root;
	while(!nodeStack.isEmpty() || t != NULL)
		{
			while(t != NULL)
			{
				cout<<t->value<<" ";
				nodeStack.push(t);
				t = t->lChild;
			}
			if (!nodeStack.isEmpty())
			{
				t = nodeStack.pop();
				t = t->rChild;
			}
		}
}
