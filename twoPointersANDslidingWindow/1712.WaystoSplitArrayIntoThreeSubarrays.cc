/*
   A split of an integer array is good if:

   The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
   The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.

   Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.



   Example 1:

Input: nums = [1,1,1]
Output: 1
Explanation: The only good way to split nums is [1] [1] [1].

Example 2:

Input: nums = [1,2,2,2,5,0]
Output: 3
Explanation: There are three good ways of splitting nums:
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]

Example 3:

Input: nums = [3,2,1]
Output: 0
Explanation: There is no good way to split nums.



Constraints:

3 <= nums.length <= 105
0 <= nums[i] <= 104
*/
#include"head.h"
class Solution {
    public:
        int waysToSplit(vector<int>& nums) {
            const int n=nums.size();
            vector<int> presum(n+1,0);

            for(int i=0;i<n;i++)
                presum[i+1]=presum[i]+nums[i];

            long long  res=0,mod=1e9+7;
            for(int i=1;i<n-1;i++)
            {
                int second=lower_bound(presum.begin()+i+1,presum.end(),2*presum[i])-presum.begin();
                int third=upper_bound(presum.begin()+i+1,presum.end()-1,presum[i]+(presum.back()-presum[i])/2)-presum.begin();

                if(second>third)
                    continue;
                res+=third-second;
            }
            return res%mod;

        }
};
int main() 
{
    Solution s;
    s.waysToSplit();
    return 0;
}
