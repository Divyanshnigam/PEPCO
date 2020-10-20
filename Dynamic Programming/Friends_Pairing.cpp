#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int dp[n];
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]*(i-1);
    }
    cout<<dp[n];
}
/*
Sample Input
4
Sample Output
10
*/
