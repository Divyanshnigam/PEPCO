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
	if(d==-1)
	{
		return NULL;
	}
	node* root=new node(d);
	root->left=buildtree();
	root->right=buildtree();
	return root;
}
int height(node*root)       //height of the tree including all levels
{
	if(root==NULL)
	{
		return 0;
	}
	int ls=height(root->left);  //height of left subtree
	int rs=height(root->right); //height of right subtree
	return max(ls,rs)+1;        //returning the total height
}
int diameter(node*root)
{
	if(root=NULL)
	{
		return NULL;
	}
	int h1=height(root->left);       //initialised with the height of left root
	int h2=height(root->right);      //initialised with the height of right root
	int opt1=h1+h2;                  //sum of the left most and the the right most children height
	int opt2=diameter(root->left);   //diameter of left root children 
	int opt3=diameter(root->right);  //diameter of right root children
	return max(opt1,max(opt2,opt3));  //return the maximum diameter
}
int main()
{
	node*root=buildtree();
	cout<<diameter(root);
	return 0;
}
