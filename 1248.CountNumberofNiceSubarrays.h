/*
   Given an array of integers nums and an integer k. A subarray is called nice if there are k odd numbers on it.

   Return the number of nice sub-arrays.



   Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.

Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16



Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length


*/

#include"head.h"

class Solution {
	public:
		int numberOfSubarrays(vector<int>& nums, int k) {
			//return firstWay(nums,k);
			return secondWay(nums,k)-secondWay(nums,k-1);
		}

		int firstWay(vector<int>& nums, int k) {
			int res=0,count=0,begin=0;
			for(int i=0;i<nums.size();i++)
			{
				if(nums[i]&1) k--,count=0;
				while(k==0)
					k+=nums[begin++]&1,count++;
				res+=count;
			}        
			return res;
		}
		int secondWay(vector<int>& nums, int k) {
			int res=0,begin=0;
			for(int i=0;i<nums.size();i++)
			{
				k-=nums[i]&1;
				while(k<0)
				{
					k+=nums[begin++]&1;
				}
				res+=i-begin+1;
			}
			return res;
		}
};
