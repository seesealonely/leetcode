/*
   Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors.

   If there is no such integer in the array, return 0.



   Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.

*/
#include"head.h"
class Solution {
	public:
		int sumFourDivisors(vector<int>& nums) {
			int res=0,count=0,factor=0,sum=0;
			for(int i=0;i<nums.size();i++,count=0,sum=0)
			{
				for(int j=1;j*j<=nums[i];j++)
				{
					if(nums[i]%j==0)
					{
						sum+=j,count++;
						if(j*j!=nums[i])
							sum+=nums[i]/j,count++;
					}						
					if(count>4) break;
				}
				if(count==4)
					res+=sum;
			}
			return res;
		}
};
