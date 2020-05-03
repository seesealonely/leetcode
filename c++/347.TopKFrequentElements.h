/*
   Given a non-empty array of integers, return the k most frequent elements.

   For example,
   Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/
#define c11
#include"head.h"
class Solution {
	public:
		vector<int> topKFrequent(vector<int>& nums, int k) {
			unordered_map<int,int> h;
			vector<vector<int> > bucket(nums.size()+1);
			vector<int> res;
			for(int i=0;i<nums.size();++i)
				h[nums[i]]++;       
			for(unordered_map<int,int>::iterator i=h.begin();i!=h.end();i++)
				bucket[i->second].push_back(i->first);
			for(int i=bucket.size();k>0&&i>=0;i--)
				if(bucket[i].size()>0)
				{ 
					for(int j=0;k>0&&j<bucket[i].size();++j)
					{
						res.push_back(bucket[i][j]);
						k--;
					}
				}
			return res;
		}
};
