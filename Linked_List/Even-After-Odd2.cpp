#include<iostream>
#include<list>
using namespace std;
class node
{
    public:
        int data;
        node*next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
void insertattail(node*&head , int data)
{
    if(head == NULL)
    {
        head = new node(data);
        return;
    }
    node *temp = head;
    while(temp->next!=NULL)
    {
        temp = temp ->next;
    }
    node *n = new node(data);
    temp -> next = n ; 
    return;
}
void build(node*&head)
{
    int length;
    cin>>length;
    int data;
    for(int i = 0 ; i < length ; i++)
    {
        cin>>data; 
        insertattail(head,data);
    }
}
void dist(node *&head , list <int> l)
{
    node*temp = head;
    while(temp != NULL)
    {
        if(temp->data % 2 != 0)
        {
            cout<<temp->data<<" ";
            temp = temp -> next ;
        }
        else
        {
            l.push_back(temp->data);
            temp = temp -> next;
        }
    }
    for(int i:l){
        cout<<i<<" ";
    }
}
int main()
{
    list <int> l;
    node*head = NULL;
    build(head);
    dist(head,l);
}
