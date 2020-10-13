#include<iostream>
#include<cstring>
using namespace std;
template<typename T>
class Node
{
	public:
		string key;
		T value;
		Node<T>*next;
		Node(string key,T val)      //constructor
		{
			this->key=key;
			value=val;
			next=NULL;
		}	
		~Node()                 //destructor to delete a node
		{
			if(next!=NULL)
			{
				delete next;
			}
		}	
};
template<typename T>
class Hashtable
{
	Node<T>** table;    //pointer to an array of pointers
	int current_size;
	int table_size;
	
	int hashfn(string key)
	{
		int idx=0;
		int p=1;
		for(int j=0;j<key.length();j++)
		{
			idx=idx+(key[j]*p) %table_size;
			idx=idx %table_size;
			p=(p*27) %table_size;     // taken a prime no. for min. collision.
		}
		return idx;
	}
	public:
		Hashtable(int ts=7)
		{
			table_size=ts;     //initializing the table_size=7, can dynamically increase on demand 
			table=new Node<T>*[table_size];       // dynamically allocating the table 
			current_size=0;
			for(int i=0;i<table_size;i++)
			{
				table[i]=NULL;           //initialising the table with NULL
			}
		}
		
		void insert(string key,T value)
		{
			int idx=hashfn(key);                  //recieving the index where that key is stored
			Node<T>*n=new Node<T> (key,value);    //node of linked list containing key and value
			//insert at the head of the linked list with id=idx
			n->next=table[idx];          //assinging the next node of linked list to the index of the table 
			table[idx]=n;                // storing the node at the starting 
			current_size++;
			//rehash....
		}
		void print()
		{
			for(int i=0;i<table_size;i++)
			{
				cout<<"Bucket "<<i<<"->";
				Node<T>*temp=table[i];
				while(temp!=NULL)
				{
					cout<<temp->key<<"->";
					temp=temp->next;
				}
				cout<<endl;
			}			
		}		
};
int main()
{
	Hashtable<int> price_menu;
	price_menu.insert("Burger",120);
	price_menu.insert("Pepsi",20);
	price_menu.insert("BurgerPizza",150);
	price_menu.insert("Noodles",25);
	price_menu.insert("Coke",40);
	price_menu.print();
	return 0;
}
/*
o/p:

Bucket 0->
Bucket 1->
Bucket 2->Noodles->
Bucket 3->Burger->
Bucket 4->Coke->Pepsi->
Bucket 5->BurgerPizza->
Bucket 6->
*/
