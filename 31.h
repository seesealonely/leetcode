#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
	public:
		void nextPermutation(vector<int>& nums) {
			int begin=-1,end;
			for(int i=nums.size()-2;i>=0;i--)
			{
				if(nums[i]<nums[i+1])
				{
					begin=i;
					break;
				}
			}       
			if(begin==-1)
			{
				reverse(nums.begin(),nums.end());	
				return ;
			}
			for(int i=nums.size()-1;i>begin;i--)
			{
				if(nums[i]>nums[begin])
				{
					end=i;
					break;
				}
			}
			swap(nums[begin],nums[end]);
			reverse(nums.begin()+begin+1,nums.end());
		}
};
