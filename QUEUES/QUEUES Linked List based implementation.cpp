#include<iostream>
#include<list>
using namespace std;
class queue
{
	int cs;
	list<int>qu;
	 public:
	  queue()
	  {
	  	this->cs=0;
	  }
	  bool isempty()
	  {
	    return this->cs==0;
	  }
	  void enqueue(int data)
	  {
	  	this->qu.push_back(data);
	  	this->cs+=1;
	  }
	  void deque()
	  {
	  	if(!isempty())
	  	{
		  this->cs-=1;
		  this->qu.pop_front();	
		}
	  }
    int getfront()
	{
		return this->qu.front();
	}
};
int main(int argc,char const*agr[])
{
	queue qu;
	for(int i=0;i<=6;i++)
	{
		qu.enqueue(i);
    }
    qu.deque();
    qu.enqueue(8);
    while(!qu.isempty())
    {
    	cout<<qu.getfront()<<endl;
    	qu.deque();
	}
	return 0;
}
