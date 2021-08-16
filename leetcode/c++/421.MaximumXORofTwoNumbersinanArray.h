/*
   Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.



   Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Example 2:

Input: nums = [0]
Output: 0

Example 3:

Input: nums = [2,4]
Output: 6

Example 4:

Input: nums = [8,10,2]
Output: 10

Example 5:

Input: nums = 9
Output: 127



Constraints:

1 <= nums.length <= 2*10^5 
0 <= nums[i] <= 231 - 1

*/
#define c11
#include"head.h"
class Solution {
	public:
		int findMaximumXOR(vector<int>& nums) {
			return bitOperation(nums);
			return origin(nums);
		}
		int origin(vector<int>& nums) {
			int res=0,n=nums.size();
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					res=max(res,nums[i]^nums[j]);
			return res;
		}
		int bitOperation(vector<int>& nums) {
			unordered_set<int> s;
			int mask=0,res=0,n=nums.size();
			for(int i=30;i>=0;i--)
			{
				mask|=1<<i;
				for(int j=0;j<n;j++)
					s.insert(nums[j]&mask);	
				int newmask=res|(1<<i);
				for(unordered_set<int>::iterator it=s.begin();it!=s.end();it++)
					if(s.count(newmask^*it))
					{
						res=newmask;
						break;
					}
				s.clear();
			}
			return res;
		}
};
