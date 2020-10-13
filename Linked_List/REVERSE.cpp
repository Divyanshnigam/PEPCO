#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node*next;
		node(int data)
		{
			this->data=data;
			next=NULL;
		}
};
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
    insertAThead(head,2);
    print(head);
    reverse(head);
    print(head);
	return 0;
}
