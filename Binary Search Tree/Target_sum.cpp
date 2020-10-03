#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

//Accepts the old root node & data and returns the new root node 
node* insertinBST(node *root,int data){
    //Base Case
    if(root==NULL){
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if(data<=root->data){
        root->left = insertinBST(root->left,data);
    }
    else{
        root->right = insertinBST(root->right,data);
    }
    return root;
}

bool search(node*root,int data){
    if(root==NULL){
        return false;
    }
    if(root->data==data){
        return true;
    }
    //Recursively search in left and right subtree
    if(data<=root->data){
        return search(root->left,data);
    }
    else{
        return search(root->right,data);
    }
}

node* build(){
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin>>d;

    node*root = NULL;

    while(d!=-1){
        root = insertinBST(root,d);
        cin>>d;
    }
    return root;
}
//Print the BST Level By Level
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
bool find(node*root,int data)
{
	if(root==NULL)
	{
		return false;
	}
	if(data>root->data)
	{
		find(root->right,data);
	}
	else if(data<root->data)
	{
		find(root->left,data);
	}
	else
	{
		return true;
	}
}
void target_sum(node* root_u,node* root,int tar)
{
	if(root==NULL)
	{
		return;
	}
	target_sum(root_u,root->left,tar);
	int c=tar-root->data;
	if(root->data<c)
	{
		if(find(root_u,c)==true)
		{
			cout<<root->data<<" - "<<c<<endl;
			
		}
	}
	target_sum(root_u,root->right,tar);
}
int main()
{
	node*root=build();
	bfs(root);
	
	int tar;
	cin>>tar;
	target_sum(root,root,tar);
}
/*
50 25 12 37 30 75 62 60 70 87 -1
50,
25,75,
12,37,62,87,
30,60,70,
100
25 - 75
30 - 70
*/
