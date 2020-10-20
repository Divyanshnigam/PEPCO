#include<iostream>
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
    int ts;
    cin>>ts;
    int dp[ts+1]={0};
    dp[0]=1; 
    for(int i=1;i<ts+1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]<=i)
            {
                dp[i]+=dp[i-a[j]];
            } 
        }
    }
    cout<<dp[ts];
    return 0;
}
/*
Sample Input
4
2
3
5
6
7
Sample Output
5
*/
