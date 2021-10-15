/*
   You are given an integer array nums and an integer goal.

   You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).

   Return the minimum possible value of abs(sum - goal).

   Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.



   Example 1:

Input: nums = [5,-7,3,5], goal = 6
Output: 0
Explanation: Choose the whole array as a subsequence, with a sum of 6.
This is equal to the goal, so the absolute difference is 0.

Example 2:

Input: nums = [7,-9,15,-2], goal = -5
Output: 1
Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.

Example 3:

Input: nums = [1,2,3], goal = -7
Output: 7



Constraints:

1 <= nums.length <= 40
-107 <= nums[i] <= 107
-109 <= goal <= 109

*/
#include"head.h"
class Solution {
	public:
		int minAbsDifference(vector<int>& nums, int goal) {
			int n=nums.size()/2,ll=n,rl=nums.size()-n,res=INT_MAX;
			vector<int> l(1<<ll,0),r(1<<rl,0),ln(nums.begin(),nums.begin()+n),rn(nums.begin()+n,nums.end());
			addSum(l,ln,n);
			addSum(r,rn,rl);
			sort(l.begin(),l.end());
			sort(r.begin(),r.end());
			for(int i=0;i<l.size();i++)
				res=min(res,abs(l[i]-goal));

			for(int i=0;i<r.size();i++)
				res=min(res,abs(r[i]-goal));

			for(int i=0,j=r.size()-1;i<l.size()&&j>=0;)
			{
				int s=l[i]+r[j];
				res=min(res,abs(s-goal));
				if(s>goal)
					j--;
				else
					i++;
			}
			return res;
		}
		void addSum(vector<int> &s,vector<int> &num,int n)
		{
			for(int i=1;i<(1<<n);i++)
				for(int j=0;j<n;j++)
				{
					if((i&(1<<j))==0)
						continue;
					s[i]=s[i-(1<<j)]+num[j];
					break;
				}
		}
};
