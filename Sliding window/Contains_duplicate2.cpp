#include <bits/stdc++.h>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
    int i=0;
    int j=0;
    unordered_map<int,int>m;
    
    while(j<nums.size())
    {
        m[nums[j]]++;
        if(m[nums[j]]>1)
                return true;
        if((j-i)<k)
        {
            
            j++;
        }
        else if((j-i) == k )
        {
            m[nums[i]]--;
            i++;
            j++;
        }
    }
    return false;
    
}


int main() {
    vector<int> nums={3,4,3,1,5,2};
    int k=2;
    cout<<containsNearbyDuplicate(nums, k) ;

}
