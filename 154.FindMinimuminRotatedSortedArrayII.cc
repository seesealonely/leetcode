/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

#include"154.FindMinimuminRotatedSortedArrayII.h"

int main()
{
	int vv[]={4,5,6,7,0,1,2};
	vector<int> v(vv,vv+7);
	Solution s;
	cout<<s.findMin(v)<<endl;
	int vv1[]={4,5,6,7,0,1,2,2,2,3,3};
	vector<int> v1(vv1,vv1+11);
	cout<<s.findMin(v1)<<endl;
	int vv2[]={4,5,6,7,7,7,7,7,7,7,0,1,2};
	vector<int> v2(vv2,vv2+13);
	cout<<s.findMin(v2)<<endl;
	int vv3[]={10,1,10,10,10};
	vector<int> v3(vv3,vv3+5);
	cout<<s.findMin(v3)<<endl;
	return 0;
}
