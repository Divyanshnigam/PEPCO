#include<iostream>
#include<cstring>
using namespace std;
template<typename T>
class Node
{
	public:
		string key;
		T value;
		Node<T*>next;
		Node(string key,T val)      //constructor
		{
			this->key=key;
			value=val;
			next=NULL;
		}	
		~Node()                 //destructor
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
			idx=idx+(key[j]*p)%table_size;
			idx=idx%table_size;
			p=(p*27)%table_size;
		}
		return idx;
	}
	public:
		Hashtable(int ts=7)
		{
			table_size=ts;
			table=new Node<T>*[table_size];
			current_size=0;
			for(int i=0;i<table_size;i++)
			{
				table[i]=NULL;           //initialising the table with NULL
			}
		}
		
		void insert(string key,T value)
		{
			int idx=hashfn(key);
			Node<T>*n=new Node<T> (key,value);
			//insert at the head of the linked list with id=idx
			n->next=table[idx];
			table[idx]=n;
			current_size++;
			//rehash....
		}
		//void print()
};
