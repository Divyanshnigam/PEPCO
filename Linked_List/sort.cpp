
#include <iostream>
#include<climits>
using namespace std;
class node {
public:
    long long int data;
    node *next;
    node(long long int d){
        data = d;
        next = NULL;
    }
};

void print(node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}
node* sort(node* head)
{
	node*temp= head;
	while(temp->next!=NULL)
	{
		temp=min(temp->data,temp->next->data);
		temp=temp->next;
	}
	return temp;
}
void getLinkedList(node *&head,long long int n){
    long long int x;
    cin>>x; //first input;
    head = new node(x);
    node *currenext = head;
    for(long long int i=1;i<n;i++){
        cin>>x;
        node *a = new node(x);
        currenext->next = a;
        currenext = a;
    } 
    currenext->next = NULL;
}
node* reverse(node* head){
	node* currenext = head;
	node* previous =NULL;
	node* n;

	while(currenext!=NULL){
		n = currenext-> next;
		currenext->next = previous;
		previous = currenext;
		currenext = n;
	}
	return previous;
}

node* kReverse(node* head,int k) 
{ 
    int x=k;
    node *currenext = head; 
    node *prev = NULL;
    node *n = NULL; 
    while (currenext != NULL && x>0)
    { 
        n = currenext->next; 
        currenext->next = prev; 
        prev = currenext; 
        currenext = n;
        x--;
    } 
    if(n != NULL){
        head->next = kReverse(n,k);
    }
    return prev;
} 

int main(){

    node *head = NULL;
    long long int n,k;
    cin>>n>>k;
    getLinkedList(head,n);
    print(head);
    head = sort(head);
    print(head);

    return 0;
 }

