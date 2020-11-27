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

//FINDING THE LEVEL OF A GIVEN NODE FROM THE ROOT NODE/ANY GIVEN NODE.
int search(node*root ,int key,int level)     //
{
	if(root==NULL)
	{
		return -1;                           //no descended root
	}
	if(root->data==key)
	{
		return level;                       //return that level i.e. 0
	}
	int left=search(root->left,key,level+1) //itrating left untill node found
	if(root->left!=-1)                      //till not found i.e. root!=NULL
	{
		return left;                        //return left address
	}
	return search(root->right,key,level+1); //else move rightwards
}
//FUNCTION TO FIND THE DISTANCE BTW TWO NODES
int finddistance(node*root,int a,int b)
{
	node*lca_node=lca(root,a,b);           //finding the common ancesestor
	int l1=search(lca_root,a,0);           //level of lca_root is 0 and this l1 assigns with the distance of common root to that nodes
	int l2=search(lca_root,b,0);
	return l1+l2;                         //sum of them is the shortest btw two node
}
int main()
{
	node*root=buildtree();
	cout<<"distance btw 9 and 7 is "<<finddistance(root,9,7)->data<<endl;
	cout<<"distance btw 7 and 14 is "<<finddistance(root,7,14)->data<<endl;
	
}
/*
 i/p:
    8 10 7 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
 o/p:
    2
	5
 */
