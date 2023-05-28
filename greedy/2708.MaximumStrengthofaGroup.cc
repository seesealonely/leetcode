/*
   You are given a 0-indexed integer array nums representing the score of students in an exam. The teacher would like to form one non-empty group of students with maximal strength, where the strength of a group of students of indices i0, i1, i2, ... , ik is defined as nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​].

   Return the maximum strength of a group the teacher can create.



   Example 1:

Input: nums = [3,-1,-5,2,5,-9]
Output: 1350
Explanation: One way to form a group of maximal strength is to group the students at indices [0,2,3,4,5]. Their strength is 3 * (-5) * 2 * 5 * (-9) = 1350, which we can show is optimal.

Example 2:

Input: nums = [-4,-5,-4]
Output: 20
Explanation: Group the students at indices [0, 1] . Then, we’ll have a resulting strength of 20. We cannot achieve greater strength.



Constraints:

1 <= nums.length <= 13
-9 <= nums[i] <= 9

*/


#include"head.h"
class Solution {
	public:
		long long maxStrength(vector<int>& nums) {
		long long mx=nums[0],mn=nums[0];

		for(int i=1;i<nums.size();i++)
		{
			long long tmp=mx;
			mx=max(max(mx*nums[i],mn*nums[i]),max((long long)nums[i],mx));
			mn=min(min(tmp*nums[i],mn*nums[i]),min((long long)nums[i],mn));
		}
		return max((long long)nums[0],mx);
		}
};


int main() 
{
	Solution s;
	vector<int>  nums = {3,-1,-5,2,5,-9};
	cout<<s.maxStrength(nums)<<endl;
	nums.clear();nums={-4,-5,-4};
	cout<<s.maxStrength(nums)<<endl;
	return 0;
}
