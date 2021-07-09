class Solution {
public:
    int lcs(vector<int>& nums1, vector<int>& nums2,int n,int m)
    {
        int t[n + 1][m + 1]; // DP - matrix

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                if (i == 0 || j == 0)
                    t[i][j] = 0;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (nums1[i - 1] == nums2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = 0;

        int mx = INT_MIN;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                mx = max(mx, t[i][j]);

        return mx;

    }
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        int m=nums2.size();
        return lcs(nums1,nums2,n,m);
    }
};
