#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    if(n==0 or k==0 or n<k)
    {
        cout<<"0";
    }
    int dp[n+1][k+1]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int t=1;t<k+1;t++)
    {
        for(int p=1;p<n+1;p++)
        {
            if(p==1)
            {
                dp[t][p]=1;
            }
            else if(p<t)
            {
                dp[t][p]=0;
            }
            if(p==t)
            {
                dp[t][p]=1;
            }
            else
            {
                dp[t][p]=(t*dp[t][p-1])+dp[t-1][p-1];
            }
        }
    }
   /* for(int t=1;t<k+1;t++)
    {
        for(int p=1;p<n+1;p++)
        {
            cout<<dp[t][p]<<"  ";
        }
        cout<<endl;
    }*/
    cout<<dp[k][n];
}
