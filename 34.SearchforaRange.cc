/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
*/

#include"34.SearchforaRange.h"

int main()
{
	int vv[]={2,2,2,2,2,2,2,2,2};
	vector<int> v(vv,vv+9);
	Solution s;
	show(s.searchRange(v,2));
	return 0;
}
