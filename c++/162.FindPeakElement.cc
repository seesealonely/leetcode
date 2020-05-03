/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

#include"162.FindPeakElement.h"

int main()
{
	int vv[]={1, 2, 3, 1};
	vector<int> v(vv,vv+4);
	Solution s;
	cout<<v[s.findPeakElement(v)]<<endl;
	int vv1[]={2, 1, 3, 1};
	vector<int> v1(vv1,vv1+4);
	cout<<v1[s.findPeakElement(v1)]<<endl;
	return 0;
}
