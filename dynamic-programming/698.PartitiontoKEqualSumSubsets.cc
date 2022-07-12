/*
   Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.



   Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false



Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].

*/


#include"head.h"
class Solution {
    public:
        bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size(),bn=(1<<n);
        int s=accumulate(nums.begin(),nums.end(),0),t=s/k;
        sort(nums.begin(),nums.end());
    
        if(s%k||nums.back()>t) return false;
        vector<bool> dp(bn,false);
        vector<int> sum(bn,0);
        dp[0]=true;
        for(int i=0;i<bn;i++)
        {
            if(!dp[i]) continue;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j)==0)
                {
                if(sum[i]%t+nums[j]<=t)
                    sum[i|(1<<j)]=sum[i]+nums[j],dp[i|(1<<j)]=true;
                else
                    break;
                }
            }
        }
        return sum[bn-1]%t==0;
        return dp[bn-1];
        }
};


int main() 
{
    Solution s;
    vector<int> v={4,3,2,3,5,2,1};
    cout<<s.canPartitionKSubsets(v,4)<<endl;
    v.clear();v={1,2,3,4};
    cout<<s.canPartitionKSubsets(v,3)<<endl;
    v.clear();v={2,2,2,2,3,4,5};
    cout<<s.canPartitionKSubsets(v,4)<<endl;
    return 0;
}
