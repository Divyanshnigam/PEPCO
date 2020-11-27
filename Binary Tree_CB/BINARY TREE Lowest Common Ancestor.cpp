#include<iostream>
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
node* buildtree()
{
	int d;
	cin>>d;
	if(d==NULL)
	{
		return NULL;
	}
	node*root=new node(d);
	root->left=buildtree();
	root->right=buildtree();
	return root;
}
node* lca(node*root,int a,int b)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->left==a or root->right==b)   //the condition when any node is the ancenstor of the other node then that top most root node is LCA
	{
		return root;
	}
	node*leftans=lca(root->left,a,b);
	node*rightans=lca(root->right,a,b);
	if(leftans!=NULL and rightans!=NULL) //when returning the addresses of two founded node the addresses are returned both from the left and the right trees 
	{
		return root;
	}
	if(leftans!=NULL)                   //everytime when node found on left tree so, returning that address and right tree returns NULL as node not found
	{
		return leftans;
	}
	return rightans;                   //else return right node address
}
int main()
{
	node*root=buildtree();
	int a,b;
	cout<<"LCA of 7 and 9 is "<<lca(root,7,9)->data<<endl;
	cout<<"LCA of 10 and 7 is "<<lca(root,10,7)->data<<endl;
	
}
/*
 i/p:
    8 10 7 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
 o/p:
    10
	10
 */
