#include<iostream>
#include<cstring>
using namespace std;
int main()
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
	for(int i=0;i<n;i++)
	{
		int svj=0;
		//find the minimum of a row
		for(int j=1;j<n;j++)
		{
			if(a[i][j]<a[i][svj])
			{
				svj=j;
			}
		}
		bool flag=true;
		// finding Maximum of a column
		for(int k=0;k<n;k++)
		{
			if(a[k][svj]>a[i][svj])
			{
				flag=false;
				break;
			}
		}
		if(flag==true)
		{
			cout<<a[i][svj];
			return 0;
		}
	}
	cout<<"Invalid input";
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
41
*/
