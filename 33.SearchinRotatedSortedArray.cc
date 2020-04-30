/*
   Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

   (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

   You are given a target value to search. If found in the array return its index, otherwise return -1.

   You may assume no duplicate exists in the array.
   */

#include"33.SearchinRotatedSortedArray.h"

int main()
{
	int vv[]={4,5,6,7,0,1,2};
	vector<int> v(vv,vv+7);
	Solution s;
	cout<<s.search(v,1)<<endl;
	cout<<s.search(v,3)<<endl;
	cout<<s.search(v,6)<<endl;
	return 0;
}
