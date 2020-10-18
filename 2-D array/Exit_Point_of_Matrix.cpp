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
	int dir=0;
    int i=0;
    int j=0;
    while(true)
    {
        dir=(dir+a[i][i])%4;
        if(dir==0)
        {
            j++;
        }
        else if(dir==1)
        {
            i++;
        }
        else if(dir==2)
        {
            j--;
            
        }
        else if(dir==3)
        {
            i--;
        }
        
        if(i<0)
        {

        }
        if(j<0)
        {

        }
        if(i==n)
        {

        }
        if(i==m)
        {

        }
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
