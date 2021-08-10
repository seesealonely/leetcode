/*
   Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

   Return the sorted array.



   Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]



Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100

*/
#define c11
#include"head.h"
class Solution {
	public:
		vector<int> frequencySort(vector<int>& nums) {
		int n=nums.size();
		unordered_map<int,int> freq;
		vector<pair<int,int> > p;
		for(int i=0;i<n;i++)
			freq[nums[i]]++;
		for(unordered_map<int,int>::iterator it=freq.begin();it!=freq.end();it++)
			p.push_back(make_pair(it->first,it->second));
		sort(p.begin(),p.end(),cmp);
		vector<int> res;
		for(int i=0;i<p.size();i++)
			while(p[i].second--)
			res.push_back(p[i].first);
		return res;
		}
		static bool cmp(pair<int,int> &a,pair<int,int> &b)
		{
			if(a.second<b.second)
				return true;
			if(a.second==b.second&&a.first>b.first)
				return true;
			return false;
		}
};
