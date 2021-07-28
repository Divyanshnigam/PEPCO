//class Solution {
//public:
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> x,int n ,int m)
{
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(j==0)
            {
                t[i][j]=0;
            }
            if(i==0)
            {
                t[i][j]=INT_MAX-1;
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(x[i-1]<=j)
            {
                t[i][j]=min(1+t[i][j-x[i-1]] , t[i-1][j]);
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][m];
}

int numSquares(int n) 
{
    vector<int> perfectSquares;
    for (int i = 1; i * i <= n; i++) 
    {
        perfectSquares.push_back(i * i);
    }
    return solve(perfectSquares,perfectSquares.size(),n);
}
int main()
{
    cout<<numSquares(12);
    
}