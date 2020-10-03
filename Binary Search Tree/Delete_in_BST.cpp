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
node* deleteinbst(node* root,int data)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(data>root->data)
	{
		root->right=deleteinbst(root->right,data);
	}
	else if(data<root->data)
	{
		root->left=deleteinbst(root->left,data);
	}
	else
	{
		// here data=root->data
		if(root->left!=NULL and root->right!=NULL)
		{
			int lmax=max(root->left);
			root->data=lmax;
			root->left=deleteinbst(root->left,lmax);
			return root;
		}
		else if(root->left!=NULL)
		{
			return root->right;
		}
		else if(root->right!=NULL)
		{
			return root->right;
		}
		else
		{
			return NULL;
		}
	}
	return root;
}
int main()
{
	node*root=build();
	bfs(root);
	int data;
	cin>>data;
	deleteinbst(root,data);
	bfs(root);
}
