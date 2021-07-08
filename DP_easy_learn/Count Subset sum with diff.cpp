#include <bits/stdc++.h>
using namespace std;
int subset(int arr[],int sum,int n)
{
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            {
                t[i][j]=0;
            }
            if(j==0)
            {
                t[i][j]=1;
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j]= t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int count_sum_with_diff(int *arr,int diff,int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	int tot=(sum+diff)/2;
	return subset(arr,tot,n);
}
int main() 
{
    int n;
    cin>>n;
    int wt[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    int w;
    cin>>w;
    cout<<count_sum_with_diff(wt,w,n);
    return 0;    
}

