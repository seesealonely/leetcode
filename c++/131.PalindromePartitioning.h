/*
   Given a string s, partition s such that every substring of the partition is a palindrome.

   Return all possible palindrome partitioning of s.

   For example, given s = "aab",
   Return

   [
   ["aa","b"],
   ["a","a","b"]
   ]
   */

#include"head.h"

class Solution {
	public:
		void show(vector<vector<string> > &res)
		{
			for(int i=0;i<res.size();++i)
			{
				for(int j=0;j<res[i].size();++j)
					cout<<res[i][j]<<" ";
				cout<<endl;
			}
		}
		vector<vector<string> > partition(string s) {
			vector<vector<string> > res;
			vector<string>  tmp;
			dfs(s,0,tmp,res);
			return res;
		}
	private:
		void dfs(string &s,int idx,vector<string> &tmp,vector<vector<string> >&res)
		{
			if(idx==s.size())
			{
				res.push_back(tmp);
				return ;
			}
			for(int i=idx,n=s.size();i<n;++i)
			{
				int left=idx,right=i;
				while(left<right&&s[left]==s[right]) left++,right--;
				if(left>=right)
				{
					tmp.push_back(s.substr(idx,i-idx+1));
					dfs(s,i+1,tmp,res);
					tmp.pop_back();
				}
			}
		}
};
