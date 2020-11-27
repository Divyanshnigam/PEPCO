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
int count(node*root)
{
	if(root==NULL)
	{
		return 0;
	}
	return 1+count(root->left)+count(root->right);
}
int main()
{
	node*root=buildtree();
	cout<<count(root)<<endl;
	return 0;
}
/*
i/p:
  8 10 7 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
o/p:
  9
*/
