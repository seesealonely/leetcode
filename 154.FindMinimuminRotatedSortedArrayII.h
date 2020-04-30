/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

#include"head.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
 	int begin=0,end=nums.size()-1,mid;
	while(begin<end)
	{
		mid=begin+((end-begin)>>1);
		if(nums[mid]<nums[end]) end=mid;
		else if(nums[mid]>nums[end]) begin=mid+1;
		else end--;
	}       
	return nums[begin];
    }
};
