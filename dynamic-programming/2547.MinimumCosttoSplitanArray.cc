/*
   You are given an integer array nums and an integer k.

   Split the array into some number of non-empty subarrays. The cost of a split is the sum of the importance value of each subarray in the split.

   Let trimmed(subarray) be the version of the subarray where all numbers which appear only once are removed.

   For example, trimmed([3,1,2,4,3,4]) = [3,4,3,4].

   The importance value of a subarray is k + trimmed(subarray).length.

   For example, if a subarray is [1,2,3,3,3,4,4], then trimmed([1,2,3,3,3,4,4]) = [3,3,3,4,4].The importance value of this subarray will be k + 5.

   Return the minimum possible cost of a split of nums.

   A subarray is a contiguous non-empty sequence of elements within an array.



   Example 1:

Input: nums = [1,2,1,2,1,3,3], k = 2
Output: 8
Explanation: We split nums to have two subarrays: [1,2], [1,2,1,3,3].
The importance value of [1,2] is 2 + (0) = 2.
The importance value of [1,2,1,3,3] is 2 + (2 + 2) = 6.
The cost of the split is 2 + 6 = 8. It can be shown that this is the minimum possible cost among all the possible splits.

Example 2:

Input: nums = [1,2,1,2,1], k = 2
Output: 6
Explanation: We split nums to have two subarrays: [1,2], [1,2,1].
The importance value of [1,2] is 2 + (0) = 2.
The importance value of [1,2,1] is 2 + (2) = 4.
The cost of the split is 2 + 4 = 6. It can be shown that this is the minimum possible cost among all the possible splits.

Example 3:

Input: nums = [1,2,1,2,1], k = 5
Output: 10
Explanation: We split nums to have one subarray: [1,2,1,2,1].
The importance value of [1,2,1,2,1] is 5 + (3 + 2) = 10.
The cost of the split is 10. It can be shown that this is the minimum possible cost among all the possible splits.



Constraints:

1 <= nums.length <= 1000
0 <= nums[i] < nums.length
1 <= k <= 109
*/

#define c11
#include"head.h"
class Solution {
    public:
        int minCost(vector<int>& nums, int k) {
        const int n=nums.size();

        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;

        for(int i=1;i<=n;i++)
        {
            unordered_map<int,int> vis;
            int val=0;
            for(int j=i-1;j>=0;j--)
            {
                int x=nums[j];
                vis[x]++,val++;
                if(vis[x]==1) val--;
                else if(vis[x]==2) val++;
                dp[i]=min(dp[i],dp[j]+k+val);
            }
        }
        return dp[n];
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,2,1,2,1,3,3};
    cout<<s.minCost(v,2)<<endl;
    v.clear();v={1,2,1,2,1};
    cout<<s.minCost(v,2)<<endl;
    v.clear();v={1,2,1,2,1};
    cout<<s.minCost(v,5)<<endl;
    return 0;
}
