/*
   You are given an integer array, nums, and an integer k. nums comprises of only 0's and 1's. In one move, you can choose two adjacent indices and swap their values.

   Return the minimum number of moves required so that nums has k consecutive 1's.



   Example 1:

Input: nums = [1,0,0,1,0,1], k = 2
Output: 1
Explanation: In 1 move, nums could be [1,0,0,0,1,1] and have 2 consecutive 1's.

Example 2:

Input: nums = [1,0,0,0,0,0,1,1], k = 3
Output: 5
Explanation: In 5 moves, the leftmost 1 can be shifted right until nums = [0,0,0,0,0,1,1,1].

Example 3:

Input: nums = [1,1,0,1], k = 2
Output: 0
Explanation: nums already has 2 consecutive 1's.



Constraints:

1 <= nums.length <= 105
nums[i] is 0 or 1.
1 <= k <= sum(nums)

*/


#include"head.h"
class Solution {
	public:
		int minMoves(vector<int>& nums, int k) {
		vector<int> p;
		for(int i=0;i<nums.size();i++)
			if(nums[i]) p.push_back(i-p.size());

		int n=p.size();
		vector<int> sum(n+1,0);
		for(int i=0;i<n;i++)
			sum[i+1]=p[i]+sum[i];

		int res=INT_MAX;
		for(int i=0;i<=n-k;i++)
			res=min(res,sum[i]+sum[i+k]-sum[i+k/2]*2-p[i+k/2]*(k%2));
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={1,0,0,1,0,1};
	cout<<s.minMoves(nums,2)<<endl;
	nums.clear();nums={1,0,0,0,0,0,1,1};
	cout<<s.minMoves(nums,3)<<endl;
	nums.clear();nums={1,1,0,1};
	cout<<s.minMoves(nums,2)<<endl;
	return 0;
}
