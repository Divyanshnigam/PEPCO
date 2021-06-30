#include <bits/stdc++.h>
using namespace std;
int static t[102][1002];
int knapsack(int wt[],int val[],int w,int n)
{
    if(n==0 or w==0)
    {
        return 0;
    }
    if(t[n][w]!=-1)
    {
        return t[n][w];
    }
    if(wt[n-1]<=w)
    {
        return t[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1) ,knapsack(wt,val,w,n-1) );
    }
    else if(wt[n-1]>w)
    {
        return t[n][w]=knapsack(wt,val,w,n-1);
    }
    else
    {
        return -1;
    }
}
signed main() 
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
    for (int i = 0; i <= n; i++)
		for (int j = 0; j <= w; j++)
			t[i][j] = -1;
    cout<< knapsack(wt,val,w,n);
    return 0;    
}

