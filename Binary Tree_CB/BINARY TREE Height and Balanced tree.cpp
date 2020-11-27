#include<iostream>
#include<cmath>
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
	node*root=new node(d);
	root->left=buildtree();
	root->right=buildtree();
	return root;
}
class HBpair        //pair returning the height and boolean statement is balanced or not
{
	public:
		int height;
		bool balance;
};
HBpair isheightbalance(node*root)
{
	HBpair p;
	if(root==NULL)
	{
		p.height =0;       // pair returning height as 0 since NULL
		p.balance=true;    // and the tree hence, balanced 
		return p;        
    }
   //recursive case
   HBpair left=isheightbalance(root->left);       //check for the left subtree
   HBpair right=isheightbalance(root->right);     //check for the right subtree

   p.height=max(left.height,right.height)+1;                         // containing the max height of the root node 
   if(abs(left.height-right.height)<=1 && left.balance and right.balance)       // if diff. <=1 and the left and the right of the tree is if balanced then true
   {
    	p.balance=true;
   }
   else
   {
    	p.balance=false;
   }
    return p;
}
int main()
{
	node*root=buildtree();
	if(isheightbalance(root).balance)
	{
		cout<<"Balanced";
	}
	else
	{
		cout<<"Not Balanced!!"<<endl;
	}
	return 0;
}
/*
i/p:
8 7 -1 -1 6 -1 -1
o/p:
Balanced
*/
