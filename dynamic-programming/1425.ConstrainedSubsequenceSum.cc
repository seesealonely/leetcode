/*
   Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

   A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.



   Example 1:

Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].

Example 2:

Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.

Example 3:

Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].



Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

*/


#include"head.h"
class Solution {
	public:
		int constrainedSubsetSum(vector<int>& nums, int k) {
		const int n=nums.size();
		vector<int> dp(n);

		deque<int> q;
		int res=nums.front();

		dp[0]=res;
		q.push_back(0);

		for(int i=1;i<n;i++)
		{
			while(!q.empty()&&i-q.front()>k)
				q.pop_front();

			dp[i]=max(nums[i],dp[q.front()]+nums[i]);
			res=max(res,dp[i]);

			while(!q.empty()&&dp[i]>=dp[q.back()])
				q.pop_back();

			q.push_back(i);
		}

		return res;

		}
};


int main() 
{
	Solution s;
	vector<int> nums={10,2,-10,5,20};
	cout<<s.constrainedSubsetSum(nums,2)<<endl;
	nums.clear();nums={-1,-2,-3};
	cout<<s.constrainedSubsetSum(nums,1)<<endl;
	nums.clear();nums={10,-2,-10,-5,20};
	cout<<s.constrainedSubsetSum(nums,2)<<endl;
	return 0;
}
