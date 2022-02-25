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
            for(int i=1,j=1,k=1;i<n+1;i++)
            {
                j=max(j,i+1);
                while(j<n&&2*presum[i]>presum[j]) j++;

                k=max(j,k);
                while(k<n&&2*presum[k]<=presum[i]+presum.back()) ++k;

                res+=(k-j);
            }
            return res%mod;

        }
};
int main() 
{
    Solution s;
    vector<int> v={1,1,1};
    cout<<s.waysToSplit(v)<<endl;
    v.clear();v={1,2,2,2,5,0};
    cout<<s.waysToSplit(v)<<endl;
    v.clear();v={3,2,1};
    cout<<s.waysToSplit(v)<<endl;
    return 0;
}
