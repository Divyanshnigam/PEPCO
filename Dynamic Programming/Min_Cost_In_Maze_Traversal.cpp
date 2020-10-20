#include<iostream>
using namespace std;
int main()
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
    int dp[n][m];
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 and j==m-1)  // if at last block
            {
                dp[i][j]=a[i][j];
            }
            else if(i==n-1)     // if at last row
            {
                dp[i][j]=dp[i][j+1] + a[i][j];
            }
            else if(j==m-1)      // if at last column
            {
                dp[i][j]=dp[i+1][j] + a[i][j];   
            }
            else                //// else take the min of bottom and right ways
            {
                dp[i][j]=min(dp[i][j+1],dp[i+1][j])+ a[i][j];
            }
        }
    }
    cout<<dp[0][0];
    return 0;
}
/*
Sample Input
6
6
0 1 4 2 8 2
4 3 6 5 0 4
1 2 4 1 4 6
2 0 7 3 2 2
3 1 5 9 2 4
2 7 0 8 5 1
Sample Output
23
*/
