/*
 Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:

    Each element in the result should appear as many times as it shows in both arrays.
    The result can be in any order.

Follow up:

    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

*/

#include"350.IntersectionofTwoArraysII.h"

int main()
{
	int vv1[]={4,7,9,7,6,7};
	int vv2[]={5,0,0,6,1,6,2,2,4};
	vector<int> v1(vv1,vv1+6),v2(vv2,vv2+9);
	Solution s;
	show(s.intersect(v1,v2));
	return 0;
}
