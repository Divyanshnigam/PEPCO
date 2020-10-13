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
void buildlist(node*&head,int n)
{
	int data;
	while(n--)
	{
		cin>>data;
		insertattail(head,data);
	}
}
node*place(node*&head)
{
	node*tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
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
int main()
{
	node* head=NULL;
	int n;
	cin>>n;
	buildlist(head,n);
	place(head);
	print(head);
	return 0;
}
