#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int h[n][m];
    int dp[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>h[i][j];
        }
    }
    int l1=INT_MAX;
    int l2=INT_MAX;
    for(int j=0;j<m;j++)
    {
        dp[0][j]=h[0][j];
        if(h[0][j]<=l1)
        {
           l2=l1;
           l1=h[0][j];
        }
        else if(h[0][j]<=l2)
        {
            l2=h[0][j];
        }
    }
    
    for(int i=1;i<n;i++)
    {
        int nl1=INT_MAX;
        int nl2=INT_MAX;
        for(int j=0;j<m;j++)
        {
            if(l1==dp[i-1][j])
            {
                dp[i][j]=h[i][j]+l2;
            }
            else
            {
                dp[i][j]=h[i][j]+l1;
            }
            if(dp[i][j]<=nl1)
            {
               nl2=nl1;
               nl1=dp[i][j];
            }
            else if(dp[i][j]<=nl2)
            {
                nl2=dp[i][j];
            }
        }
        l1=nl1;
        l2=nl2;
    }
        cout<<l1<<endl;
    
   /* for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    } */
    
}
/*
Sample Input
4 3
1 5 7
5 8 4
3 2 9
1 2 4
Sample Output
8
*/
