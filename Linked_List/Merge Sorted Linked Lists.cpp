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
void print(node*head)
{
	node*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}
node*mergesort()
istream& operator>> (istream &is, node*&head)
{
	buildlist(head);
	return is;
}
ostream& operator<< (ostream &os, node*&head)
{
	print(head);
	return os;
}

int main()
{
	node*head=NULL;
	node*head2=NULL;
	cin>>head>>head2;
	cout<<head<<endl<<head2<<endl;;
	head=merge(head,head2);
	cout<<head;
	
    return 0;
}
