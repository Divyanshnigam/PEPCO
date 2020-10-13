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
bool searchiterative(node*head,int key)
{
	while(head!=NULL)
	{
		if(head->data==key)
		{
			return true;
		}
		head=head->next;
	}
	return false;
}
bool searchRecursive(node*head,int key)
{
	if(head==NULL)
	{
		return false;
	}
	if(head->data==key)
	{
		return true;
	}
	else
	{
		return searchRecursive(head->next,key);
	}
}
void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ->";
        head=head->next;
    }
    cout<<endl;
}

int main() 
{
    node*head=NULL;
    insertAThead(head,5);
    insertAThead(head,4);
    insertAThead(head,3);
    insertATtail(head,6);
    insertATmiddle(head,2,3);
    print(head);
    cout<<endl;
    int key=4;
    
    if(searchRecursive(head,key))
    {
    	cout<<"present";
	}    
	else
	{
		cout<<"not present";
	}
	if(searchiterative(head,key))
    {
    	cout<<"present";
	}    
	else
	{
		cout<<"not present";
	}
    return 0;
}
