/*
   Given an array nums and an integer target, return the maximum number of non-empty non-overlapping subarrays such that the sum of values in each subarray is equal to target.



   Example 1:

Input: nums = [1,1,1,1,1], target = 2
Output: 2
Explanation: There are 2 non-overlapping subarrays [1,1,1,1,1] with sum equals to target(2).

Example 2:

Input: nums = [-1,3,5,1,4,2,-9], target = 6
Output: 2
Explanation: There are 3 subarrays with sum equal to 6.
([5,1], [4,2], [3,5,1,4,2,-9]) but only the first 2 are non-overlapping.



Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
0 <= target <= 106

*/

#define c11
#include"head.h"
class Solution {
    public:
        int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> idx;
        int n=nums.size(),sum=0;

        vector<int> dp(n+1,0);
        idx[0]=0;
        for(int i=1;i<=n;i++)
        {
            sum+=nums[i-1];
            if(idx.count(sum-target))
            {
                dp[i]=max(dp[i-1],dp[idx[sum-target]]+1);
            }
            else
                dp[i]=dp[i-1];

            idx[sum]=i;
        }

        return dp[n];
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,1,1,1,1};
    cout<<s.maxNonOverlapping(v,2)<<endl;
    v.clear();v={-1,3,5,1,4,2,-9};
    cout<<s.maxNonOverlapping(v,6)<<endl;
    return 0;
}
