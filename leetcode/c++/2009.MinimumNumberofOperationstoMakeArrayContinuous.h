/*
   You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

   nums is considered continuous if both of the following conditions are fulfilled:

   All elements in nums are unique.
   The difference between the maximum element and the minimum element in nums equals nums.length - 1.

   For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

   Return the minimum number of operations to make nums continuous.



   Example 1:

Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.

Example 2:

Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.

Example 3:

Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109

*/
#define c11
#include"head.h"
class Solution {
	public:
		int minOperations(vector<int>& nums) {
			int n=nums.size(),cur=0,res=INT_MAX;
			sort(nums.begin(),nums.end());
			unordered_map<int,int> h;
			for(int i=0,j=0;i<n;i++)
			{
				while(j<n&&nums[j]-nums[i]<n)
					if(h[nums[j++]]++==0) 
						++cur;
				res=min(res,n-cur);
				if(h[nums[i]]--==1)
					--cur;
			}
			return res;
		}
};
