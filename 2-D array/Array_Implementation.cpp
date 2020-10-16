#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
/*
i/p:
2
4
11
12
13
14
21
22
23
24
o/p:
11 12 13 14 
21 22 23 24
*/
