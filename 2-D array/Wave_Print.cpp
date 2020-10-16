#include<iostream>
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
	for(int j=0;j<m;j++)
	{
	    if(j%2==0)
	    {
	        for(int i=0;i<n;i++)
	        {
	            cout<<a[i][j]<<endl;
	        }
	    }
	    else
	    {
	        for(int i=n-1;i>=0;i--)
	        {
	            cout<<a[i][j]<<endl;
	        }
	    }
	}
	return 0;
}
/*
Sample Input
3
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
Sample Output
11
21
31
32
22
12
13
23
33
34
24
14
*/
