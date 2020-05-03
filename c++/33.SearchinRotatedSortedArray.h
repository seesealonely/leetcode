/*
   Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

   (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

   You are given a target value to search. If found in the array return its index, otherwise return -1.

   You may assume no duplicate exists in the array.
   */

#include"head.h"

class Solution {
	public:
		int search(vector<int>& nums, int target) {
			if(nums.empty()) return -1;
			int begin=0,end=nums.size()-1,mid=(begin+end)>>1;
			while(begin<=end)
			{
				mid=(begin+end)>>1;
				if(nums[mid]==target) return mid;
				if(nums[begin]<=nums[mid])
				{
					if(target<nums[mid]&&target>=nums[begin])
						end=mid-1;
					else
						begin=mid+1;
				}
				if(nums[mid]<=nums[end])
				{
					if(target>nums[mid]&&target<=nums[end])
						begin=mid+1;
					else 
						end=mid-1;
				}
			}       
			return -1;
		}
};
