/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

#include"153.FindMinimuminRotatedSortedArray.h"

int main()
{
	int vv[]={4,5,6,7,0,1,2};
	vector<int> v(vv,vv+7);
	Solution s;
	cout<<s.findMin(v)<<endl;
	return 0;
}
