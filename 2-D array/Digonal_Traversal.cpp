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
	for(int g=0;g<n;g++)
	{
		for(int i=0,j=g;j<n;i++,j++)
		{
			cout<<a[i][j]<<endl;
		}
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
11
22
33
44
12
23
34
13
24
14
*/
