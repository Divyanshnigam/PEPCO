#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
		node(int d)
		{
			data=d;
			next=NULL;
		}
};
void print (node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
int length(node* head)
{
	int len=0;
	while(head->next!=NULL)
	{
		head=head->next;
		len++;
	}
	return len;
}

void insertattail(node*head,int data)
{
	if(head==NULL)
	{
		node* n=new node(data);
		head=n;
	}
	node *tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	tail->next=new node(data);
	return;
}
void insertathead(node*&head,int data)
{
	node* n=new node(data);  //assigned data to n
	n->next=head;
	head=n;
}
void insertatmid(node*&head,int data,int p)
{
	if(head==NULL or p==0)
	{
		insertathead(head,data);
	}
	else if(length(head)<p)
	{
		insertattail(head,data);
	}
	else
	{
		node*temp=head;
		int jump=1;
		while(jump<=p-1)
		{
			temp=temp->next;
			jump++;
		}
		
		node* n=new node(data);
		n->next=temp->next;
		temp->next=n;
	}
}
void deleteathead(node*&head)
{
	if(head==NULL)
	{
		return;
	}
	node*temp=head;
	head=head->next;
	delete temp;
	return;
}
void deleteattail(node*&head)
{
	node*temp=head;
	node*prev=NULL;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	delete temp;
	prev->next=NULL;
	return;
}
int main()
{
	node*head=NULL;
	int data,p;
	cin>>data;
	while(data!=-1)
	{
		insertathead(head,data);
		insertattail(head,data);
		cin>>data;
	}
	cin>>data;
    while(data!=-1)
	{
		cin>>p;
		insertatmid(head,data,p);
		cin>>data;
	}
	print(head);
	cout<<endl;
	deleteathead(head);
	deleteattail(head);
	print(head);
}
/*
5
4
3
2
1
-1
9 1
8 4
7 3
-1
1 9 2 7 3 8 4 5 5 4 3 2 1
*/
