//assigning null in the array ???
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int dp[n+1];
    for(int i=0;i<=n;i++)
    {
    	dp[i]='\0';
	}
    dp[n]=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>0)
        {
            int m=INT_MAX;
            for(int j=1;j<=a[i] and (i+j)<(n+1);j++)
            {
                if(dp[i+j]!='\0')
                {
                    m=min(m,dp[i+j]);
                }
            }
            if(m!=INT_MAX)
            {
                dp[i]=m+1;
            }
        }
    }
    cout<<dp[0];
    
}
/*
Sample Input
10
3
3
0
2
1
2
4
2
0
0
Sample Output
4
*/
