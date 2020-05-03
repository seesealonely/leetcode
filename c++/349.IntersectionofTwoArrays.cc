/*
 Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:

    Each element in the result must be unique.
    The result can be in any order.

*/

#include"349.IntersectionofTwoArrays.h"

int main()
{
	int vv1[]={1, 2, 2, 1};
	int vv2[]={2};
	vector<int> v1(vv1,vv1+4),v2(vv2,vv2+1);
	Solution s;
	show(s.intersection(v1,v2));
	return 0;
}
