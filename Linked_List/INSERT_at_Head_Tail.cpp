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
void insertAThead(node*&head,int data)
{
    node* n= new node(data);
    n->next=head;
    head=n;
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
    print(head);
    return 0;
}
