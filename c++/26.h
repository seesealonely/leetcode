#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			int count=0;
			for(int i=1;i<nums.size();i++)
				nums[i-1]==nums[i]?count++:nums[i-count]=nums[i];
	return nums.size()-count;
			/*
			   nums.resize(nums.size()-count);
			   return nums.size();
			   */
		}
};
