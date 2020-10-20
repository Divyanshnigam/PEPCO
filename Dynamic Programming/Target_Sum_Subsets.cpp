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
    bool dp[n+1][ts+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<ts+1;j++)
        {
            if(i==0 and j==0)
            {
                dp[i][j]=true;
            }
            else if(i==0)
            {
                dp[i][j]=false;
            }
            else if(j==0)
            {
                dp[i][j]=true;
            }
            else
            {
                if(dp[i-1][j]==true)
                {
                    dp[i][j]=true;
                }
                else
                {
                    int val=a[i-1];
                    if(j>=val)
                    {
                        if(dp[i-1][j-val]==true)
                        {
                            dp[i][j]=true;
                        }
                    }
                }
            }
        }
    }
    if(dp[n][ts]==1)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}
