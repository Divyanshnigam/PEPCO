#include<iostream>
#include<stack>
using namespace std;
int main () 
{
	stack<int > s;
	int t,p,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==2)
		{
			cin>>p;
			s.push(p);			
		}
		else if(n==1 and s.empty())
		{
			cout<<"No Code"<<endl;
		}
		else
		{
			cout<<s.top()<<endl;
			s.pop();
		}
	}
	return 0;
}
