#include<bits/stdc++.h>
using namespace std;
bool lcs(string X, string Y, int n, int m) 
{
        
    int dp[n + 1][m + 1]; // DP - matrix

    // base case of recursion --> for initialization of dp - matrix
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (X[i - 1] == Y[j - 1]) // when last character is same
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else // when last character is not same -> pick max
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

    if(dp[n][m]==n)
    {
        return true;
    }
    return false;
}
bool isSubsequence(string s, string t) 
{
    return lcs(s,t,s.size(),t.size());        
}
int main()
{
    string s="abc";
    string y="paqbrsct";
}