class Solution {
public:
    int lcs(string text1, string text2,int n,int m)
    {
        if(n==0 or m==0)
            return 0;
        if(text1[n-1]==text2[m-1])
        {
            return 1+lcs(text1,text2,n-1,m-1);
        }
        else
            return max(lcs(text1,text2,n-1,m), lcs(text1,text2,n,m-1));
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n=text1.size();
        int m=text2.size();
        return lcs(text1,text2,n,m);
    }
};
