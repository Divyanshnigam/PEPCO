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
	public:
		Hashtable(int ts=7)
		{
			table_size=ts;
			table = new node<T>*[table_size];  //dynamic..
			current_size=0;
			for(int i=0;i<table_size;i++)
			{
				table[i]=NULL;  //initialize
			}
		}
}


int main()
{
	
}
