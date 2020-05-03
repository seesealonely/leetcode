/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

#include"head.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
	int begin=0,end=nums.size()-1,mid=(begin+end);
	while(begin<=end)
	{
		if(nums[begin]<nums[end])
		return nums[begin];
		mid=(begin+end)>>1;
		if(nums[mid]>nums[begin])
		begin=mid+1;
		else
		end=mid;
	}        
	return nums[begin];
    }
};
