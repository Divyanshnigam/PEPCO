#include<iostream>
using namespace std;
class node{
	public:
		long long int data;
		node* next;
		node(long long int d)
		{
			data=d;
			next=NULL;
		}
};
void insertattail(node* &head,long long int data)
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
	return ;	
}
int length(node*head)
{
	long long int len=0;
	while(head!=NULL)
	{
		head=head->next;
		len+=1;
	}
	return len;
}
node* kappend(node* &head, int k)
{
	long long int t=length(head)-k+1;    //7-3+1=5th element
	node* temp=head;  //1
	node* prv=temp;   //1
	node* cur=temp->next;    //2
	for(int i=0;i<t-2;i++)   //3--
	{
		prv=prv->next; // 2  3  4
		cur=cur->next;//  3  4  5
	}
	prv->next=NULL;   //4=NULL
	node* todo=cur;  //5
	while(todo->next!=NULL)
	{
		todo=todo->next; //7
	}
	todo->next=temp;   //7->1
	head=cur;     //5=>head
	return head;
}
void print(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
int main()
{
	node* head=NULL;
	long long int n,k,data;
	cin>>n;
	while(n--)
	{
		cin>>data;
		insertattail(head,data);
	}
	cin>>k;
	kappend(head,k);
	print(head);	
	return 0;
}
