#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
	public:
		vector<vector<int> > permute(vector<int>& nums) {
			vector<vector <int> > res;
			vector<int> one;
			dfs(nums,res,0);
			return res;
		}
	private:
		void dfs(vector<int> &nums,vector<vector<int> > &res,int begin)
		{
			if(begin==nums.size())
			{
				res.push_back(nums);
				return;
			}
			for(int i=begin;i<nums.size();i++)
			{
				swap(nums[begin],nums[i]);
				dfs(nums,res,begin+1);
				swap(nums[begin],nums[i]);
			}
		}
};
