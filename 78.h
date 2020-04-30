#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
   void recursive(vector<vector<int> >&res,vector<int> &one,vector<int> &nums,int begin)	
   {
   res.push_back(one);
   for(int i=begin;i<nums.size();i++)
   {
   one.push_back(nums[i]);
   recursive(res,one,nums,i+1);	
   one.pop_back();
   }
   }
   class Solution {
   public:
   vector<vector<int> > subsets(vector<int>& nums)
   {
   vector<vector<int> >res;
   vector<int> one;
   recursive(res,one,nums,0);
   return res;
   }
   };
   */
class Solution {
	public:
		vector<vector<int> > subsets(vector<int>& nums)
		{
			vector<vector<int> >res;
			vector<int> one;
			for(int i=0;i<nums.size();i++)
				for(int j=0;i<nums.size();j++)
				{
					res.push_back(one);
					res.back().push_back(nums[j]);
				}
			return res;
		}
};
