/*
 Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:

Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

Note:

    The length of the given array will not exceed 15.
    The range of integer in the given array is [-100,100].
    The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.

*/

#include"head.h"

void dfs(vector<int> &nums,int begin,vector<int> &subseq,set<vector<int> > &res)
{
	if(subseq.size()>=2) res.insert(subseq);
	for(int  i=begin;i<nums.size();i++)	
	if(subseq.empty()||nums[i]>=subseq.back())
	{
		subseq.push_back(nums[i]);
		dfs(nums,i+1,subseq,res);
		subseq.pop_back();
	}
}
class Solution {
public:
    vector<vector<int> > findSubsequences(vector<int>& nums) {
       vector<int> subseq;
       set<vector<int> > res;
	dfs(nums,0,subseq,res); 
	return vector<vector<int> >(res.begin(),res.end());
    }
};
