/*
   You are given an integer array nums.

   You replace each element in nums with the sum of its digits.

   Return the minimum element in nums after all replacements.



   Example 1:

Input: nums = [10,12,13,14]

Output: 1

Explanation:

nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

Example 2:

Input: nums = [1,2,3,4]

Output: 1

Explanation:

nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

Example 3:

Input: nums = [999,19,199]

Output: 10

Explanation:

nums becomes [27, 10, 19] after all replacements, with minimum element 10.



Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 104

*/


#include"head.h"
class Solution {
	public:
		int minElement(vector<int>& nums) {
		int res=INT_MAX,n=nums.size();
		for(int i=0;i<n;i++)
		{
			int cur=0;
			while(nums[i])
			{
				cur+=nums[i]%10;
				nums[i]/=10;
			}
			res=min(res,cur);
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int>  nums = {10,12,13,14};
	cout<<s.minElement(nums)<<endl;
	nums.clear();nums={1,2,3,4};
	cout<<s.minElement(nums)<<endl;
	nums.clear();nums={999,19,199};
	cout<<s.minElement(nums)<<endl;
	return 0;
}
