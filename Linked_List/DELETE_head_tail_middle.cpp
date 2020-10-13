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
		node* head=new node(data);
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

void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}
void deleteattail(node*&head)
{
	node*prev=NULL;
	node*temp=head;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	delete temp;
	prev->next=NULL;
	return;
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
int main() 
{
    node*head=NULL;
    insertAThead(head,5);
    insertAThead(head,4);
    insertAThead(head,3);
    insertATtail(head,6);
    insertATmiddle(head,2,3);
    deleteathead(head);
    deleteattail(head);
    print(head);
    return 0;
}
