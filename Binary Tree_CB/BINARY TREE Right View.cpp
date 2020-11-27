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
void printrightview(node*root,int level,int &maxlevel)
{
	if(root==NULL)
	{
		return ;
	}
	if(maxlevel<level)
	{                       //have discovered a new level
		cout<<root->data<<" ";
		maxlevel=level;
	}
	printrightview(root->right,level+1,maxlevel);  //right node__ For each new current level>maxlevel print the right most node as a root
	printrightview(root->left,level+1,maxlevel);   //left node	
}
int main()
{
	node*root=buildtree();
	int maxlevel=-1;
	printrightview(root,0,maxlevel);
    return 0;
}
/*
i/p:
8 10 7 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
o/p:
8 3 14 13
*/
