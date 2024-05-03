/*
   You are given two arrays of equal length, nums1 and nums2.

   Each element in nums1 has been increased (or decreased in the case of negative) by an integer, represented by the variable x.

   As a result, nums1 becomes equal to nums2. Two arrays are considered equal when they contain the same integers with the same frequencies.

   Return the integer x.



   Example 1:

Input: nums1 = [2,6,4], nums2 = [9,7,5]

Output: 3

Explanation:

The integer added to each element of nums1 is 3.

Example 2:

Input: nums1 = [10], nums2 = [5]

Output: -5

Explanation:

The integer added to each element of nums1 is -5.

Example 3:

Input: nums1 = [1,1,1,1], nums2 = [1,1,1,1]

Output: 0

Explanation:

The integer added to each element of nums1 is 0.



Constraints:

1 <= nums1.length == nums2.length <= 100
0 <= nums1[i], nums2[i] <= 1000
The test cases are generated in a way that there is an integer x such that nums1 can become equal to nums2 by adding x to each element of nums1.

*/


#include"head.h"
class Solution {
	public:
		int addedInteger(vector<int>& nums1, vector<int>& nums2) {
		int mx1=-1,mx2=-1,n=nums1.size();
		for(int i=0;i<n;i++)
		{
			mx1=max(mx1,nums1[i]);
			mx2=max(mx2,nums2[i]);
		}
		return mx1-mx2;
		}
};


int main() 
{
	Solution s;
	vector<int> nums1 = {2,6,4}, nums2 = {9,7,5};
	cout<<s.addedInteger(nums1,nums2)<<endl;
	nums1.clear();nums2.clear();
	nums1={10};nums2={5};
	cout<<s.addedInteger(nums1,nums2)<<endl;
	nums1.clear();nums2.clear();
	nums1={1,1,1,1};
	nums2={1,1,1,1};
	cout<<s.addedInteger(nums1,nums2)<<endl;
	return 0;
}
