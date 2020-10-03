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

int size(node*root)
{
	if(root==NULL)
	{
		return 0;
	}
	int ls=size(root->left);
	int rs=size(root->right);
	int ts=ls+rs+1;
	return ts;
}
int sum(node*root)
{
	if(root==NULL)
	{
		return 0;
	}
	int ls=sum(root->left);
	int rs=sum(root->right);
	
	return ls+rs+root->data;
}
int max(node*root)
{
	
	if(root->right!=NULL)
	{
		return max(root->right);
	}
	else
	{
		return root->data;
	}
}
int min(node*root)
{
	
	if(root->left!=NULL)
	{
		return min(root->left);
	}
	else
	{
		return root->data;
	}
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
int main()
{
	node*root=build();
	bfs(root);
	cout<<size(root)<<endl;
	cout<<sum(root)<<endl;
	cout<<max(root)<<endl;
	cout<<min(root)<<endl;
	int data;
	cin>>data;
	if(find(root,data))
	{
		cout<<"present";
	}
	else{
		cout<<"No Not!!";
	}
}
