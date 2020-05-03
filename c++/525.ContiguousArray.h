/*
   Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

   Example 1:

Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:

Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000. 
*/

#include"head.h"

int bruteForce(vector<int> &nums)
{
	int res=0;
	for(int i=0;i<nums.size();i++)
	{
		int one=0,zero=0;
		for(int j=i;j<nums.size();j++)
		{
			if(nums[j]) one++;
			else zero++;
			if(one==zero)
				res=max(res,j-i+1);
		}
	}
	return res;
}
int hashFind(vector<int> & nums)
{
	map<int,int> m;
	m[0]=-1;
	int count=0,res=0;
	for(int i=0;i<nums.size();i++)
	{
		count+=(nums[i]==0?-1:1);	
		if(m.count(count))
		{
			res=max(res,i-m[count]);	
		}
		else
			m[count]=i;
	}
	return res;
}
class Solution {
	public:
		int findMaxLength(vector<int>& nums) {
//			return bruteForce(nums);
	return hashFind(nums);
		}
};
