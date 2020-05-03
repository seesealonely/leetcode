/*
   Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 

*/

#include"head.h"

class Solution {
	public:
		int minSubArrayLen(int s, vector<int>& nums) {
			return	     slidingWindow(s,nums);  
		}
		int bruteForce(int s,vector<int> &nums)
		{
			int n=nums.size();
			int res=INT_MAX;
			for(int i=0;i<n;i++)
			{
				for(int j=i;j<n;j++)
				{
					int sum=0;
					for(int k=i;k<=j;k++)
						sum+=nums[k];
					if(sum>=s)
						res=min(res,j-i+1);
				}
			}
			return (res!=INT_MAX?res:0);
		}
		int slidingWindow(int s,vector<int> &nums)
		{
			int res=INT_MAX,sum=0,begin=0;
			for(int end=0;end<nums.size();end++)
			{
				sum+=nums[end];
				while(sum>=s)
				{
					res=min(res,end-begin+1);
					 sum-=nums[begin++];
				}
			}	
			return res!=INT_MAX?res:0;
		}
};
