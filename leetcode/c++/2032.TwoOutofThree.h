/*
   Given three integer arrays nums1, nums2, and nums3, return a distinct array containing all the values that are present in at least two out of the three arrays. You may return the values in any order.



   Example 1:

Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
Output: [3,2]
Explanation: The values that are present in at least two arrays are:
- 3, in all three arrays.
- 2, in nums1 and nums2.

Example 2:

Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
Output: [2,3,1]
Explanation: The values that are present in at least two arrays are:
- 2, in nums2 and nums3.
- 3, in nums1 and nums2.
- 1, in nums1 and nums3.

Example 3:

Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
Output: []
Explanation: No value is present in at least two arrays.



Constraints:

1 <= nums1.length, nums2.length, nums3.length <= 100
1 <= nums1[i], nums2[j], nums3[k] <= 100
*/
#define c11
#include"head.h"
class Solution {
	public:
		vector<int> twoOutOfThree(const vector<int>& nums1,const vector<int>& nums2,const vector<int>& nums3) {
		vector<int> res;
		unordered_map<int,int> fre;

		delDup(nums1,fre);
		delDup(nums2,fre);
		delDup(nums3,fre);

		for(unordered_map<int,int>::iterator it=fre.begin();it!=fre.end();it++)
			if(it->second>=2)
				res.push_back(it->first);
		return res;
		}
		void delDup(const vector<int> &nums,unordered_map<int,int> &f)
		{
			vector<int> res;
			vector<int> cur(101,0);
			for(int i=0;i<nums.size();i++)
				if(cur[nums[i]]==0)
					cur[nums[i]]++;
			for(int i=1;i<=100;i++)
				if(cur[i])
				f[i]++;
			return ;	
		}
};
