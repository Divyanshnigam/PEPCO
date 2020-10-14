#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int>l;
	list<int> eve;
	list<int> odd;
	int n,d;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>d;
		l.push_back(d);
	}
	for(int i=0;i<n;i++)
	{
		if(l.front()%2==0)
		{
			eve.push_back(l.front());
		}
		else
		{
			odd.push_back(l.front());
		}
		l.pop_front();
	}
    for(auto y:odd)
	{
		cout<<y<<"->";
	}
	for(auto x:eve)
	{
		cout<<x<<"->";
	}
	
}
/*
i/p:
10
1 2 3 4 5 6 7 8 9 10
o/p:
1->3->5->7->9->2->4->6->8->10->
*/
