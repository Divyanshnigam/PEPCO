#include <bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int w,int n)
{
    int t[n+1][w+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i==0 or j==0)
            {
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(wt[i-1]<=j)
            {
                t[i][j]=max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]);
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][w];
}
int main() 
{
    int n;
    cin>>n;
    int wt[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    int w;
    cin>>w;

    cout<< knapsack(wt,val,w,n);
    return 0;    
}

