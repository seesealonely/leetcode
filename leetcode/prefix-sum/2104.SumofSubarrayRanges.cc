/*
   You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

   Return the sum of all subarray ranges of nums.

   A subarray is a contiguous non-empty sequence of elements within an array.



   Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.

Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.



Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109



Follow-up: Could you find a solution with O(n) time complexity?

*/
#include"head.h"
class Solution {
	public:
		long long subArrayRanges(vector<int>& nums) {
		const int n=nums.size();
		long long int res=0;
		for(int i=0;i<n;i++)
		{
			int mx=nums[i],mn=nums[i];
			for(int j=i+1;j<n;j++)
			{
				mx=max(mx,nums[j]);
				mn=min(mn,nums[j]);
				res+=mx-mn;
			}
		}
		return res;
		}
};
int main() 
{
	Solution s;
	vector<int> v={1,2,3};
	cout<<s.subArrayRanges(v)<<endl;
	v.clear();v={1,3,3};
	cout<<s.subArrayRanges(v)<<endl;
	v.clear();v={4,-2,-3,4,1};
	cout<<s.subArrayRanges(v)<<endl;
	return 0;
}
