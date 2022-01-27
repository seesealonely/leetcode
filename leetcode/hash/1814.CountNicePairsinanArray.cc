/*
   You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

   0 <= i < j < nums.length
   nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])

   Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.



   Example 1:

Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
- (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
- (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.

Example 2:

Input: nums = [13,10,35,24,76]
Output: 4



Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109

*/
#define c11
#include"head.h"
class Solution {
	public:
		int countNicePairs(vector<int>& nums) {
			unordered_map<int,int> count;
			for(int i=0;i<nums.size();i++)
				count[nums[i]-rev(nums[i])]++;	

			int res=0;
			const int mod=1e9+7;
			for(unordered_map<int,int>::iterator it=count.begin();it!=count.end();it++)
				if(it->second>1)
					res=(res+(long) it->second*(it->second-1)/2)%mod;

			return res;
		}
		int rev(int cur)
		{
			int res=0;
			while(cur)
			{
				int d=cur%10;
				res=res*10+d;
				cur/=10;
			}
			return res;
		}
};
int main() 
{
	Solution s;
	vector<int> v={42,11,1,97};
	cout<<s.countNicePairs(v)<<endl;
	v.clear();v={13,10,35,24,76};
	cout<<s.countNicePairs(v)<<endl;
	return 0;
}
