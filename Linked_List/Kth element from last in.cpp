#include<iostream>
using namespace std;
class  node
{
	public:
		int data;
		node*next;
		node(int d)
		{
			data =d;
			next=NULL;
		}
};
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
node*fndlst(node*head,int k)
{
	node*fast=head;
	node*slow=head;
	while(k--)
	{
		fast=fast->next;
	}
	while(fast!=NULL)
	{
		fast=fast->next;
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
	int k;
	cin>>k;
	node*m=fndlst(head,k);
	cout<<m->data;
	return 0;
}
