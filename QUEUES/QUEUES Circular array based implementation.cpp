#include<iostream>
using namespace std;
class queue
{            //initializing 
	int *arr;
	int ms;         //maximum size 
	int cs;         //current size
	int front;
	int rear;
  public:
    queue(int default_size=7)    //constructor to declare
    {
    	this->front=0;
    	this->rear=default_size-1;
    	this->arr=new int [this->ms] ();             //declaring zeros
    	this->ms=default_size;
    	this->cs=0;
	}
	bool isfull()
	{
		return this->cs==this->ms;
	}
	bool isempty()
	{
		return this->cs==0;
	}
	void enqueue(int data)
	{
		if(!isfull())                                 //if not empty
		{
			this->rear=(this->rear+1)%this->ms;       //this->rear=8%7=1
			this->arr[this->rear]=data;               //arr[1]=data
			this->cs+=1;                              //As enqueued the size by 1 
		}
	}
	void deque()
	{
		if(!isempty())                          
		{
			this->front=(this->front+1)%this->ms;     //from this->front=0  to  this->front=1%7=1  hence front element got removed.
			this->cs-=1;
		}
	}
	int getfront()
	{
		return this->arr[this->front];
	}
};
int main(int argc,char const*agr[])
{
	queue q(10);
	for(int i=0;i<=6;i++)
	{
		q.enqueue(i);
    }
    q.deque();
    q.enqueue(8);
    while(!q.isempty())
    {
    	cout<<q.getfront()<<endl;
    	q.deque();
	}
	return 0;
}
