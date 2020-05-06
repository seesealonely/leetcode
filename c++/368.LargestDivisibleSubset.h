/*
   Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

   Si % Sj = 0 or Sj % Si = 0.

   If there are multiple solutions, return any subset is fine.

   Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

 */

#include"head.h"

class Solution {
	public:
		vector<int> largestDivisibleSubset(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			vector<int> pre(nums.size(),-1),count(nums.size(),1),res;
			int len=0,idx=-1;
			for(int i=0;i<nums.size();i++)
			{
				for(int j=i-1;j>=0;j--)
				{
					if(nums[i]%nums[j]==0&&count[j]+1>count[i])
					{
						count[i]=count[j]+1;
						pre[i]=j;
					}
				}       
				if(count[i]>len)
				{
					len=count[i];
					idx=i;
				}
			}
			while(idx!=-1)
			{
				res.push_back(nums[idx]);
				idx=pre[idx];
			}
			return res;
		}
};
