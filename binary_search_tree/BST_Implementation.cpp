#include <iostream>
#include "BST.h"
#include "Queue_Implementation.cpp"
#include "Stack.h"
using namespace std;

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	/*
	 * Input : None
	 * Utility : Constructor
	 * Output : None
	 */
	root = NULL;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(BSTNode<T>* r)
{
	/*
	 * Input : None
	 * Utility : Parameterized Constructor
	 * Output : None
	 */
	root = r;
}

template <typename T>
T BinarySearchTree<T>::max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::getRoot()
{
	/*
	 * Input : None
	 * Utility : get the pointer of root for current Binary Search tree
	 * Output : root
	 */
	return this->root;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::getNode(T data)
{
	/*
	 * Input : Data
	 * Utility : Create node of provided data
	 * Output : BSTNode
	 */
	BSTNode<T>* newNode = new BSTNode<T>();
	newNode->data = data;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	return newNode;
}

template <typename T>
bool BinarySearchTree<T>::isEmpty()
{
	/*
	 * Input : None
	 * Utility : Determine whether tree is empty
	 * Output : boolean true/false value
	 */
	return (root == NULL);
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::recursive_insert(BSTNode<T>* r, T data)
{
	/*
	 * Input : data
	 * Utility : insert new node in tree. report error if duplication found.(recursive)
	 * Output : None
	 */
	//If current root is a leaf, assign value to node
	if(r == NULL)
	{
		root = this->getNode(data);
		return r;
	}
	//else, create tree node by locating position
	else
	{
		cout<<"Visited node : "<<r->data<<endl;
		if(data < r->data)
		{
			if (r->lchild != NULL)
				r->lchild = this->recursive_insert(r->lchild, data);
			else
				r->lchild = this->getNode(data);
		}
		else if (data > r->data)
		{
			if (r->rchild != NULL)
				r->rchild = this->recursive_insert(r->rchild, data);
			else
				r->rchild = this->getNode(data);
		}
		else
		{
			cout<<"Duplication not allowed !"<<endl;
			return r;
		}
	}
	return r;
}

template <typename T>
void BinarySearchTree<T>::searchTree(T key)
{
	/*
	 * Input : item to be searched
	 * Utility : determine whether item is present in the tree (iterative)
	 * Output : None
	 */
	//If the tree is empty, return to call
	if (this->isEmpty())
	{
		cout<<"Tree empty!"<<endl;
		return;
	}
	//Else, search for element.
	BSTNode<T>* temp = root;
	while (temp != NULL)
	{
		if (key == temp->data)
		{
			cout<<key<<" found in tree"<<endl;
			cout<<(temp->lchild == NULL)<<endl;
			cout<<(temp->rchild == NULL)<<endl;
			return;
		}
		else if (key < temp->data)
			temp = temp->lchild;
		else
			temp = temp->rchild;
	}
	//Element not found. display message
	cout<<key<<" not found in tree!"<<endl;
	return;
}

template <typename T>
int BinarySearchTree<T>::height()
{
	/*
	 * Input : None
	 * Utility : Calculate height of tree (Iterative) using Queue.
	 * Output : Height of tree
	 */

	//if tree is empty, return 0.
	if (this->isEmpty())
	{
		return 0;
	}
	//Else, calculate height.
	int tree_height = 0;
	Queue<BSTNode<T>*> q;
	q.enqueue(root);
	while(1)
	{
		int nodeCount = q.size();
		if (nodeCount == 0)
		{
			return tree_height;
		}
		tree_height += 1;
		//FIFO structure used to maintain pointers
		while (nodeCount > 0)
		{
			BSTNode<T>* temp = q.dequeue();
			if (temp->lchild != NULL)
				q.enqueue(temp->lchild);
			if (temp->rchild != NULL)
				q.enqueue(temp->rchild);
			nodeCount -= 1;
		}
	}
	//reduce by one as root is always level zero.
	return (tree_height - 1);
}

template <typename T>
void BinarySearchTree<T>::mirror(BSTNode<T>* r)
{
	/*
	 * Input  : None
	 * Utility: Generate mirror of tree.
	 * Output :	None
	 */
	//If tree is not empty, generate mirror (swap left child and right child)
	if (r != NULL)
	{
		//swapping left and right child of current root.
		BSTNode<T>* temp = r->lchild;
		r->lchild = r->rchild;
		r->rchild = temp;
		//recursive call to mirror for further level.
		this->mirror(r->lchild);
		this->mirror(r->rchild);
	}
}

template <typename T>
bool BinarySearchTree<T>::isLeaf(BSTNode<T>* node)
{
	/*
	 * Input : BSTNode
	 * Utility : Determine whether given node is a leaf.
	 * Output : boolean (true/false) value.
	 */
	return ((node->lchild == NULL) && (node->rchild == NULL));
}

template <typename T>
void BinarySearchTree<T>::displayLeaves(BSTNode<T>* node)
{
	/*
	 * Input : node
	 * Utility : Display leaves of the tree (Recursive)
	 * Output : Leaves if tree
	 */
	//using algorithm for in order traversal to display all leaves
	if (this->isEmpty())
	{
		cout<<"Tree Empty !"<<endl;
		return;
	}
	if (node == NULL)
	{
		return;
	}
	this->displayLeaves(node->lchild);
	if (this->isLeaf(node))
	{
		cout<<node->data<<" ";
	}
	this->displayLeaves(node->rchild);
}

template <typename T>
void BinarySearchTree<T>::recursive_inorder_display(BSTNode<T>* node)
{
	/*
	 * Input : None
	 * Utility : Displaying nodes in in-order manner
	 * Output : In-order display
	 */
	if (node == NULL)
	{
		return;
	}
	this->recursive_inorder_display(node->lchild);
	cout<<node->data<<" ";
	this->recursive_inorder_display(node->rchild);
}

template <typename T>
void BinarySearchTree<T>::recursive_preorder_display(BSTNode<T>* node)
{
	/*
	 * Input : None
	 * Utility : Displaying nodes in pre-order manner
	 * Output : Pre-order display
	 */
	if (node == NULL)
	{
		return;
	}
	cout<<node->data<<" ";
	this->recursive_preorder_display(node->lchild);
	this->recursive_preorder_display(node->rchild);
}

template <typename T>
void BinarySearchTree<T>::recursive_postorder_display(BSTNode<T>* node)
{
	/*
	 * Input : None
	 * Utility : Displaying nodes in post-order manner
	 * Output : Post-order display
	 */
	if (node == NULL)
	{
		return;
	}
	this->recursive_postorder_display(node->lchild);
	this->recursive_postorder_display(node->rchild);
	cout<<node->data<<" ";
}

template <typename T>
BinarySearchTree<T> BinarySearchTree<T>::getDuplicate(BSTNode<T>* r_duplicate, BSTNode<T>* r)
{
	/*
	 * Input : root
	 * Utility : Create duplicate of tree (recursive)
	 * Output : Duplicate object of current binary search tree
	 */
	return nullptr;
}

template <typename T>
void BinarySearchTree<T>::displayParents(BSTNode<T>* r)
{
	/*
	 * Input : None
	 * Utility : Display parent nodes along with child
	 * Output : tabular display of parent nodes
	 */
	//if tree is empty, return to call
	if (this->isEmpty())
	{
		cout<<"Tree Empty !"<<endl;
		return;
	}
	if (r == NULL)
	{
		return;
	}
	//Else, use in order traversal to display parent nodes
	this->displayParents(r->lchild);
	if (!this->isLeaf(r))
	{

		cout<<r->data<<"\t|";
		if (r->lchild != NULL)
		{
			cout<<r->lchild->data<<"\t|";
		}
		else
		{
			cout<<"Empty\t|";
		}
		if(r->rchild != NULL)
		{
			cout<<r->rchild->data<<endl;
		}
		else
		{
			cout<<"Empty"<<endl;
		}
	}
	this->displayParents(r->rchild);
}

template <typename T>
void BinarySearchTree<T>::level_order_display(BSTNode<T>* t)
{
	/*
	 * Input : None
	 * Utility : Display tree in level order
	 * Output : Level order display of tree
	 */
	//If tree is empty, return to call
	if (this->isEmpty())
	{
		cout<<"Tree Empty!"<<endl;
		return;
	}
	Queue<BSTNode<T>*> q;
	while(t != NULL)
	{
		cout<<t->data<<" ";
		if (t->lchild != NULL)
			q.enqueue(t->lchild);
		if (t->rchild != NULL)
			q.enqueue(t->rchild);
		if (!q.isEmpty())
			t = q.dequeue();
		else
		{
			return;
		}
	}
}

template <typename T>
void BinarySearchTree<T>::iterative_inorder_display()
{
	if (root == NULL)
	{
		cout<<"Tree Empty !"<<endl;
		return;
	}
	Stack<BSTNode<T>*> s;
	BSTNode<T>* top = root;
	while(top != NULL || !s.isEmpty())
	{
		while(top != NULL)
		{
			s.push(top);
			top = top->lchild;
		}
		top = s.pop();
		cout<<top->data<<" ";
		top = top->rchild;
	}
}

template <typename T>
void BinarySearchTree<T>::iterative_preorder_display()
{
	if (root == NULL)
	{
		cout<<"Tree Empty!"<<endl;
		return;
	}
	Stack<BSTNode<T>*> nodeStack;
	BSTNode<T>* t = root;
	while(!nodeStack.isEmpty() || t != NULL)
	{
		while(t != NULL)
		{
			cout<<t->data<<" ";
			nodeStack.push(t);
			t = t->lchild;
		}
		if (!nodeStack.isEmpty())
		{
			t = nodeStack.pop();
			t = t->rchild;
		}
	}
}

template <typename T>
void BinarySearchTree<T>::iterative_postorder_display()
{
	if (root == NULL)
	{
		cout<<"Tree Empty!"<<endl;
		return;
	}
	Stack<BSTNode<T>*> nodeStack;
	Stack<int> flagStack;
	int flag = 0;
	BSTNode<T>* t = root;
	do
	{
		while(t != NULL && flag == 0)
		{
			nodeStack.push(t);
			flagStack.push(1);
			t = t->lchild;
		}
		if(!nodeStack.isEmpty())
		{
			t = nodeStack.pop();
			flag = flagStack.pop();
			if (flag == 1)
			{
				nodeStack.push(t);
				flagStack.push(2);
				t = t->rchild;
				flag = 0;
			}
			else
			{
				cout<<t->data<< " ";
			}
		}
	}while(!nodeStack.isEmpty());
}

template <typename T>
void BinarySearchTree<T>::iterative_insert(T data)
{
	/*
	 * Input : data
	 * Utility : Create and place new node in tree
	 * Output : None
	 */
	//If tree is empty, add node to root.
	if (this->isEmpty())
	{
		root = this->getNode(data);
		return;
	}
	//Else locate position of node using 2 pointers
	BSTNode<T>* P = root;
	BSTNode<T>* Q = root;
	while (Q != NULL && data != P->data)
	{
		P = Q;
		//traverse to left if data is less than value at P
		if (data < P->data)
			Q = P->lchild;
		//traverse to right if data is less than value at P
		if (data > P->data)
			Q = P->rchild;
	}
	//If duplication is found, return to call
	if (data == P->data)
	{
		cout<<"Duplication not allowed!"<<endl;
		return;
	}
	//Insert node at left if value is less than that of P
	if (data > P->data)
	{
		P->rchild = this->getNode(data);
	}
	//Insert node at right if value is less than that of P
	else
	{
		P->lchild = this->getNode(data);
	}
}
