/*
   You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:

   Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.

   Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.

   The gcd of two integers is the greatest common divisor of the two integers.



   Example 1:

Input: nums = [2,6,3,4]
Output: 4
Explanation: We can do the following operations:
- Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
- Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
- Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
- Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].

Example 2:

Input: nums = [2,10,6,14]
Output: -1
Explanation: It can be shown that it is impossible to make all the elements equal to 1.



Constraints:

2 <= nums.length <= 50
1 <= nums[i] <= 106

*/


#include"head.h"
class Solution {
	public:
		int minOperations(vector<int>& nums) {
		int n=nums.size(),ones=0,gcd=nums[0];
		for(int i=0;i<n;i++)
		{
			ones+=nums[i]==1;
			if(i>0)
			gcd=__gcd(gcd,nums[i]);
		}

		if(ones>1)
			return n-ones;

		if(gcd>1)
			return -1;

		int res=INT_MAX;
		for(int i=0;i<n;i++)
		{
			gcd=nums[i];
			int idx=-1;
			for(int j=i;j<n;j++)
			{
				gcd=__gcd(nums[j],gcd);
				if(gcd==1)
				{
					idx=j;
					break;
				}
			}

			if(idx==-1)
				continue;
			res=min(res,idx-i+n-1);
		}

		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> v={2,6,3,4};
	cout<<s.minOperations(v)<<endl;
	v.clear();v={2,10,6,14};
	cout<<s.minOperations(v)<<endl;
	return 0;
}
