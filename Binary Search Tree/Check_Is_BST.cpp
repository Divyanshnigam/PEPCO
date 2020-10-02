#include<iostream>
#include<climits>
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
node* insertinbst(node* root,int data)
{
	if(root==NULL)
	{
		return new node(data);
	}
	if (data<=root->data)
	{
		insertinbst(root->left,data);
	}
	else
	{
		insertinbst(root->right,data);
	}
	return root;
}
node* build()
{
	node* root=NULL;
	int d;
	cin>>d;
	while(d!=-1)
	{
		root=insertinbst(root,d);
		cin>>d;
	}
	return root;
}
bool is_bst(node* root,int minv=INT_MIN,int maxv=INT_MAX)
{
	if(root==NULL)
	{
		return true;
	}
	if(root->data>=minv and root->data<=maxv and is_bst(root->left,minv,root->data) and is_bst(root->right,root->data,maxv))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
int main()
{
	node* root=build();
	if(is_bst(root))
	{
		cout<<"yes";
	}
	else
	{
		cout<<"no";
	}
}
/*
5 3 7 1 6 8 -1
yes
*/
