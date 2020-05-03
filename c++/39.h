#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
	public:
		vector<vector<int> > combinationSum(vector<int>& candidates, int target) 
		{
			vector<vector<int> > res;
			vector<int>  one;
			sort(candidates.begin(),candidates.end());
			dfs(res,one,candidates,target,0);
			return res;
		}
	private:
		void		dfs(vector<vector<int> > &res,vector<int> &one,vector<int> &candidates,int sum,int begin)
		{
			if(!sum)
			{
				res.push_back(one);
				return; 
			}
			for(int i=begin;sum>=candidates[i]&&i<candidates.size();i++)
			{
				one.push_back(candidates[i]);
				dfs(res,one,candidates,sum-candidates[i],i);
				one.pop_back();	
			}
		}
};
