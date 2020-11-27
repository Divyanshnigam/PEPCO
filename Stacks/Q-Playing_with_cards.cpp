#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int prime[1000]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157};
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
	for(int i=0;i<q;i++)
	{
		int p=prime[i];
	while(!s.empty())
	{
		if(s.top()%p==0)
		{
			b.push(s.top());
			s.pop();
		}
		else{
			a.push(s.top());
			s.pop();
		}
	}
    }
for(int i=0;i<q;i++)
{
	while(!b.empty())
	{
		cout<<b.top()<<endl;
		b.pop();
	}
}
while(!a[q].empty()){   // print aq
            cout<<a[q].top()<<endl;
            a[q].pop();
    }


	return 0;
}
