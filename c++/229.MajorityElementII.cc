/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]

Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]

*/

#include"229.MajorityElementII.h"

int main()
{
	int e1[]={3,2,3};
	int e2[]={1,1,1,3,3,2,2,2};
	vector<int> v1(e1,e1+3),v2(e2,e2+8);
	Solution s;
	show(s.majorityElement(v1));
	show(s.majorityElement(v2));
	v2.clear();
	show(s.majorityElement(v2));
	return 0;
}
