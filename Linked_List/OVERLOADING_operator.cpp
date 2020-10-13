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
istream& operator>>(istream &is,node*&head)
{
	buildlist(head);
	return is; 
}
ostream& operator<<(ostream &os,node*&head)
{
	print(head);
	return os;
}
int main()
{
	node*head=NULL;
	node*head2=NULL;
	cin>>head>>head2;
	cout<<head<<endl<<head2;
	return 0;
}

/* input as:
            1 2 3 -1
            4 5 6 -1
    output:
            1->2->3->

            4->5->6->  */
