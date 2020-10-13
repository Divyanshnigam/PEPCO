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
void insertathead(node*&head,int data)
{
	node*n=new node(data);
	n->next=head;
	head=n;
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
void print(node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}
node* mid(node*head)
{
	if(head==NULL or head->next==NULL)
	{
		return head;
	}
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL and fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}
void buildlist(node*&head)
{
	int data;
	cin>>data;
	while(data!=-1)
	{
		insertattail(head,data);
		cin>>data;
	}
}
int main()
{
	node*head=NULL;
	buildlist(head);
	print(head);
	node*m=mid(head);
	cout<<m->data<<endl;
	return 0;
}
