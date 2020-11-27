#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int n,q,data;
	stack<int> s;
	stack<int> a;
	stack<int> b;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		s.push(data);
	}
	while(!s.empty())
	{
		if(s.top()%2==0)
		{
			b.push(s.top());
			s.pop();
		}
		else{
			a.push(s.top());
			s.pop();
		}
	}
	while(!b.empty())
	{
		cout<<b.top()<<endl;
		b.pop();
	}
	while(!a.empty())
	{
		cout<<a.top()<<endl;
		a.pop();
	}
	return 0;
}
