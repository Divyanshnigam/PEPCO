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
}/*
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
	
}*/
class info
{
	public:
		int size;
		int max;
		int min;
		int ans;
		bool is_bst;
};
info larg_BST(node* root)
{
	if(root==NULL)
	{
		return {0,INT_MIN,INT_MAX,0,true};
	}
	if(root->left==NULL and root->right==NULL)
	{
		return {1,root->data,root->data,1,true};
	}
	info l=larg_BST(root->left);
	info r=larg_BST(root->right);
	
	info i;
	i.size=(1+ l.size + r.size);
	
	if(l.is_bst and r.is_bst and l.max<root->data and r.min>root->data)
	{
		i.min=min(l.min,min(r.min,root->data));
		i.max=max(l.max,min(r.max,root->data));
		
		i.ans=i.size;
		i.is_bst=true;
		
		return i;
	}
	
	i.ans=max(l.ans,r.ans);
	i.is_bst=false;
	return i;
}
int main()
{
	node* root=build();
	cout<<larg_BST(root).ans;
}
/*
5 3 7 1 6 8 -1
yes
*/
