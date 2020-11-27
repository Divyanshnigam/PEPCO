#include<iostream>
#include<queue>
using namespace std;
template<typename t>
class stack
{
	queue<t> q1,q2;
	public:
		void push(t x)
		{
			q1.push(x);
		}
		void pop()
		{
			//we have to first move 1st n-1 elements in q2 
			//remove the last added element from th q1 
			//interchangethe names of q1 and q2
			if(q1.empty())
			{
				return;
			}
			while(q1.size()>1)
			{                     //moving to q2
				t element=q1.front();
				q2.push(element);
				q1.pop();
			}
			//remove the last element 
			q1.pop();
			//swap the names of q1 and q2
			swap(q1,q2);
		}
		t top()
		{
			while(q1.size()>1)
			{
				t element=q1.front() ;
				q2.push(element);
				q1.pop();
			}
			t element=q1.front();
			q1.pop();
			q2.push(element);
			swap(q1,q2);
			return element;
		}
		int size()
		{
			return q1.size()+q2.size();
		}
		bool empty()
		{
			return size()==0;
		}
};
int main()
{
	stack<int >s;
	s.push(1);	
	s.push(2);	
	s.push(3);	
    while(!s.empty())
    {
    	cout<<s.top()<<" ";
    	s.pop();
	}
	return 0;
}
