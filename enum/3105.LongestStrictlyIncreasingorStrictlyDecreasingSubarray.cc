/*
   You are given an array of integers nums. Return the length of the longest
   subarray
   of nums which is either
   strictly increasing
   or
   strictly decreasing
   .



   Example 1:

Input: nums = [1,4,3,3,2]

Output: 2

Explanation:

The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].

The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].

Hence, we return 2.

Example 2:

Input: nums = [3,3,3,3]

Output: 1

Explanation:

The strictly increasing subarrays of nums are [3], [3], [3], and [3].

The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

Hence, we return 1.

Example 3:

Input: nums = [3,2,1]

Output: 3

Explanation:

The strictly increasing subarrays of nums are [3], [2], and [1].

The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].

Hence, we return 3.



Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50

*/


#include"head.h"
class Solution {
	public:
		int longestMonotonicSubarray(vector<int>& nums) {
		return max(solve(nums,1),solve(nums,-1));
		}
		int check(int x,int y)
		{
			return x<y?-1:(x==y?0:1);
		}
		int solve(const vector<int>& nums,int sub)
		{
			const int n=nums.size();
			int res=1;
			for(int i=1,j=0;i<n;i++)
			{
				if(check(nums[i-1],nums[i])!=sub)
					j=i;
				res=max(res,i-j+1);
			}
			return res;
		}
};


int main() 
{
	Solution s;
	vector<int>  nums = {1,4,3,3,2};
	cout<<s.longestMonotonicSubarray(nums)<<endl;
	nums.clear();nums={3,3,3,3};
	cout<<s.longestMonotonicSubarray(nums)<<endl;
	nums.clear();nums={3,2,1};
	cout<<s.longestMonotonicSubarray(nums)<<endl;
	return 0;
}
