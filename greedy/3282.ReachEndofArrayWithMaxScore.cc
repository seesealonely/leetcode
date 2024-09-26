/*
   You are given an integer array nums of length n.

   Your goal is to start at index 0 and reach index n - 1. You can only jump to indices greater than your current index.

   The score for a jump from index i to index j is calculated as (j - i) * nums[i].

   Return the maximum possible total score by the time you reach the last index.



   Example 1:

Input: nums = [1,3,1,5]

Output: 7

Explanation:

First, jump to index 1 and then jump to the last index. The final score is 1 * 1 + 2 * 3 = 7.

Example 2:

Input: nums = [4,3,1,3,2]

Output: 16

Explanation:

Jump directly to the last index. The final score is 4 * 4 = 16.



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105


*/


#include"head.h"
class Solution {
	public:
		long long findMaximumScore(vector<int>& nums) {
		const int n=nums.size();
		int p=0;
		long long res=0LL;
		for(int i=1;i<n;i++)
			if(nums[i]>nums[p])
			{
				res+=(long long)(i-p)*nums[p];
				p=i;
			}
		res+=(long long)(n-1-p)*nums[p];
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={1,3,1,5};
	cout<<s.findMaximumScore(nums)<<endl;
	nums.clear();nums={4,3,1,3,2};
	cout<<s.findMaximumScore(nums)<<endl;
	return 0;
}
