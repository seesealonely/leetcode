/*
   You are given an array nums of non-negative integers and an integer k.

   An array is called special if the bitwise OR of all of its elements is at least k.

   Return the length of the shortest special non-empty
   subarray
   of nums, or return -1 if no special subarray exists.



   Example 1:

Input: nums = [1,2,3], k = 2

Output: 1

Explanation:

The subarray [3] has OR value of 3. Hence, we return 1.

Example 2:

Input: nums = [2,1,8], k = 10

Output: 3

Explanation:

The subarray [2,1,8] has OR value of 11. Hence, we return 3.

Example 3:

Input: nums = [1,2], k = 0

Output: 1

Explanation:

The subarray [1] has OR value of 1. Hence, we return 1.



Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 109
0 <= k <= 109

*/


#include"head.h"
class Solution {
	public:
		int minimumSubarrayLength(vector<int>& nums, int k) {
			const int n=nums.size();
			vector<int> cnt(32,0);
			int sum=0,res=INT_MAX;
			for(int l=0,r=0;r<n;r++)
			{
				in(nums[r],cnt,sum);
				while(l<=r&&sum>=k)
				{
					res=min(res,r-l+1);
					out(nums[l++],cnt,sum);
				}
			}
			return res==INT_MAX?-1:res;
		}
		void in(int x,vector<int>&cnt,int &sum)
		{
			sum|=x;
			for(int i=0;i<31;i++)
				if((x>>i)&1)
					++cnt[i];
		}
		void out(int x,vector<int>&cnt,int &sum)
		{
			for(int i=0;i<31;i++)
			{	
				if(!((x>>i)&1))
					continue;
				if(--cnt[i]==0)
					sum^=1<<i;
			}
		}
};


int main() 
{
	Solution s;
	vector<int> nums={1,2,3};
	cout<<s.minimumSubarrayLength(nums,2)<<endl;
	nums.clear();nums={2,1,8};		
	cout<<s.minimumSubarrayLength(nums,10)<<endl;
	nums.clear();nums={1,2};		
	cout<<s.minimumSubarrayLength(nums,0)<<endl;
	return 0;
}
