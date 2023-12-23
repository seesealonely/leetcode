/*
   You are given an integer array nums and a positive integer k.

   Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

   A subarray is a contiguous sequence of elements within an array.



   Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105

*/


#include"head.h"
class Solution {
	public:
		long long countSubarrays(vector<int>& nums, int k) {
		int mx=*max_element(nums.begin(),nums.end());
		long long res=0;
		int cnt=0;
		for(int l=0,r=0;r<nums.size();r++)
		{
			cnt+=nums[r]==mx;
			while(cnt==k)
				cnt-=nums[l++]==mx;
			res+=l;
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums = {1,3,2,3,3};
	cout<<s.countSubarrays(nums,2)<<endl;
	nums.clear();nums={1,4,2,1};
	cout<<s.countSubarrays(nums,3)<<endl;
	return 0;
}
