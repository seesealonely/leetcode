/*
   You are given a 0-indexed integer array nums. For each index i (1 <= i <= nums.length - 2) the beauty of nums[i] equals:

   2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k <= nums.length - 1.
   1, if nums[i - 1] < nums[i] < nums[i + 1], and the previous condition is not satisfied.
   0, if none of the previous conditions holds.

   Return the sum of beauty of all nums[i] where 1 <= i <= nums.length - 2.



   Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation: For each index i in the range 1 <= i <= 1:
- The beauty of nums[1] equals 2.

Example 2:

Input: nums = [2,4,6,4]
Output: 1
Explanation: For each index i in the range 1 <= i <= 2:
- The beauty of nums[1] equals 1.
- The beauty of nums[2] equals 0.

Example 3:

Input: nums = [3,2,1]
Output: 0
Explanation: For each index i in the range 1 <= i <= 1:
- The beauty of nums[1] equals 0.



Constraints:

3 <= nums.length <= 105
1 <= nums[i] <= 105

*/
#include"head.h"
class Solution {
	public:
		int sumOfBeauties(vector<int>& nums) {
			int n=nums.size(),res=0;
			vector<int> prefix(n,INT_MIN),suffix(n,INT_MAX);

			for(int i=1;i<n;i++)
			{
				prefix[i]=max(prefix[i-1],nums[i-1]);
				suffix[n-i-1]=min(suffix[n-i],nums[n-i]);
			}

			for(int i=1;i<n-1;i++)
			{
				if(nums[i]>prefix[i]&&nums[i]<suffix[i])
					res+=2;
				else if(nums[i]>nums[i-1]&&nums[i]<nums[i+1])
					res++;
			}
			return res;
		}
};
