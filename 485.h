#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		int findMaxConsecutiveOnes(vector<int>& nums) {
			int dp=0,res=0;
			for(int i=0;i<nums.size();i++)
				if(nums[i])   ++dp; 
				else
				{
					if(dp>res)res=dp;
					dp=0;
				}
			if(dp>res) res=dp;
			return res;
		}
};
