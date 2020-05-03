/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

Note:

    The array is only modifiable by the update function.
    You may assume the number of calls to update and sumRange function is distributed evenly.

*/

#include"307.RangeSumQuery-Mutable.h"

int main()
{
	int vv[]={1, 3, 5};
	vector<int> v(vv,vv+3);
	NumArray  n(v);
	cout<<n.sumRange(0,2)<<endl;
	n.update(1,2);	
	cout<<n.sumRange(0,2)<<endl;
	return 0;
}
