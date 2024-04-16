/*
   You are given an integer array nums.

   Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.



   Example 1:

Input: nums = [4,2,9,5,3]

Output: 3

Explanation: nums[1], nums[3], and nums[4] are prime. So the answer is |4 - 1| = 3.

Example 2:

Input: nums = [4,8,2,8]

Output: 0

Explanation: nums[2] is prime. Because there is just one prime number, the answer is |2 - 2| = 0.



Constraints:

1 <= nums.length <= 3 * 105
1 <= nums[i] <= 100
The input is generated such that the number of prime numbers in the nums is at least one.

*/


#include"head.h"
class Solution {
	public:
		int maximumPrimeDifference(vector<int>& nums) {
		int i=0;
		while(!check(nums[i]))
			i++;
		int j=nums.size()-1;
		while(!check(nums[j]))
			j--;
		return j-i;
		}
		bool check(int x)
		{
			for(int i=2;i*i<=x;i++)
				if(x%i==0)
					return false;
			return x>=2;
		}
};


int main() 
{
	Solution s;
	vector<int> nums = {4,2,9,5,3};
	cout<<s.maximumPrimeDifference(nums)<<endl;
	nums.clear();nums={4,8,2,8};
	cout<<s.maximumPrimeDifference(nums)<<endl;
	return 0;
}
