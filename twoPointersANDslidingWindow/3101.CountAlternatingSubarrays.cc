/*
   You are given a
   binary array
   nums.

   We call a
   subarray
   alternating if no two adjacent elements in the subarray have the same value.

   Return the number of alternating subarrays in nums.



   Example 1:

Input: nums = [0,1,1,1]

Output: 5

Explanation:

The following subarrays are alternating: [0], [1], [1], [1], and [0,1].

Example 2:

Input: nums = [1,0,1,0]

Output: 10

Explanation:

Every subarray of the array is alternating. There are 10 possible subarrays that we can choose.



Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

*/


#include"head.h"
class Solution {
	public:
		long long countAlternatingSubarrays(vector<int>& nums) {
		const int n=nums.size();
		long long res=1;
		for(int l=0,r=1;r<n;r++)
		{
			if(nums[r]==nums[r-1])
				l=r;
			res+=r-l+1;
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={0,1,1,1};
	cout<<s.countAlternatingSubarrays(nums)<<endl;
	nums.clear();nums={1,0,1,0};
	cout<<s.countAlternatingSubarrays(nums)<<endl;
	return 0;
}
