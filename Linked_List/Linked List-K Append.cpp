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
int length(node*head)
{
	int len=0;
	while(head!=NULL)
	{
		head=head->next;
		len++;
	}
	return len;
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
void append(node*&head,int k)
{
	node*temp=head;
	node*ptr1=head;
	node*ptr2=head;
	while((length(head)-k)>0)
	{
		head=head->next;
	}
	while((length(head)-k-1)>0)
	{
		ptr1=ptr1->next;		
	}
	ptr1->next=NULL;
	while(length(head)>0)
	{
		ptr2=ptr2->next;
	}
	ptr2->next=temp;
}
int main()
{
	node* head=NULL;
	int n,k;
	cin>>n;
	buildlist(head,n);
	cin>>k;
	append(head,k);
	print(head);
	return 0;
}
