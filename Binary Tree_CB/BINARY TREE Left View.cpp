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
node* insertInBST(node *root,int data){
    //Base Case
    if(root==NULL){
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    while(data!=-1)
    {
        insertInBST(root->left,data);

        insertInBST(root->right,data);
    
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
void printleftview(node*root,int level,int &maxlevel)
{
	if(root==NULL)
	{
		return ;
	}
	if(maxlevel<level)
	{                       //have discovered a new level
		cout<<root->data<<" ";
		maxlevel=level;
	}
	printleftview(root->left,level+1,maxlevel);  //right node__ For each new current level>maxlevel print the right most node as a root
	printleftview(root->right,level+1,maxlevel);   //left node	
}
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

int main()
{
	node*root=build();
	bfs(root);
	int maxlevel=-1;
	printleftview(root,0,maxlevel);
    return 0;
}
/*
i/p:
8 10 7 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
o/p:
8 3 14 13
*/
