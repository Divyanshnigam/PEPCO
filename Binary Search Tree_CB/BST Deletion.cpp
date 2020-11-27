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
node* insertInBST(node *root,int data){
    //Base Case
    if(root==NULL){
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}
node* build(){
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin>>d;

    node*root = NULL;

    while(d!=-1){
        root = insertInBST(root,d);
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

node* deleteinBST(node*root,int data)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(data<root->data)
	{
		root->left=deleteinBST(root->left,data);
		return root;
	}
	else if(data==root->data)
	{
		//1.node with 0 child- LEAF NODE
		if(root->left==NULL and root->right==NULL)
		{
			delete root;
			return root;
		}
		//2.node with 1 child
		if(root->left!=NULL and root->right==NULL)       //no right child
		{
			node*temp=root->left;      //storing the left subtree in temp
			delete root;               //then deleting the root
			return temp;               //returning the left subtree root to the node above the deleted root node
		}
		if(root->right!=NULL and root->left==NULL)      //no left child
		{
			node*temp=root->right;
			delete root;
			return temp;
		}
		//3.node with 2 children***special case
		node* replace= root->right;
		//find the inorder successor from right subtree
		while(replace->left!=NULL)      //since the left of the sunbtree is balanced no change is needed. root is replaced with the right subtree's left or the last element 
		{                                 //that is taking the pointer to shortest element of right subtree and then
			replace=replace->left;      
		}	
		root->data=replace->data;
		root->right=deleteinBST(root->right,replace->data);
		return root;
	}
	else
	{
		root->right=deleteinBST(root->right,data);
		return root;
	}
}
//Inorder Print
void inorder(node*root)
{
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}
int main()
{
	node*root=build();
    inorder(root);
	int d;
	cin>>d;
	root=deleteinBST(root,d);
	inorder(root);
	cout<<endl;
	bfs(root);
	return 0;
}
/*
i/p:
  5 3 7 1 6 8 -1
o/p:
1,3,5,6,7,8,
3
1,5,6,7,8,
5,
1,7,
6,8,
*/
