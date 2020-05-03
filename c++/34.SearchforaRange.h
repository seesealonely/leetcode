/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
*/

#include"head.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
	int begin=0,end=nums.size()-1,mid;
	vector<int> res(2,-1);
	while(begin<end)
	{
		mid=(begin+end)>>1;
		if(nums[mid]<target) begin=mid+1;
		else end=mid;
	}	
	if(nums[begin]!=target) return res;
	else res[0]=begin;
	end=nums.size()-1;
	while(begin<end)
	{
		mid=((begin+end)>>1)+1;
		if(nums[mid]>target) end=mid-1;
		else begin=mid;
	}
	res[1]=end;
	return res;
    }
};
