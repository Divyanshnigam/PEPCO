#include<iostream>
using namespace std;
class node
{
	public:
	node*next;
	int data;
	node(int d)
	{
	    next=NULL;
		data=d;
	}
};
void insertatTail(node*&head,int data)
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
void insertAThead(node*&head,int data)
{
    node* n= new node(data);
    n->next=head;
    head=n;
}
void print(node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}
void buildlist(node*&head)
{
	int data;
	cin>>data;
	while(data!=-1)
	{
		insertatTail(head,data);
		cin>>data;
	}
}
int main()
{
	node*head=NULL;
	buildlist(head);
	print(head);
	return 0;
}
