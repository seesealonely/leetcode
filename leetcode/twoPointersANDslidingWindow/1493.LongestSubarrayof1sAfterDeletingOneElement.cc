/*
   Given a binary array nums, you should delete one element from it.

   Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.



   Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.



Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

*/
#include"head.h"
class Solution {
	public:
		int longestSubarray(vector<int>& nums) {
			int n=nums.size();
			int l=0,r=0,sum=0,res=0;
			for(;r<n;r++)
			{
				sum+=nums[r];
				while(l<r&&sum<r-l)
					sum-=nums[l++];	
				res=max(res,r-l);
			}
			return res;
		}
};
int main() 
{
	Solution s;
	vector<int> v={1,1,0,1};
	cout<<s.longestSubarray(v)<<endl;
	v.clear();v={0,1,1,1,0,1,1,0,1};
	cout<<s.longestSubarray(v)<<endl;
	v.clear();v={1,1,1};
	cout<<s.longestSubarray(v)<<endl;
	return 0;
}
