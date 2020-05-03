#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
	public:
		vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
			vector<int> one;       
			vector<vector<int> > res;
			sort(candidates.begin(),candidates.end());
			dfs(res,one,candidates,target,0);
			return res;
		}
	private:
		void dfs(vector<vector<int> > &res,vector<int> &one,vector<int> &candidates,int sum,int begin)
		{
			if(!sum)
			{
				res.push_back(one);
				return;
			}
			for(int i=begin;i<candidates.size()&&sum>=candidates[i];i++)
			{
				if(i>begin&&candidates[i]==candidates[i-1])
 continue;
				one.push_back(candidates[i]);
				dfs(res,one,candidates,sum-candidates[i],i+1);
				one.pop_back();
			}
		}
};
