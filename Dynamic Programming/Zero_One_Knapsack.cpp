#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int v[n],w[n];
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    int c;
    cin>>c;
    int dp[n+1][c+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<c+1;j++)
        {
            if(i==0)
            {
                dp[i][j]=0;
            }
            else if(j==0)
            {
                dp[i][j]=0;
            }
            else
            {
                if(j<w[i])
                {
                    dp[i][j]=dp[i-1][j];
                }
              /*  else if(j==w[i])
                {
                    dp[i][j]=max(dp[i-1][j],v[i]);
                }*/
                else
                {
                    int rem=j-w[i];
                    dp[i][j]=max(dp[i-1][j],(v[i]+dp[i-1][rem]));
                }
            }
        }
    }
  /*  for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<c+1;j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    } */
    cout<<dp[n][c];
}
/*
Sample Input
5
15 14 10 45 30
2 5 1 3 4
7
Sample Output
75
*/
