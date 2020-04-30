/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:

    You may assume that the array does not change.
    There are many calls to sumRange function.

*/

#include"head.h"

class NumArray {
public:
    NumArray(vector<int> nums) {
       res.push_back(0); 
	for(int i=0;i<nums.size();++i)
	{
		res.push_back(res[res.size()-1]+nums[i]);
	}
    }
    
    int sumRange(int i, int j) {
       return res[j+1]-res[i]; 
  }
private:
	vector<int> res;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
