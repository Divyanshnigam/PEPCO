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
	int x;
	cin>>x;
	int i=0;
	int j=n-1;
	while(i<n and j>=0)
	{
		if(x==a[i][j])
		{
			cout<<i<<endl<<j;
			return 0;
		}
		else if(x<a[i][j])
		{
			j--;
		}
		else if(x>a[i][j])
		{
			i++;
		}
		
	}
	    cout<<"Not Found";
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
43
Sample Output
3
2
*/
