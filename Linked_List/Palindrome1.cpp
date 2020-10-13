#include <iostream>
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
int length(node*head)
{
	int len=0;
	while(head!=NULL)
	{
		head=head->next;
		len+=1;
	}
	return len;
}
void insertATtail(node*&head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}	
	node* tail=head;
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
void insertATmiddle(node*&head,int data,int p)
{
	if(head==NULL or p==0)
	{
		insertAThead(head,data);
	}
	else if(p>length(head))
	{
		insertATtail(head,data);
	}
	else
	{
		int jump=1;
		node*temp=head;
		while(jump<=p-1)
		{
			temp=temp->next;
			jump+=1;
		}
		node* n=new node(data);
		n->next=temp->next;
		temp->next=n;
	}
}


void reverse(node*&head)
{
	node*c=head;
	node*p=NULL;
	node*n=NULL;
	while(c!=NULL)
	{
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
	head=p;
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

int main() 
{
    node*head=NULL;
    node*head1=NULL;
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>data;
    	insertATtail(head,data);
	}
	print(head);
	reverse(head);
	cout<<endl;
	print(head);
	cout<<endl;
	while(head!=NULL)
	{
		head1->data=head->data;  //???????????????????????
		head1->next=head->next;
		head=head->next;
		head1=head1->next;
	}
	print(head1);
    return 0;
}
