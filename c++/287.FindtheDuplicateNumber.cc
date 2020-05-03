/*
 Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:

    You must not modify the array (assume the array is read only).
    You must use only constant, O(1) extra space.
    Your runtime complexity should be less than O(n2).
    There is only one duplicate number in the array, but it could be repeated more than once.
*/

#include"287.FindtheDuplicateNumber.h"

int main()
{
	int vv[]={1,2,3,4,5,6,7,8,6,9};
	vector<int> v(vv,vv+10);
	Solution s;	
	cout<<s.findDuplicate(v)<<endl;
	return 0;
}
