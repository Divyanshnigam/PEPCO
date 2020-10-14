#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// This function gets two arguments - the head pointers of the two linked lists
// Return the node which is the intersection point of these linked lists
// It is assured that the two lists intersect
int length(Node*head)
{
	int len=0;
	while(head!=NULL)
	{
		head=head->next;
		len+=1;
	}
	return len;
}
Node *intersectionOfTwoLinkedLists(Node *h1, Node *h2)
{   int n=length(h1);
	int m=length(h2);
    Node *a,*b;
	if(n>m)
	{
		int d=n-m;
		for(int i=0;i<d;i++)
		h1=h1->next;
	}
	else
	{
		int d=m-n;
		for(int i=0;i<d;i++)
		h2=h2->next;
	}
	while(h1!=NULL)
	{
		
		if(h1->data==h2->data)
		{	
			
			a=h1->next;
			b=h2->next;
			while(((a->data)==(b->data))&&a->next!=NULL&&b->next!=NULL)
			{
				a=a->next;
				b=b->next;
			}
			if(a->data==b->data)
			{
				return h1;
			}
		}
		h1=h1->next;
		h2=h2->next;
	}
   return NULL;
}



/*
1 -> 2 -> 3  -> null
    ^
   / 
4
*
*
*   You do not need to refer or modify any code below this. 
*   Only modify the above function definition.
*	Any modications to code below could lead to a 'Wrong Answer' verdict despite above code being correct.
*	You do not even need to read or know about the code below.
*
*
*
*/

Node *buildList(unordered_map<int, Node *> &hash)
{
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *current = head;
    hash[x] = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
        break;
        Node *n = new Node(x);
        hash[x] = n;
        current->next = n;
        current = n;
    }
    current->next = NULL;
    return head;
}

void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    unordered_map<int, Node *> hash;
    Node *l1 = buildList(hash);

    Node *l2 = NULL;
    int x;
    cin >> x;
    l2 = new Node(x);
    Node *temp = l2;

    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end())
        {
            temp->next = hash[x];
            break;
        }
        Node *n = new Node(x);
        temp->next = n;
        temp = n;
    }

    cout << "L1 - ";
    printLinkedList(l1);
    cout << "L2 - ";
    printLinkedList(l2);

    Node *intersectionPoint = intersectionOfTwoLinkedLists(l1, l2);
    cout << "Intersection at node with data = " << intersectionPoint->data << endl;

    return 0;
}
