#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	//transpose
	for(int i=0;i<n;i++)
	{
		for (int j=i;j<n;j++)
		{
			swap(a[i][j],a[j][i]);
		}
	}
	//reverse
	for(int i=0;i<n;i++)
	{
		int lc=0;
		int rc=n-1;
		while(lc<rc)
		{
			swap(a[i][lc],a[i][rc]);
			lc++;
			rc--;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
/*
Sample Input
4
11
12
13
14
21
22
23
24
31
32
33
34
41
42
43
44
Sample Output
41 31 21 11
42 32 22 12
43 33 23 13
44 34 24 14
*/
