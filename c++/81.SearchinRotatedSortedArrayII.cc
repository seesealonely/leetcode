/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/
#include"81.SearchinRotatedSortedArrayII.h"
int main()
{
	int vv[]={4,5,6,7,0,1,2};
	vector<int> v(vv,vv+7);
	Solution s;
	cout<<s.search(v,4)<<endl;
	cout<<s.search(v,1)<<endl;
	cout<<s.search(v,3)<<endl;
	return 0;
}
