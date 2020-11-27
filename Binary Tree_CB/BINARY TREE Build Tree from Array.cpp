#include<iostream>
#include<queue>
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
void bfs(node*root)        //to print the tree 
{
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node*f=q.front();
		if(f==NULL)
		{
			cout<<endl;
			q.pop();
			if(!q.empty())
			{
				q.push(NULL); 
			}
		}
		else
		{
			cout<<f->data<<",";
			q.pop();
			if(f->left)
			{
				q.push(f->left);
			}
			if(f->right)
			{
				q.push(f->right); 
			}
		}
	}
	return ;
}
node* buildtreefromarray(int *a,int s,int e)
{
	if(s>e)
	{
		return NULL;
	}
	int mid=(s+e)/2;
	node*root=new node (a[mid]);                      //starting from the mid of the array 
	root->left=buildtreefromarray(a,s,mid-1);         //inserting in the left if of lesser index
	root->right=buildtreefromarray(a,mid+1,e);        //else in the right
	return root;                                      //and from the last root returns
}
int main()
{
	int a[]={1,2,3,4,5,6,7};
	int n=7;
	node*root=buildtreefromarray(a,0,n-1);
	bfs(root);
	return 0;
}
