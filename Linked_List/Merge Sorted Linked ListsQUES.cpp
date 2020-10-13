#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node*next;
	node(int d)
	{
		data=d;
		next=NULL;
	}
};
node*merge(node*a,node*b)
{
	if(a==NULL)
	{
		return b;
	}
	else if(b==NULL)
	{
		return a;
	}
	node*c;
	if(a->data<b->data)
	{
		c=a;
		c->next=merge(a->next,b);
	}
	else
	{
		c=b;
		c->next=merge(a,b->next);
	}
	return c;
}
void insertattail(node*&head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node*tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	tail->next=new node(data);
	return;
}
void buildlist(node*&head,int n)
{
	int data;
	while(n--)
	{
		cin>>data;
		insertattail(head,data);
	}
}
void print(node*head)
{
	node*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main()
{

	int t,m,n;
	cin>>t;
    for(int i=0;i<t;i++)
	{
		node*head=NULL;
    	node*head2=NULL;
		cin>>n;
        buildlist(head,n);
	    cin>>m;
	    buildlist(head2,m);
        head=merge(head,head2);
        print(head);
    }
   
    return 0;
}
