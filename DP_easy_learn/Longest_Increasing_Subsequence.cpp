//class Solution {
//public:
#include <bits/stdc++.h>
using namespace std;
int lcs(vector<int>x,vector<int>y,int n,int m)
{
    int t[n+1][m+1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                t[i][j] = 0;
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(x[i-1]==y[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else
            {
                t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
    }
    return t[n][m];
}
int lengthOfLIS(vector<int>& nums)
{
    int n=nums.size();
    vector<int>inc;
    inc=nums;
    sort(inc.begin(),inc.end());
    
    inc.erase(unique(inc.begin(),inc.end()),inc.end());
    return lcs(nums,inc,n,inc.size());
}
int main()
{
    vector<int> nums={10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(nums);
    
}