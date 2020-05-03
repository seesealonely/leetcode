#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
	public:
		vector<vector<int> > permuteUnique(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			vector<vector<int> >res;
			dfs(nums,0,nums.size(),res);       
			return res;
		}
		void show(vector<vector<int> > &res)
		{
			for(int i=0;i<res.size();++i)
			{
				for(int j=0;j<res[i].size();++j)
					cout<<res[i][j]<<" ";
				cout<<endl;
			}
		}
	private:
		void dfs(vector<int> nums,int begin,int end,vector<vector<int>  >&res)
		{
			if(begin==end-1)
				res.push_back(nums);
			for(int i=begin;i<end;i++)
			{
				if(begin!=i&nums[begin]==nums[i])continue;
				swap(nums[begin],nums[i]);
				dfs(nums,begin+1,end,res);	
			}
		}
};
