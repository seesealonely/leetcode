/*
   You are given a 0-indexed array nums consisting of positive integers.

   A partition of an array into one or more contiguous subarrays is called good if no two subarrays contain the same number.

   Return the total number of good partitions of nums.

   Since the answer may be large, return it modulo 109 + 7.



   Example 1:

Input: nums = [1,2,3,4]
Output: 8
Explanation: The 8 possible good partitions are: ([1], [2], [3], [4]), ([1], [2], [3,4]), ([1], [2,3], [4]), ([1], [2,3,4]), ([1,2], [3], [4]), ([1,2], [3,4]), ([1,2,3], [4]), and ([1,2,3,4]).

Example 2:

Input: nums = [1,1,1,1]
Output: 1
Explanation: The only possible good partition is: ([1,1,1,1]).

Example 3:

Input: nums = [1,2,1,3]
Output: 2
Explanation: The 2 possible good partitions are: ([1,2,1], [3]) and ([1,2,1,3]).



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109

*/

#define c11
#include"head.h"
class Solution {
	public:
		int numberOfGoodPartitions(vector<int>& nums) {
			const int n=nums.size(),mod=1e9+7;
			unordered_map<int,int> r;
			for(int i=0;i<n;i++)
				r[nums[i]]=i;

			int res=1,max_r=0;
			for(int i=0;i+1<n;i++)
			{
				max_r=max(max_r,r[nums[i]]);
				if(max_r==i)
					res=res*2%mod;
			}
			return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={1,2,3,4};
	cout<<s.numberOfGoodPartitions(nums)<<endl;
	nums.clear();nums={1,1,1,1};
	cout<<s.numberOfGoodPartitions(nums)<<endl;
	nums.clear();nums={1,2,1,3};
	cout<<s.numberOfGoodPartitions(nums)<<endl;
	return 0;
}
