class Solution {
public:
    
    bool subset(vector<int>& arr,int sum,int n)
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
    
    bool equal_subset(vector<int>& nums)
    {
        int sum=0;
        sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0)
        {
            return false;
        }
        return subset(nums,sum/2,nums.size());
    }

    bool canPartition(vector<int>& nums) 
    {
        return equal_subset(nums); 
    }
};
