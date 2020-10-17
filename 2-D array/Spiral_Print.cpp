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
	int minr=0;
	int maxr=n-1;
	int minc=0;
	int maxc=m-1;
	int tne=n*m;
	int cne=0;
	while(cne<tne)
	{
		//left wall
		for(int i=minr,j=minc;i<=maxr and  cne<tne;i++)
		{
			cout<<a[i][j]<<endl;
			cne++;
		}
		minc++;
		//bottom wall
		for(int j=minc,i=maxr;j<=maxc and  cne<tne;j++)
		{
			cout<<a[i][j]<<endl;
			cne++;
		}
		maxr--;
		//right wall
		for(int i=maxr,j=maxc;i>=minr and  cne<tne;i--)
		{
			cout<<a[i][j]<<endl;
			cne++;
		}
		maxc--;
		//top wall
		for(int j=maxc,i=minr;j>=minc and  cne<tne;j--)
		{
			cout<<a[i][j]<<endl;
			cne++;
		}
		minr++;
	}
	
	
	return 0;
}
/*
Sample Input
3
5
11
12
13
14
15
21
22
23
24
25
31
32
33
34
35
Sample Output
11
21
31
32
33
34
35
25
15
14
13
12
22
23
24
*/
