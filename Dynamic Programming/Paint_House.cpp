#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int h[n][3];
    int dp[n][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>h[i][j];
        }
    }
    dp[0][0]=h[0][0];
    dp[0][1]=h[0][1];
    dp[0][2]=h[0][2];
    for(int i=1;i<n;i++)
    {
        dp[i][0]=h[i][0]+min(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=h[i][1]+min(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=h[i][2]+min(dp[i-1][0],dp[i-1][1]);
        
    }
    cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    /*for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ho[i][j]<<" ";
        }
        cout<<endl;
    } */
    
}
/*
Sample Input
4
1 5 7
5 8 4
3 2 9
1 2 4
Sample Output
8
*/
