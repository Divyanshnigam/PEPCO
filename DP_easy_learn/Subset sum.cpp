#include <bits/stdc++.h>
using namespace std;
bool subset(int arr[],int sum,int n)
{
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            {
                t[i][j]=false;
            }
            if(j==0)
            {
                t[i][j]=true;
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j]= t[i-1][j-arr[i-1]] or t[i-1][j];
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
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
    int w;
    cin>>w;
    int m=subset(wt,w,n);
    if(m==1)
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    } 
    return 0;    
}

