//Since level order recursive is of 0(N^2) complexity. Now BFS Traversal-2 with 0(N) complexity
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
node* buildtree()
{                                                     //              {8}  
	int d;                                            //      {10}            {3}
	cin>>d;                                           //   {7}   {6}            {14}
	if(d==-1)                                         //       {9} {7}       {3}
	{
		return NULL;
	}
	node*root=new node(d);
	root->left=buildtree();
	root->right=buildtree();
	return root;
}
void bfs(node*root)
{
	queue<node*>q;              //created an empty queue
	q.push(root);               //pushed the 1st root 
	q.push(NULL);               //****change made**** As 1st root encountered then also push the NULL as to change the line.
	while(!q.empty())            
	{
		node*f=q.front();          //f will hold the front element
		//***************changes made******************//
		
		if(f==NULL)
		{
			cout<<endl;           //for every NULL change the line
			q.pop();              //then pop NULL with a condition
			if(!q.empty())
			{
				q.push(NULL);     //if no children further present then no need to push the NULL			
			}
        }
        else
        { 
		//***************changes made******************//
		
		cout<<f->data<<",";       //pick one node at front print it
		q.pop();                  //pop it
		if(f->left)               //push its children just after poping that node
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
int main()
{
	node*root= buildtree();
	bfs(root);
	return 0;
		
}
/*
 i/p:
    8 10 7 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
 o/p:
    8,
   10,3,
   7,6,14,
   9,7,13, */
