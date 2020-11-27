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
{                                                     //             {10}  
	int d;                                            //      {2}            {10}
	cin>>d;                                           // {20}    {1}             {-25}
	if(d==-1)                                         //                      {3}    {4}
	{
		return NULL;
	}
	node*root=new node(d);
	root->left=buildtree();
	root->right=buildtree();
	return root;
}
class Pair 
{
	public:
		int branchsum;                    //branch is distance of the root to any of the left or to the right.
		int maxsum;                       //max is the distance covering atleast or atmost branches in order to get maxsum
		Pair()
		{
			branchsum=0;
			maxsum=0;
		}
};
Pair maxsumpath(node*root)
{
	Pair p;
	if(root==NULL)
	{
		return p;				          //0
	}
	Pair left=maxsumpath(root->left);     //iterate over the left part of the root returning p from last 
	Pair  right=maxsumpath(root->right);  //iterate over the right part of the root returning p from last
	
// four options to get max sum 
    int op1=root->data;                            //left and right descends are negative then return the root as max sum
	int op2=left.branchsum +root->data;            //right descend is negative then return the root and the left of root 
	int op3=right.branchsum+root->data;            //left descend is negative then return the root and the right of root 
	int op4=right.branchsum+left.branchsum+root->data;   //return root with left and right branches as none are negative
//four options megered as maximum as below for maxsum
	int current_ans_through_root=max(op1,max(op2,max(op3,op4))); //maximum sum of 4 options OP is assigned
//branch sum of current root
    p.branchsum=max(left.branchsum,max(right.branchsum,0))+root->data;   //max with zero because if all branchsum are negative then return 0.
    p.maxsum=max(left.maxsum,max(right.maxsum,current_ans_through_root));
    return p;
}
int main()
{
	node*root=buildtree();
	cout<<"max Sum path "<<maxsumpath(root).maxsum<<endl;
	return 0;	
}
/*
i/p:
 10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1
o/p:
 max Sum path 42
*/
