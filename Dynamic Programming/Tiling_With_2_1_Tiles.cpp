#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int dp[n]={0};
    dp[1]=1; // ways to arange tiles in this 1 unit length
    dp[2]=2; // ways to arange are 2 tile in this 2 unit length in two ways
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
    
}
/*
Sample Input
8
Sample Output
34
*/
