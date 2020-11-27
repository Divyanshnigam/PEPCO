#include<iostream>
#include<queue>
using namespace std;
class node
{
	public:
		int data;
		node*left;
		node*right;
		node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
};
node*  insertinBST(node*root,int data)
{
	if(root==NULL)
	{
		return new node(data);
	}
	if(data<root->data)
	{
		root->left=insertinBST(root->left,data);
	}
	else
	{
		root->right=insertinBST(root->right,data);
	}
	return root;
}
class linkedlist
{
	public:
		node* head;
		node* tail;
};
linkedlist flatten(node*root)
{
	linkedlist l;
	
}
node* build()
{
	node*root=NULL;
	int d;
	cin>>d;
	if(d!=-1)
	{
		insertinBST(root,d);
		cin>>d;
	}
	return root;
}
