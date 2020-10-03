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
void in_range(node* root,int a,int b)
{
	if(root==NULL)
	{
		return ;
	}
	if(root->data>a and root->data>b)
	{
		in_range(root->left,a,b);
	}
	else if(root->data<a and root->data<b)
	{
		in_range(root->right,a,b);
	}
	else
	{
		in_range(root->left,a,b);
		cout<<root->data<<endl;
		in_range(root->right,a,b);
	}
}
int main()
{
	node* root=build();
	bfs(root);
	cout<<endl;
	int a,b;
	cin>>a>>b;
	in_range(root,a,b);
	cout<<endl;
	bfs(root);
}
/*
5 3 7 1 6 8 -1
5,
3,7,
1,6,8,

3
7
3
5
6
7

5,
3,7,
1,6,8,
*/
