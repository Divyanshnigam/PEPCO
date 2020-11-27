#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node* left;
		node* right;
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
	if(d==-1)
	{
		return NULL;
	}
	node* root=new node(d);
	root->left=buildtree();
	root->right=buildtree();
	return root;
}
void printin(node*root)         //inoder traversal
{
	if (root==NULL)
	{
		return;
	}                           //else print the left, root and right
	printin(root->left);
	cout<<root->data<<" ";
	printin(root->right);
}
void printpost(node*root)       //postoder traversal
{
	if (root==NULL)
	{
		return;
	}                           //else print the left, right and root
	printin(root->left);
	printin(root->right);
	cout<<root->data<<" ";
}
void printpre(node* root)      //preorder traversal
{
	if(root==NULL)
	{
		return;
	}                         //else print the root, left and right
	cout<<root->data<<" ";
	printpre(root->left);     //left node now become the root and get printed as a root and further printed till left node is null
	printpre(root->right);    //same goes with the right node
}
int main()
{
	node* root=buildtree();
	printpre(root);
	cout<<endl;
	printin(root);
	cout<<endl;
	printpost(root);
	cout<<endl;
	return 0;
}
/*
   i/p:
    8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 13 -1 -1 -1
     
   o/p:    
    8 10 1 6 9 7 3 13
    1 10 9 6 7 8 13 3
    1 10 9 6 7 13 3 8
*/
