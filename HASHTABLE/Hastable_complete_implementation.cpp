#include<iostream>
using namespace std;

template<typename T>  //templated class
class node{
	public:
		string key;
		t value;
		node<T>*next;
		 
		//constructor 
		node(string key,T val)
		{
			this->key=key;
			value= val;
			next=NULL;
		}
		//destructor
		~node()
		{
			if(next!=NULL)
			{
				delete next;
			}
		}
		
};

template<typename T>  //templated class
class Hashtable
{
	node<T>** table;  // pointer to array of pointers
	int current_size;
	int table_size;
	
	int hashfn(string key)
	{
		int idx=0;
		int p=1;
		for(int j=0;j<key.length();j++)
		{
			idx=idx+(key[j]*p)%table_size;    //  The key itself will give the index.
            idx=idx%table_size;      // moduloe every time to abide segmenation fault..
            p=(p*27)%table_size; // every time the p is updated with higher power (p is a distinguished prime no.)
		}
        return idx;
	}
	
	public:
		Hashtable(int ts=7)
		{
			table_size=ts;  
			table = new node<T>*[table_size];  //dynamic.. a random node table to store next to another table.
			current_size=0;
			for(int i=0;i<table_size;i++)
			{
				table[i]=NULL;  //initialize
			}
		}
}

void insert(string key ,T value)
{
	int idx=hashfn(key);  
    node<T>*n=new node<T> (key,value);
    //Inserting at the head of the linked list with id=idx
    n->next=table[idx];
    table[idx]=n;
    current_size++;
    //rehash
	
}



int main()
{
	
}
