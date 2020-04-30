#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
	public:
		vector<vector<int> > subsetsWithDup(vector<int>& nums) 
		{
			sort(nums.begin(),nums.end());
			vector<vector<int> > res;
			vector<int> one;
			dfs(res,nums,one,0);	       
			return res;
		}
	private:
		void dfs(vector<vector<int> > &res,vector<int> &nums,vector<int> &one,int begin)
		{
			res.push_back(one);
			for(int i=begin;i<nums.size();i++)
			{
				if(i==begin||(i>0&&nums[i-1]!=nums[i]))
				{
					one.push_back(nums[i]);
					dfs(res,nums,one,i+1);
					one.pop_back();
				}
			}
		}
};
