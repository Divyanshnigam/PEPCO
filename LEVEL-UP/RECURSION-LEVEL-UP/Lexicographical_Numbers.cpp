#include<iostream>
using namespace std;
void dfs(int i,int n)
{
	if(i>n)
	{
		return;
	}
	cout<<i<<endl;
	for(int j=0;j<10;j++)
	{
		dfs((10*i)+j,n);
	}
	
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<10;i++)
    {
    	dfs(i,n);
	}
}
/*
14
1
10
11
12
13
14
2
3
4
5
6
7
8
9
*/
