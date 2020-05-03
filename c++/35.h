#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		int searchInsert(vector<int>& nums, int target) {
			int end=nums.size()-1;
			int begin=0;
			int  index;
			while(begin<=end)
			{
				index=(begin+end)/2;
				if(nums[index]>target)
					end=index-1;
				else if(nums[index]<target)
					begin=index+1;	
				else return index;
			}
			if(nums[index]>target) return index;
			else
			return index+1;
		}
};
