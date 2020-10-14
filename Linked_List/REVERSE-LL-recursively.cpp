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
node* rec_reverse(node*&head)
{
	//smallest linked list
	if(head==NULL or head->next==NULL)
	{
		return head;
	}
	// rec case
	node* smhead=rec_reverse(head->next);  // reached the last node as smhead
	                                         //head is now the prev to smhead
	head->next->next=head;             //made smhead to point to head in reverse order
	head->next=NULL;                   //rec. returning the rest pointing reverse
	return smhead;
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
    head=rec_reverse(head);
    print(head);
	return 0;
}
