/*
   Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.



   Example 1:

Input: nums1 = [4,1,3], nums2 = [5,7]
Output: 15
Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.

Example 2:

Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
Output: 3
Explanation: The number 3 contains the digit 3 which exists in both arrays.



Constraints:

1 <= nums1.length, nums2.length <= 9
1 <= nums1[i], nums2[i] <= 9
All digits in each array are unique.
*/


#include"head.h"
class Solution {
	public:
		int minNumber(vector<int>& nums1, vector<int>& nums2) {
		vector<int> cnt(10,0);
		for(int i=0;i<nums1.size();i++)
			cnt[nums1[i]]++;

		sort(nums2.begin(),nums2.end());
		for(int i=0;i<nums2.size();i++)
			if(cnt[nums2[i]])
				return nums2[i];

		sort(nums1.begin(),nums1.end());

		return nums1[0]<nums2[0]?nums1[0]*10+nums2[0]:nums2[0]*10+nums2[0];
		}
};


int main() 
{
	Solution s;
	vector<int> v1={4,1,3},v2={5,7};
	cout<<s.minNumber(v1,v2)<<endl;
	v1.clear();v1={3,5,2,6};
	v2.clear();v2={3,1,7};
	cout<<s.minNumber(v1,v2)<<endl;
	return 0;
}
