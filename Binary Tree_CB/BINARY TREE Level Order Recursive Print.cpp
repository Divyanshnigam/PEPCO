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
void printkthlevel(node*root,int k)
{
	if(root==NULL)
	{
		return;
	}
	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}
	printkthlevel(root->left,k-1);
	printkthlevel(root->right,k-1);
	return ;
}
void printalllevels(node*root)
{
	int h=height(root);
	for(int i=1;i<h;i++)
	{
		printkthlevel(root,i);
		cout<<endl;
	}
	return ;
}
int main()
{
	node*root=buildtree();
	printalllevels(root);
	return 0;
}
/*
i/p:
	8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 13 -1 -1 -1
o/p:
    8
    10 3
    1 6 13
*/	
