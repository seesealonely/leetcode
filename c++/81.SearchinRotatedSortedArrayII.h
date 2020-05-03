/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/

#include"head.h"

class Solution {
public:
    bool search(vector<int>& nums, int target) {
  if(nums.empty())return false;
 int low=0,high=nums.size()-1,mid=(low+high)>>1; 
	while(low<high)
	{
		mid=(low+high)>>1;
		if(nums[mid]==target) return true;
		if(nums[mid]>nums[high])
		{
			if(nums[mid]>target&&nums[low]<=target)
			high=mid;
			else
			low=mid+1;
		}
		else if(nums[mid]<nums[high])
		{
		if(nums[mid]<=target&&nums[high]>=target)
		low=mid+1;
		else 
		high=mid;
		}
		else
		high--;
	}
	return nums[low]==target?true:false;
    }
};
