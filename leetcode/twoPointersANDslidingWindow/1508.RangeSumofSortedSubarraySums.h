/*
   You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n 1023.CamelcaseMatching 1023.CamelcaseMatching.cc 1023.CamelcaseMatching.h 1508.RangeSumofSortedSubarraySums.cc 1508.RangeSumofSortedSubarraySums.h 1574.ShortestSubarraytobeRemovedtoMakeArraySorted.cc 1574.ShortestSubarraytobeRemovedtoMakeArraySorted.h 475.Heaters 475.Heaters.cc 475.Heaters.h 522.LongestUncommonSubsequenceII 522.LongestUncommonSubsequenceII.cc 522.LongestUncommonSubsequenceII.h 825.FriendsOfAppropriateAges 825.FriendsOfAppropriateAges.cc 825.FriendsOfAppropriateAges.h 838.PushDominoes 838.PushDominoes.cc 838.PushDominoes.h head.cc head.h head.o lib.a l.sh makefile (n + 1) / 2 numbers.

   Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.



   Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13.

Example 2:

Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.

Example 3:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50



Constraints:

n == nums.length
1 <= nums.length <= 1000
1 <= nums[i] <= 100
1 <= left <= right <= n * (n + 1) / 2
*/
#include"head.h"
class Solution {
	public:
		int rangeSum(vector<int>& nums, int n, int left, int right) {
		return preSum(nums,n,left,right);
		}
		int preSum(vector<int>& nums, int n, int left, int right) {
			int res=0,start=0,mod=1e9+7;
			vector<int> sums(n*(n+1)/2);
			for(int i=0;i<nums.size();i++)
			{
				int sum=0;
				for(int j=i;j<nums.size();j++)
				{
					sum+=nums[j];
					sums[start++]=sum;
				}
			}
			sort(sums.begin(),sums.end());

			for(int i=left-1;i<right;i++)
				res=(res+sums[i])%mod;

			return res;
		}
};
