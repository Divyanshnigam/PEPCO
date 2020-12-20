class Solution {
public:
    int path(int m,int n,int i,int j,int dp[][100])
    {
        //int a[10000][10000]={0};
        if(i>=m or j>=n)
        {
            return 0;
        }
        if(i==m-1 and j==n-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        else
        {
            return dp[i][j]=path(m,n,i+1,j,dp) + path(m,n,i,j+1,dp);
        }
    }
    int uniquePaths(int m, int n) 
    {
        int dp[100][100]={-1};
        int k=path(m,n,0,0,dp);
        return k;
    }
};

int main()
{}
