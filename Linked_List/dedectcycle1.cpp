#include<iostream>
using namespace std; 
// Create a class node for the circular linked list 
class node
{
	public:
		int data;
		node*next;
	node(int data)
	{
		this->data = data; // Refering to data
		//Here the tail pointer would point to head of the node instead of the NULL 
	}
};
// A function which is used to print the list 
void printlist(node *head)
{
	node *temp = head;
	while(temp->next != head)
	{
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
//	cout<<"END";	
}
//A function used to push the node in the linked list 
void push(node *&head , int data)
{
	node *ptr1 = new node(data);
	node *temp = head; 
	ptr1->next = head; 
	if(head != NULL)
	{
		while(temp->next!=head)
		{
			temp = temp->next;
		}
		temp->next = ptr1; 
		
	}
	else
	{
		ptr1->next = ptr1; 
	}
	head = ptr1;
}
bool dedectcycle(node*head)
{
	node*slow=head;
	node*fast=head;
	while(fast!=NULL and fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow)
		{
			return true;
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	node *head = NULL;
	push(head,10);
	push(head,20);
	push(head,30);
	push(head,40);
	printlist(head);
	cout<<dedectcycle(head);
	return 0;
	
}
