/*
   You are given an array of integers nums of size 3.

   Return the maximum possible number whose binary representation can be formed by concatenating the binary representation of all elements in nums in some order.

   Note that the binary representation of any number does not contain leading zeros.



   Example 1:

Input: nums = [1,2,3]

Output: 30

Explanation:

Concatenate the numbers in the order [3, 1, 2] to get the result "11110", which is the binary representation of 30.

Example 2:

Input: nums = [2,8,16]

Output: 1296

Explanation:

Concatenate the numbers in the order [2, 8, 16] to get the result "10100010000", which is the binary representation of 1296.



Constraints:

nums.length == 3
1 <= nums[i] <= 127

*/


#include"head.h"
#include<ranges>
class Solution {
	public:
		int maxGoodNumber(vector<int>& nums) {
		ranges::sort(nums,[](int x,int y)
		{
			int lx=__lg(x)+1;
			int ly=__lg(y)+1;
			return (x<<ly|y)>(y<<lx|x);
		});
		int res=0;
		for(int x:nums)
		res=(res<<__lg(x)+1)|x;
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={1,2,3};
	cout<<s.maxGoodNumber(nums)<<endl;
	nums.clear();nums={2,8,16};
	cout<<s.maxGoodNumber(nums)<<endl;
	return 0;
}
