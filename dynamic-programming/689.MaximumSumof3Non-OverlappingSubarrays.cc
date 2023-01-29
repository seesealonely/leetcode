/*
   Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.

   Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.



   Example 1:

Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.

Example 2:

Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]



Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] < 216
1 <= k <= floor(nums.length / 3)

*/


#include"head.h"
class Solution {
    public:
        vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n=nums.size();
        vector<int> sum;sum.push_back(0);

        reverse(nums.begin(),nums.end());
        for(int i=1;i<=n;i++)
            sum.push_back(sum[i-1]+nums[i-1]);

        vector<vector<int>> dp(4,vector<int>(n+1,INT_MIN));

        for(int i=0;i<=n;i++)
        dp[0][i]=0;

        for(int i=1;i<=3;i++)
            for(int j=k;j<=n;j++)
                dp[i][j]=max(dp[i][j-1],dp[i-1][j-k]+sum[j]-sum[j-k]);

        vector<int> res;
        for(int i=3,j=n;i>0;)
        {
            if(dp[i][j-1]>dp[i-1][j-k]+sum[j]-sum[j-k])
                j--;
            else
            {
                res.push_back(n-j);
                j-=k;
                i--;
            }
        }

        return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,2,1,2,6,7,5,1};
    show(s.maxSumOfThreeSubarrays(v,2));
    return 0;
}
