#include<iostream> 
#include<string>
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
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}
void pathinrange(node* root,string path,int sum,int lb,int ub)
{
	if(root=NULL)
	{
		return;
	}
	if(root->left==NULL and root->right==NULL)
	{
		sum+=root->data;
		if(sum<=ub and sum>=lb)
		{
			cout<<path + to_string(root->data)<<endl;   // ??????????
		}
		return;
	}
	pathinrange(root->left, path + to_string(root->data) + " " ,sum+root->data,lb,ub);
	pathinrange(root->right, path + to_string(root->data) + " " ,sum+root->data,lb,ub);
}
int main()
{
    node* root=buildtree();
    int lb=150;
    int ub=250;
    pathinrange(root,"",0,lb,ub);

    
}/*
50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
3
o/p:
30
70
*/

