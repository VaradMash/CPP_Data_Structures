//Combine recursive and iterative traversal

#include <iostream>
#include "BST_Implementation.cpp"
#include "BST.h"
using namespace std;

int main()
{
	cout<<"Binary Search Tree"<<endl;
	BinarySearchTree<int> bst;
	int choice;
	do
	{
		cout<<"\n**************Menu*************"<<endl;
		cout<<"0. Iterative insert"<<endl;
		cout<<"1. Insert Node"<<endl;
		cout<<"2. Search Tree"<<endl;
		cout<<"3. Mirror image"<<endl;
		cout<<"4. Height of tree"<<endl;//fault
		cout<<"5. Level Order Display "<<endl;
		cout<<"6. Display Leaves"<<endl;
		cout<<"7. Traversal (Recursive)"<<endl;
		cout<<"8. Traversal (Non Recursive)"<<endl;
		cout<<"9. Search Tree (Recursive)"<<endl;
		cout<<"10.Height (Recursive)"<<endl;
		cout<<"11.Create duplicate"<<endl;
		cout<<"12.Display Parent nodes"<<endl;
		cout<<"13.Delete Node"<<endl;
		cout<<"14.Exit"<<endl;
		cout<<"*****************************"<<endl;
		cout<<"Enter Choice Code : ";
		cin>>choice;
		switch(choice)
		{
		case 0:
		{
			int data;
			cout<<"\nEnter Data : "<<endl;
			cin>>data;
			bst.iterative_insert(data);
			break;
		}
		case 1:
		{
			int data;
			cout<<"\nEnter Data : "<<endl;
			cin>>data;
			bst.recursive_insert(bst.getRoot(), data);
			break;
		}
		case 2:
		{
			int data;
			cout<<"\nEnter Data to be searched : "<<endl;
			cin>>data;
			bst.searchTree(data);
			break;
		}
		case 3:
		{
			bst.mirror(bst.getRoot());
			cout<<"\nInorder :"<<endl;
			bst.recursive_inorder_display(bst.getRoot());
			cout<<endl;
			cout<<"\nPreorder : "<<endl;
			bst.recursive_preorder_display(bst.getRoot());
			cout<<endl;
			cout<<"\nPostOrder"<<endl;
			bst.recursive_postorder_display(bst.getRoot());\
			cout<<endl;
			bst.mirror(bst.getRoot());
			break;
		}
		case 4:
		{
			cout<<"\nHeight of current tree : "<<bst.height()<<endl;
			break;
		}
		case 5:
		{
			bst.level_order_display(bst.getRoot());
			break;
		}
		case 6:
		{
			cout<<"Leaf Nodes are : "<<endl;
			bst.displayLeaves(bst.getRoot());
			cout<<endl;
			break;
		}
		case 7:
		{
			cout<<"\nInorder :"<<endl;
			bst.recursive_inorder_display(bst.getRoot());
			cout<<endl;
			cout<<"\nPreorder : "<<endl;
			bst.recursive_preorder_display(bst.getRoot());
			cout<<endl;
			cout<<"\nPostOrder"<<endl;
			bst.recursive_postorder_display(bst.getRoot());
			cout<<endl;
			break;
		}
		case 8:
		{
			cout<<"\nInorder"<<endl;
			bst.iterative_inorder_display();
			cout<<"\nPre Order"<<endl;
			bst.iterative_preorder_display();
			cout<<"\nPost Order"<<endl;
			bst.iterative_postorder_display();
			break;
		}
		case 9:
		{
			int data;
			cout<<"\nEnter Data to be searched : "<<endl;
			cin>>data;
			bst.searchTree_recursive(data, bst.getRoot());
			break;
		}
		case 10:
		{
			int h = bst.height_recursive(bst.getRoot());
			cout<<"Height : "<<h;
			break;
		}
		case 11:
		{
			BinarySearchTree<int> bst1;
			bst1.setRoot(bst.getDuplicate(bst.getRoot()));
			cout<<"\nInorder :"<<endl;
			bst1.recursive_inorder_display(bst.getRoot());
			cout<<endl;
			cout<<"\nPreorder : "<<endl;
			bst1.recursive_preorder_display(bst.getRoot());
			cout<<endl;
			cout<<"\nPostOrder"<<endl;
			bst1.recursive_postorder_display(bst.getRoot());\
			cout<<endl;
			break;
		}
		case 12:
		{
			cout<<"Parent\t|LChild\t|RChild"<<endl;
			bst.displayParents(bst.getRoot());
			break;
		}
		case 13:
		{
			int data;
			cout<<"Enter node to be deleted : ";
			cin>>data;
			bst.delete_node(data, bst.getRoot());
			break;
		}
		case 14:
		{
			break;
		}
		default:
			cout<<"Invalid choice!"<<endl;
			break;
		}
	}while(choice != 14);
	cout<<"\nThank You !"<<endl;
	return 0;
}
