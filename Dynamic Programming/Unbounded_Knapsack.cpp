#include<iostream>
#include<climits>
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
    int dp[c+1]={0};
    dp[0]=0;
    int m=m=INT_MIN;
    for(int j=1;j<c+1;j++)
    {
        
        for(int i=1;i<=n;i++)
        {
            if(w[i]<=j)
            {
                m=max(m,v[i]+dp[j-w[i]]);
            }
        }
        dp[j]=m;
    }
   /* for(int i=0;i<c+1;i++)
    {
        cout<<dp[i]<<"  ";
    } 
    cout<<endl;*/
    cout<<dp[c];
}
/*
Sample Input
5
15 14 10 45 30
2 5 1 3 4
7
Sample Output
100
*/
