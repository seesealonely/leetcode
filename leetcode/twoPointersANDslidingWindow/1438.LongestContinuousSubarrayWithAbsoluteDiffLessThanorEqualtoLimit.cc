/*
   Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.



   Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2
Explanation: All subarrays are:
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4.
Therefore, the size of the longest subarray is 2.

Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= limit <= 109

*/
#include"head.h"
class Solution {
	public:
		int longestSubarray(vector<int>& nums, int limit) {
		map<int,int> count;
		int l=0,r=0,res=0;
		while(r<nums.size())
		{
			count[nums[r]]++;
			while(count.rbegin()->first-count.begin()->first>limit)
			{
				count[nums[l]]--;
				if(count[nums[l]]==0)
					count.erase(nums[l]);
				l++;
			}
			res=max(res,r-l+1);
			r++;
		}
		return res;
		}
};
int main() 
{
	Solution s;
	vector<int> v={8,2,4,7};
	cout<<s.longestSubarray(v,4)<<endl;
	v.clear();v={10,1,2,4,7,2};
	cout<<s.longestSubarray(v,5)<<endl;
	v.clear();v={4,2,2,2,4,4,2,2};
	cout<<s.longestSubarray(v,0)<<endl;
	return 0;
}
