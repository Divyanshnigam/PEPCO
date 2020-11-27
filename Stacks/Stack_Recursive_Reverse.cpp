#include<iostream>
#include<stack>
using namespace std;
void insertatbottom(stack<int> &s,int x)
{
	if(s.empty())
	{
	s.push(x);
	return ;
	}
	int y=s.top();
	s.pop();
	insertatbottom(s,x);
	s.push(y);
}
void recreverse(stack<int> &s)
{
	if(s.empty())
	{
		return;
	}
	int x=s.top();
	s.pop();
	recreverse(s);
	insertatbottom(s,x);
}
int main()
{
	stack<int> s;
	int n,data;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		s.push(data);
	}
	recreverse(s);
	for(int i=0;i<n;i++)
	{
		cout<<s.top()<<endl;
		s.pop();
	}
    return 0;
}
